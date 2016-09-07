#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
  std::vector<int> data;

  // Read integers from the standard input, and append them to the end of data.
  data.insert(data.end(), std::istream_iterator<int>(std::cin), std::istream_iterator<int>());

  std::reverse(data.begin(), data.end());

  for(int element : data) {
    std::cout << element << std::endl;
  }
}
