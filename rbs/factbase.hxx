#pragma once

#include <string>

class FactBase {
public:
  FactBase* readFromFile(std::string_view file);
};
