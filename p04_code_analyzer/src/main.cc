#include "tools/tools.h"

int main(int argc, char* argv[]) {
  Tools tools = parseArgs(argc, argv);
  std::cout << "Fichero de entrada: " << tools.filein << std::endl;
  std::cout << "Fichero de salida: " << tools.fileout << std::endl;
  return 0;
}