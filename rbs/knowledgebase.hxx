#pragma once

#include <string>

class KnowledgeBase {
public:
  KnowledgeBase* readFromFile(std::string_view file);
};
