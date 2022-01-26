#include "factbase.hxx"

#include <fstream>
#include <iostream>


bool FactBase::containsFact(Fact f) {
  return end(facts) != find_if(begin(facts), end(facts),
                               [&] (auto p) { return p.first == f; });
}

void FactBase::addFact(Fact f) {
  // TODO: When implementing certainty factors, this should be modified.
  facts.push_back({ f, 0.0 });
}

std::istream &operator>>(std::istream &is, FactBase &fb) {
  int numFacts; is >> numFacts; is.ignore();
  fb.facts.resize(numFacts);
  for (unsigned i = 0; i < numFacts; i++) {
    std::string fact; is >> fact; is.ignore(4); fact.pop_back();
    float cert;       is >> cert;

    fb.facts[i] = {fact, cert};
  }

  is >> fb.obj >> fb.obj;

  return is;
}

std::ostream &operator<<(std::ostream &os, FactBase const& fb) {
  os << "Num facts: " << fb.facts.size() << std::endl;
  for (auto [fact, cert]: fb.facts)
    std::cout << "Fact: " << fact << ", cert: " << cert << std::endl;
  std::cout << "Objective: " << fb.obj << std::endl;

  return os;
}
