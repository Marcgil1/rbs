#include "knowledgebase.hxx"

#include <iostream>
#include <fstream>


KnowledgeBase *KnowledgeBase::readFromFile(std::string_view file) {
  std::ifstream fs(file);
  auto *kb = new KnowledgeBase;
  size_t numRules; fs >> numRules; fs.ignore(); // "[newline]"

  kb->rules.resize(numRules);
  for (unsigned i = 0; i < numRules; i++) {
    fs.ignore(7); // "RX: Si "
    std::string input;
    while (fs >> input) {
      if      (input == "y")        kb->rules[i].type = RuleType::AND;
      else if (input == "o")        kb->rules[i].type = RuleType::OR;
      else if (input == "Entonces") break;
      else                          kb->rules[i].pre.push_back(input);
    }
    fs >> input; input.pop_back(); kb->rules[i].pos = input;
    fs.ignore(4); fs >> kb->rules[i].cert; fs.ignore();
  }

  return kb;
}

void KnowledgeBase::printBase() {
  std::cout << "Num rules: " << rules.size() << std::endl;

  for (auto r: rules) {
    std::cout << "Rule(pre=[";
    for (auto x: r.pre)
      std::cout << x << " ";
    std::cout << "], pos=" << r.pos << ", cert=" << r.cert << ", type="
              << ((r.type == RuleType::AND) ? "AND" : "OR") << ")"
              << std::endl;
  }
}
