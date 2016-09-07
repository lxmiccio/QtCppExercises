#include <iostream>
#include <string>

int main()
{
  std::string shape;
  int sides;

  std::cout << "Shape\t\tSides\n"
               "-----\t\t-----\n";
  std::cout << "Square\t\t" << 4 << '\n' <<
               "Circle\t\t?\n" <<
               shape << "\t" << sides << '\n';
}
