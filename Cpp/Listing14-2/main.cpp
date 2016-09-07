#include <cstdio>
#include <fstream>
#include <iostream>

int main()
{
  std::fstream in {"list1402.in"};

  if(not in) {
    perror("list1402.in");
  } else {
    std::ofstream out {"list1402.out"};

    if(not out) {
      perror("list1402.out");
    } else {
      int x {};
      while(in >> x) {
        out << x << std::endl;
      }
      out.close();
    }
    in.close();
  }
}
