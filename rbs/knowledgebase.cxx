#include "knowledgebase.hxx"

#include <iostream>
#include <fstream>


KnowledgeBase::KnowledgeBase() : rules() {}

void KnowledgeBase::getConflictSet(std::vector<Rule>& conflictSet, Fact f) {
  for (auto r: rules) {
    if (r.pos == f) {
      conflictSet.push_back(r);
    }
  }
}

std::istream &operator>>(std::istream &is, KnowledgeBase &kb) {
  size_t numRules; is >> numRules; is.ignore(); // "[newline]"

  kb.rules.resize(numRules);
  for (auto& r: kb.rules) {
      is >> r;
  }

  return is;
}

std::ostream &operator<<(std::ostream &os, KnowledgeBase const &kb) {
  os << "Num rules: " << kb.rules.size() << std::endl;
  for (auto rule: kb.rules)
    os << rule << std::endl;
  return os;
}
