#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
  std::vector<int> data;
  int x {};

  while(std::cin >> x) {
    data.push_back(x);
  }

  std::sort(data.begin(), data.end());

  for(std::vector<int>::iterator i {data.begin()}, end {data.end()}; i != end; i++) {
    std::cout << *i << std::endl;
  }

  for (int element : data) {
    std::cout << element << std::endl;
  }
}
