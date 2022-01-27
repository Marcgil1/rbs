#include "inferenceengine.hxx"

#include <algorithm>
#include <iostream>


InferenceEngine::InferenceEngine(FactBase fb, KnowledgeBase kb)
    : fb(fb), kb(kb) {}

bool InferenceEngine::verify(Fact goal, std::vector<Rule>& mem) {
  if (fb.containsFact(goal))
    return true;

  bool verified = false;
  std::vector<Rule> conflictSet;
  kb.getConflictSet(conflictSet, goal);
  while (not conflictSet.empty() and not verified) {
    auto rule = solve(conflictSet);
    auto newGoals = rule.pre;
    verified = true;
    while (not newGoals.empty() and verified) {
      auto newGoal = selectGoal(newGoals);
      verified = verify(newGoal, mem);
    }
    if (verified) {
      fb.addFact(goal);
      mem.push_back(rule);
    }
  }
  return verified;
}

Rule InferenceEngine::solve(std::vector<Rule> &conflictSet) {
  auto res = conflictSet[conflictSet.size() - 1];
  conflictSet.resize(conflictSet.size() - 1);
  return res;
}

Fact InferenceEngine::selectGoal(std::vector<Fact> &goals) {
  auto res = goals[goals.size() - 1];
  goals.resize(goals.size() - 1);
  return res;
}
