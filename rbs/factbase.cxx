#include "factbase.hxx"

#include <fstream>
#include <iostream>

FactBase *FactBase::readFromFile(std::string_view file) {
  std::ifstream fs(file);
  auto fb = new FactBase();;
  int numFacts;

  fs >> numFacts; fs.ignore();
  fb->facts.resize(numFacts);
  for (unsigned i = 0; i < numFacts; i++) {
    std::string fact; fs >> fact; fs.ignore(4); fact.pop_back();
    float cert;       fs >> cert;

    fb->facts[i] = {fact, cert};
  }

  fs >> fb->obj >> fb->obj;

  return fb;
}

void FactBase::printBase() {
  std::cout << "Num facts: " << facts.size() << std::endl;

  for (auto [fact, cert]: facts)
    std::cout << "Fact: " << fact << ", cert: " << cert << std::endl;

  std::cout << "Objective: " << obj << std::endl;
}
