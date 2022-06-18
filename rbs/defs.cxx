#include "defs.hxx"


std::ostream &operator<<(std::ostream &os, RuleType type) {
  switch (type) {
  case RuleType::AND:
    os << "AND";
    break;
  case RuleType::OR:
    os << "OR";
    break;
  case RuleType::SINGLETON:
    os << "SINGLETON";
    break;
  }
  return os;
}

std::istream &operator>>(std::istream &is, Rule &r) {
  is >> r.id; r.id.pop_back(); // Reads   "id:"
  is.ignore(4);                // Ignores " Si "
  std::string input;
  while (is >> input) {
    if      (input == "y")        r.type = RuleType::AND;
    else if (input == "o")        r.type = RuleType::OR;
    else if (input == "Entonces") break;
    else                          r.pre.push_back(input);
  }
  is >> r.pos; r.pos.pop_back(); // Reads "pos,"
  is.ignore(4);                  // Ignore " FC="
  is >> r.cert;
  
  return is;
}

std::ostream &operator<<(std::ostream &os, Rule r) {
  os << "Rule(id='" << r.id << "', pre=[";
  for (auto x : r.pre)
    os << x << " ";
  os << "], pos=" << r.pos << ", cert=" << r.cert << ", type=" << r.type << ")";
  return os;
}
