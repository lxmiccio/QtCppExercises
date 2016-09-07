#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
 cout << setfill('0') << setw(6) << 42 << '\n';
 cout << left << setw(6) << 42 << '\n';
 cout << 42 << '\n';
 cout << setfill('-') << setw(4) << -42 << '\n';
}
