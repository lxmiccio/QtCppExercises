#include <iostream>

int main()
{
  int x {42};

  std::cout << "x   = " << x   << std::endl;
  std::cout << "++x = " << ++x << std::endl;
  std::cout << "x   = " << x   << std::endl;
  std::cout << "x++ = " << x++ << std::endl;
  std::cout << "x   = " << x   << std::endl;
}
