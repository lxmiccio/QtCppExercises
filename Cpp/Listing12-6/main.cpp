#include <iostream>
#include <string>

int main()
{
  std::string a {"abc"}, b {"abc"};

  if(a != b) std::cout << "wrong: abc != abc" << std::endl;
  if(a < b) std::cout << "wrong: abc < abc" << std::endl;
  if(a > b) std::cout << "wrong: abc > abc" << std::endl;
  if(a == b) std::cout << "okay: abc == abc" << std::endl;
  if(a >= b) std::cout << "okay: abc >= abc" << std::endl;
  if(a <= b) std::cout << "okay: abc <= abc" << std::endl;

  a.push_back('d');

  if(a != b) std::cout << "okay: abcd != abc" << std::endl;
  if(a < b) std::cout << "wrong: abcd < abc" << std::endl;
  if(a > b) std::cout << "okay: abcd > abc" << std::endl;
  if(a == b) std::cout << "wrong: abcd == abc" << std::endl;
  if(a >= b) std::cout << "okay: abcd >= abc" << std::endl;
  if(a <= b) std::cout << "wrong: abcd <= abc" << std::endl;

  b.push_back('e');

  if(a != b) std::cout << "okay: abcd != abce" << std::endl;
  if(a < b) std::cout << "okay: abcd < abce" << std::endl;
  if(a > b) std::cout << "wrong: abcd > abce" << std::endl;
  if(a == b) std::cout << "wrong: abcd == abce" << std::endl;
  if(a >= b) std::cout << "wrong: abcd >= abce" << std::endl;
  if(a <= b) std::cout << "okay: abcd <= abce" << std::endl;
}
