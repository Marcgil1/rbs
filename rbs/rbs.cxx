#include "defs.hxx"
#include "factbase.hxx"
#include "knowledgebase.hxx"
#include "inferenceengine.hxx"

#include <exception>
#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

std::ifstream kbFs;
std::ifstream fbFs;

std::ostream& os = std::cout;

fs::path kbPath;
fs::path fbPath;
fs::path outPath;

KnowledgeBase kb;
FactBase      fb;

float res;

void openIfstream       (std::ifstream& ifs, char* name);
void checkArgs          (int argc, char* argv[]);
void initData           (char* argv[]);
void printInputData     ();
void printContentOfFiles();
void execProgram        ();
void printResults       ();

int main(int argc, char *argv[]) {
  checkArgs          (argc, argv);
  initData           (argv);
  printInputData     ();
  //printContentOfFiles();
  execProgram        ();
  printResults       ();
}

void checkArgs(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " [knowledge_base] [fact_base]"
              << std::endl;
    std::exit(1);
  }
}

void initData(char* argv[]) {
  openIfstream(kbFs, argv[1]);
  openIfstream(fbFs, argv[2]);

  kbPath = argv[1];
  fbPath = argv[2];
  
  kbFs >> kb;
  fbFs >> fb;

  outPath /= kbPath.stem();
  outPath += fbPath.stem();
  outPath += ".txt";
}

void printInputData() {
  os << "----------------------------------------" << std::endl;
  os << "- Input data ---------------------------" << std::endl;
  os << "----------------------------------------" << std::endl;
  os << "Knowledge base: " << kbPath.filename()    << std::endl;
  os << "Fact base:      " << fbPath.filename()    << std::endl;
  os << "Output file:    " << outPath              << std::endl;
  os << "Objective:      " << fb.getGoal()         << std::endl;
}

void printContentOfFiles() {
  os << "----------------------------------------" << std::endl;
  os << "- Content of files ---------------------" << std::endl;
  os << "----------------------------------------" << std::endl;
  os << kb                                         << std::endl;
  os << fb                                         << std::endl;
}

void execProgram() {
  os << "----------------------------------------" << std::endl;
  os << "- Program execution --------------------" << std::endl;
  os << "----------------------------------------" << std::endl;

  InferenceEngine ie(fb, kb, std::cerr);
  res = ie.verify(fb.getGoal());
}

void printResults() {
  os << "----------------------------------------" << std::endl;
  os << "- Result -------------------------------" << std::endl;
  os << "----------------------------------------" << std::endl;
  os << "The fact " << fb.getGoal() << " has certainty " << res << std::endl;
}

void openIfstream(std::ifstream& ifs, char* name) {
  try {
      ifs.open(name);
  } catch (std::exception const& ex) {
      std::cerr << "There was a problem opening '" << name;
      std::cerr << "' Does this file exist?" << std::endl;
      std::exit(1);
  }
}
