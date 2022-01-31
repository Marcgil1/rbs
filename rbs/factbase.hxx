#pragma once

#include "defs.hxx"

#include <istream>
#include <ostream>
#include <vector>
#include <utility>
#include <string>
#include <optional>

class FactBase {
public:
  float setCert(Fact f, float cert);
  std::optional<float> getCert(Fact f);
  Fact getGoal();

  friend std::ostream &operator<<(std::ostream &os, FactBase const& fb);
  friend std::istream &operator>>(std::istream &is, FactBase &fb);
private:
  std::vector<std::pair<Fact, float> > facts;
  Fact obj;
};

