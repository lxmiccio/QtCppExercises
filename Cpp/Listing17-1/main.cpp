#include <iostream>

int main(int argc, char *argv[])
{
  bool haveValue {false};
  int value {};

  char ch {};
  while(std::cin.get(ch)) {
    if(ch >= '0' and ch <= '9') {
      value = ch - '0';
      haveValue = true;
      while(std::cin.get(ch) and ch >= '0' and ch <= '9') {
        value = value * 10 + ch - '0';
      }
    }

    if(ch == '\n') {
      if(haveValue) {
        std::cout << value << std::endl;
        haveValue = false;
      }
    } else if(ch != ' ' and ch != '\t') {
      std::cout << '\a';
      haveValue = false;

      while(std::cin.get(ch) and ch != '\n');
    }
  }
}
