#include <iostream>
#include <vector>

int main()
{
  std::vector<int> positiveData, negativeData;

  for(int x {0}; std::cin >> x; ) {
    if(x < 0) {
      negativeData.push_back(x);
    } else {
      positiveData.push_back(x);
    }
  }
}
