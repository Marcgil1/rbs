#pragma once

#include "defs.hxx"

#include <vector>
#include <utility>
#include <string>

class FactBase {
public:
  static FactBase *readFromFile(std::string_view file);
  void printBase();
private:
  std::vector<std::pair<Fact, float> > facts;
  Fact obj;
};
