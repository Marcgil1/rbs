#include "inferenceengine.hxx"

#include <algorithm>
#include <iostream>
#include <optional>
#include <limits>


InferenceEngine::InferenceEngine(FactBase fb, KnowledgeBase kb)
    : fb(fb), kb(kb) {}

float InferenceEngine::verify(Fact goal) {
  if (auto cert = fb.getCert(goal)) {
    return cert.value();
  }

  std::optional<float> cert;
  std::vector<Rule> conflictSet;
  kb.getConflictSet(conflictSet, goal);

  while (not conflictSet.empty()) {
    auto rule = solve(conflictSet);

    switch (rule.type) {
    case RuleType::SINGLETON:
      certaintyCombine(cert, certaintyChain(rule.cert, verify(rule.pre[0])));
      break;
    case RuleType::AND:
      certaintyCombine(cert, certaintyChain(rule.cert, certaintyAnd(rule.pre)));
      break;
    case RuleType::OR:
      certaintyCombine(cert, certaintyChain(rule.cert, certaintyOr(rule.pre)));
      break;
    }
    //std::cout << rule << " -- " << *cert << std::endl;
  }

  //std::cout << goal << " - " << cert.value() << std::endl;
  return fb.setCert(goal, cert.value_or(0.0f));
}

Rule InferenceEngine::solve(std::vector<Rule> &conflictSet) {
  auto res = conflictSet.back();
  conflictSet.pop_back();
  return res;
}

Fact InferenceEngine::selectGoal(std::vector<Fact> &goals) {
  auto res = goals.back();
  goals.pop_back();
  return res;
}

float InferenceEngine::certaintyAnd(std::vector<Fact> const &pre) {
  float res = std::numeric_limits<float>::max();
  for (auto f: pre)
    res = std::min(res, verify(f));
  return res;
}

float InferenceEngine::certaintyOr(std::vector<Fact> const &pre) {
  float res = std::numeric_limits<float>::min();
  for (auto f: pre)
    res = std::max(res, verify(f));
  return res;
}

float InferenceEngine::certaintyChain(float certRule, float cert) {
  return certRule * std::max(0.0f, cert);
}

void InferenceEngine::certaintyCombine(std::optional<float>& acc, float cert) {
  if (not acc.has_value()) {
    //std::cout << "certComb( nullopt, " << cert << ")" << std::endl;
    acc = cert;
  } else {
    float val = acc.value();
    //std::cout << "certComb( " << val << ", " << cert << ")";

    if (val >= 0 and cert >= 0) {
      acc = val + cert - val*cert;
    } else if (val <= 0 or cert <= 0) {
      acc = val + cert + val*cert;
    } else {
      acc = (val + cert) / (1 - std::min(std::abs(val), std::abs(cert)));
    }
    //std::cout << " = " << *acc << std::endl;
  }
}
