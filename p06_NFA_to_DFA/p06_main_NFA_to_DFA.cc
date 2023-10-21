#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  if(argc == 2) {
    string ayuda = argv[1];
    if(ayuda == "--help" ) {
      cout << "Modo de empleo: ./NFA2DFA input.nfa output.dfa" << endl;
      exit(EXIT_SUCCESS);
    }
  }
  else if(argc != 3) {
    cout << "Pruebe ’NFA2DFA --help’ para más información." << endl;
    return 1;
  }
}