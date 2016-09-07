#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
 cout << '|' << setfill('*') << setw(6) << 1234 << '|' << '\n';
 cout << '|' << left << setw(6) << 1234 << '|' << '\n';
 cout << '|' << setw(6) << -1234 << '|' << '\n';
 cout << '|' << right << setw(6) << -1234 << '|' << '\n';
}
