/// Read the program and determine what the program does.

#include <iostream>

int main()
{
  int x;

  while(std::cin >> x) {
    if(x % 2) {
      std::cout << x << " is odd.\n";
    }
    else {
      std::cout << x << " is even.\n";
    }
  }
}
