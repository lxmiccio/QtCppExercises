#include <cstdio>
#include <fstream>
#include <iostream>

int main()
{
  std::ifstream in {"list1401.txt"};

  if(not in) {
    std::perror("list1401.txt");
  } else {
    int x {};
    while(in >> x) {
      std::cout << x << std::endl;
    }
    in.close();
  }
}
