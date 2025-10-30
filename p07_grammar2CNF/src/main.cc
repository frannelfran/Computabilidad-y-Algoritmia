#include "tools/tools.h"

int main(int argc, char* argv[]) {
  try {
    Tools datos = parseArgs(argc, argv);
  } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return EXIT_FAILURE;
  }
}