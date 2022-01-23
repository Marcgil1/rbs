#include "defs.hxx"


std::ostream &operator<<(std::ostream &os, RuleType type) {
  switch (type) {
  case RuleType::AND: os << "AND"; break;
  case RuleType::OR:  os << "OR";  break;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, Rule r) {
  os << "Rule(pre=[";
  for (auto x : r.pre)
    os << x << " ";
  os << "], pos=" << r.pos << ", cert=" << r.cert << ", type=" << r.type << ")";
  return os;
}
