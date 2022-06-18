#pragma once

#include <iostream>
#include <vector>
#include <string>


// Fact type. -----------------------------------------------------------------
typedef std::string Fact;

//Rule type. ------------------------------------------------------------------
enum class RuleType { AND, OR, SINGLETON };

std::ostream &operator<<(std::ostream &os, RuleType type);

// Rule -----------------------------------------------------------------------
struct Rule {
  std::string id;
  std::vector<Fact> pre;
  Fact pos;
  float cert;
  RuleType type = RuleType::SINGLETON;
};

std::istream &operator>>(std::istream &is, Rule &r);
std::ostream &operator<<(std::ostream &os, Rule r);
