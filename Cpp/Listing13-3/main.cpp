#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
  std::vector<int> data;

  data.insert(data.end(), std::istream_iterator<int>(std::cin), std::istream_iterator<int>());

  std::sort(data.begin(), data.end());

  {
    // Print the sorted vector all on one line. Start the line with "{" and
    // end it with "}". Separate elements with commas. An empty vector prints
    // as "{ }".
    std::cout << '{';
    std::string separator {" "};
    for (int element : data) {
      std::cout << separator << element;
      separator = ", ";
    }
    std::cout << " }\n";
  }
  // Cannot use separator out here.
}
