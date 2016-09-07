#include <iostream>
#include <iterator>
#include <vector>

int main()
{
  std::vector<int> data;

  data.insert(data.end(), std::istream_iterator<int>(std::cin), std::istream_iterator<int>());

  std::vector<int>::iterator iterator;

  for(iterator = data.begin(); iterator != data.end() and *iterator == 0; ++iterator);

  if(iterator == data.end()) {
    std::cout << "data contains all zeroes" << std::endl;
  } else {
    std::cout << "data does not contain all zeroes" << std::endl;
  }
}
