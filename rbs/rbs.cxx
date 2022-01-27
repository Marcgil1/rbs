#include "defs.hxx"
#include "factbase.hxx"
#include "knowledgeBase.hxx"
#include "inferenceengine.hxx"

#include <fstream>
#include <string>
#include <iostream>


int main(int argc, char* argv[]) {

  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " [knowledge_base] [fact_base]"
              << std::endl;
    return 1;
  }

  std::cout << "----------------------------------------" << std::endl;
  std::cout << "- Program arguments --------------------" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Knowledge base: " << argv[1] << std::endl;
  std::cout << "Fact base:      " << argv[2] << std::endl;

  std::string kbFile(argv[1]); std::ifstream kbFs(kbFile);
  std::string fbFile(argv[2]); std::ifstream fbFs(fbFile);

  KnowledgeBase kb; kbFs >> kb;
  FactBase      fb; fbFs >> fb;

  std::cout << "----------------------------------------" << std::endl;
  std::cout << "- Content of files ---------------------" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << kb << std::endl;
  std::cout << fb << std::endl;

  std::cout << "----------------------------------------" << std::endl;
  std::cout << "- Program execution --------------------" << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  InferenceEngine ie(fb, kb);
  std::vector<Rule> mem;
  auto res = ie.verify(fb.getGoal(), mem);

  if (res) {
    std::cout << "The goal could be inferred through the application of the "
              << "following rules:" << std::endl;
    for (auto rule: mem) {
      std::cout << rule << std::endl;
    }
  } else {
    std::cout << "The goal could not be inferred" << std::endl;
  }
}
