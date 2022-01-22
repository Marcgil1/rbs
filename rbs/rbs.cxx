#include <iostream>

int main(int argc, char* argv[]) {

  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " [knowledge_base] [fact_base]" << std::endl;
    return 1;
  }

  std::cout << "Knowledge base: " << argv[1] << std::endl;
  std::cout << "Fact base:      " << argv[2] << std::endl;
}
