#include <iostream>

int main()
{
 int sum {0};

 for(int i {10}; i <= 20; i = i + 1) {
   sum = sum + i;
 }

 std::cout << "Sum of 10 to 20 = " << sum << '\n';
}
