#include "headers/filereader.hpp"
#include <string>
#include <fstream>

std::string minesweeperbot::filereader::readfile(std::string path) {

  std::string output;

  std::ifstream file(path);

  std::string line;

  while (std::getline(file, line)) {
    output.append(line);
    output.append("\n");
  }

  file.close();

  return output;

}

