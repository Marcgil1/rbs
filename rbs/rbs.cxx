#include "defs.hxx"
#include "factbase.hxx"
#include "knowledgeBase.hxx"

#include <memory>
#include <string>
#include <iostream>


int main(int argc, char* argv[]) {

  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " [knowledge_base] [fact_base]"
              << std::endl;
    return 1;
  }

  std::cout << "Knowledge base: " << argv[1] << std::endl;
  std::cout << "Fact base:      " << argv[2] << std::endl;

  std::string kbFile(argv[1]);
  std::string fbFile(argv[2]);
  auto kb = std::unique_ptr<KnowledgeBase>(KnowledgeBase::readFromFile(kbFile));
  auto fb = std::unique_ptr<FactBase>(FactBase::readFromFile(fbFile));

  kb->printBase();
  fb->printBase();
}
