#include "tools/tools.h"

int main(int argc, char* argv[]) {
  try {
    Tools d = readData(argc, argv);
    cout << d.alfabeto << endl;
  } catch (const exception& e) {
    cerr << e.what() << endl;
    return EXIT_FAILURE;
  }
  return 0;
}