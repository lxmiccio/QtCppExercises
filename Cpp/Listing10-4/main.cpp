#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
  std::vector<int> data;

  std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(data));

  std::cout << std::left;

  for(int element : data) {
    std::cout << std::setw(5) << element << std::setw(5) << element * 2 << std::setw(5) << element * element << std::endl;
  }
}
