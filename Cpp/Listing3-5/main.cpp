#include <iostream>

int main()
{
  int sum {0};
  int count {};
  int x;

  while(std::cin >> x) {
    sum = sum + x;
    count = count + 1;
  }

  if(count) {
    std::cout << "average = " << sum / count << '\n';
  }
  else {
    std::cout << "No data.\n";
  }
}
