#pragma once

#include <vector>
#include <string>


// Fact type. -----------------------------------------------------------------
typedef std::string Fact;

// Rule type. -----------------------------------------------------------------
enum class RuleType { AND, OR };

// Rule -----------------------------------------------------------------------
struct Rule {
  std::vector<Fact> pre;
  Fact pos;
  float cert;
  RuleType type = RuleType::AND;
};
