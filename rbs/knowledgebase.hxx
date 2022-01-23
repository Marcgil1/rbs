#pragma once

#include "defs.hxx"

#include <vector>
#include <string>


class KnowledgeBase {
public:
  static KnowledgeBase *readFromFile(std::string_view file);
  void printBase();

private:
  std::vector<Rule> rules;
};
