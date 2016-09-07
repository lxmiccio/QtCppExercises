#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
  std::vector<int> data {10, 42};
  std::ostream_iterator<int> out {std::ostream_iterator<int>(std::cout, "")};

  std::copy(data.begin(), data.end(), out);

  --out;
}
