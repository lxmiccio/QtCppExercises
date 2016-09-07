#include <cstdio>
#include <fstream>
#include <iostream>

int main()
{
  std::fstream in {"list1403.in"};

  if(not in) {
    perror("list1403.in");
  } else {
    std::ofstream out {"list1403.out"};

    if(not out) {
      perror("list1403.out");
    } else {
      int x {};
      while(in >> x) {
        out << x << std::endl;
      }
      out.close();

      // Checks for error.
      if(not out) {
        std::perror("list1403.out");
      }
    }
    in.close();
  }
}
