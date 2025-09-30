/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Informatica Basica
 * 
 * @brief Ejercicios de programacion
 *        Version 1: Funcion factorial
 */

#include <iostream>
#include <cassert>

// Returns the factorial of the argument
int Factorial(int number) {
  switch (number) {
    case 0:
    case 1:
      return 1;
    default:
      int factorial = 1;
      for (int i = 1; i <= number; ++i) {
        factorial *= i;
      }
      return factorial;
  }
}

int main() {
  std::cout << "ntorduzca el número de factoriales a calcular: ";
  int limit;
  std::cin >> limit;
  for (int i = 0; i < limit; ++i) {
    std::cout << i << "! = " << (double)Factorial(i) << std::endl;
  }
  return 0;
}