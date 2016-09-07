#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
  std::vector<int> data; // No need to initialize

  int x {};

  while(std::cin >> x) {
    data.push_back(x);
  }

  std::sort(data.begin(), data.end());

  for(std::vector<int>::size_type i {0}, end {data.size()}; i != end; ++i) {
    std::cout << data.at(i) << std::endl;
  }
}
