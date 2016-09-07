/// Read the program and determine what the program does.

#include <iostream>
#include <limits>

int main()
{
  int min {std::numeric_limits<int>::max()};
  int max {std::numeric_limits<int>::min()};
  int x;
  bool any {false};

  while(std::cin >> x) {
    any = true;
    if(x) {
      min = x;
    }
    if(x > max) {
      max = x;
    }
  }

  if(any) {
    std::cout << "min = " << min << "\nmax = " << max << '\n';
  }
}
