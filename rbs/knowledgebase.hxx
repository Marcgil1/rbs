#pragma once

#include "defs.hxx"

#include <istream>
#include <ostream>
#include <vector>
#include <string>


class KnowledgeBase {
public:
  KnowledgeBase();

  void getConflictSet(std::vector<Rule>& conflictSet, Fact f);

  friend std::ostream &operator<<(std::ostream &os, KnowledgeBase const& kb);
  friend std::istream &operator>>(std::istream &is, KnowledgeBase &kb);

private:
  std::vector<Rule> rules;
};
