#pragma once

#include "defs.hxx"
#include "factbase.hxx"
#include "knowledgebase.hxx"


class InferenceEngine {
public:
  InferenceEngine(FactBase fb, KnowledgeBase kb);
  bool verify(Fact goal);

private:
  FactBase fb;
  KnowledgeBase kb;

  Rule solve(std::vector<Rule>& conflictSet);
  Fact selectGoal(std::vector<Fact>& goals);
};
