/// Read the program and determine what the program does.

#include <iostream>
#include <limits>

int main()
{
  std::cout << "bits per bool: " << std::numeric_limits<bool>::digits << '\n';
}
