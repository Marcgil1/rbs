#include "knowledgebase.hxx"

#include <iostream>
#include <fstream>


KnowledgeBase::KnowledgeBase() : rules() {}

std::istream &operator>>(std::istream &is, KnowledgeBase &kb) {
  size_t numRules; is >> numRules; is.ignore(); // "[newline]"

  kb.rules.resize(numRules);
  for (unsigned i = 0; i < numRules; i++) {
    is.ignore(7); // "RX: Si "
    std::string input;
    while (is >> input) {
      if      (input == "y")        kb.rules[i].type = RuleType::AND;
      else if (input == "o")        kb.rules[i].type = RuleType::OR;
      else if (input == "Entonces") break;
      else                          kb.rules[i].pre.push_back(input);
    }
    is >> input; input.pop_back(); kb.rules[i].pos = input;
    is.ignore(4); is >> kb.rules[i].cert; is.ignore();
  }

  return is;
}

std::ostream &operator<<(std::ostream &os, KnowledgeBase const &kb) {
  os << "Num rules: " << kb.rules.size() << std::endl;
  for (auto rule: kb.rules)
    os << rule << std::endl;
  return os;
}
