#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
  std::vector<int> data;

  std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(data));

  for(std::vector<int>::iterator begin {data.begin()}, end {data.end()}; begin != end and begin != --end; ++begin) {
      std::iter_swap(begin, end);
  }

  for(int element : data) {
    std::cout << element << std::endl;
  }
}
