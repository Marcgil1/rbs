#pragma once

#include "defs.hxx"
#include "factbase.hxx"
#include "knowledgebase.hxx"

#include <optional>
#include <vector>
#include <ostream>


class InferenceEngine {
public:

  InferenceEngine(FactBase& fb, KnowledgeBase& kb, std::ostream& log);
  float verify(Fact goal);

private:
  FactBase&      fb;
  KnowledgeBase& kb;
  std::ostream&  log;
  size_t         callDepth;

  void printStackDepth();
  Rule solve(std::vector<Rule>& conflictSet);
  Fact selectGoal(std::vector<Fact>& goals);
  float certaintyAnd(std::vector<Fact> const& pre);
  float certaintyOr(std::vector<Fact> const& pre);
  float certaintyChain(float certRule, float cert);
  void certaintyCombine(std::optional<float>& acc, float cert);
};
