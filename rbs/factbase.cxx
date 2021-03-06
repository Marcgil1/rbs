#include "factbase.hxx"

#include <fstream>
#include <iostream>


float FactBase::setCert(Fact f, float cert) {
  auto it = std::find_if(begin(facts), end(facts),
                         [&] (auto p) { return p.first == f; });
  if (it == end(facts)) {
    facts.push_back({f, cert});
  } else {
    it->second = cert;
  }

  return cert;
}

std::optional<float> FactBase::getCert(Fact f) {
  auto it = std::find_if(begin(facts), end(facts),
                         [&] (auto p) { return p.first == f; });
  if (it == end(facts)) {
    return std::nullopt;
  } else {
    return it->second;
  }
}

Fact FactBase::getGoal() {
  return obj;
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
