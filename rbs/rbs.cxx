#include "defs.hxx"
#include "factbase.hxx"
#include "knowledgeBase.hxx"

#include <fstream>
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

  std::string kbFile(argv[1]); std::ifstream kbFs(kbFile);
  std::string fbFile(argv[2]); std::ifstream fbFs(fbFile);

  KnowledgeBase kb; kbFs >> kb;
  FactBase      fb; fbFs >> fb;

  std::cout << kb << std::endl;
  std::cout << fb << std::endl;
}
