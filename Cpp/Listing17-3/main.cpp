#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main()
{
  typedef std::vector<int> intVector;
  typedef intVector::iterator iterator;

  intVector xs;
  intVector ys;

  int x {};
  int y {};
  char separator {};

  while(std::cin >> x >> separator and separator == ',' and std::cin >> y) {
    xs.push_back(x);
    ys.push_back(y);
  }

  for(iterator x {xs.begin()}, y {ys.begin()}; x != xs.end() and y != ys.end(); ++x, ++y) {
    std::cout << *x << ',' << *y << std::endl;
  }
}
