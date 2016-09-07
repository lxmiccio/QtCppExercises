#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
  int const min {1};
  int const max {10};
  int const width {4};

  cout << right;

  cout << setw(width) << '*' << '|';
  for(int i {min}; i <= max; i = i + 1) {
    cout << setw(width) << i;
  }
  cout << '\n';

  cout << setfill('-') << setw(width) << "" <<
          '+' <<
          setw((max - min + 1) * width) << "" <<
          '\n';

  cout << setfill(' ');

  for(int i {min}; i <= max; i = i + 1) {
    cout << setw(width) << i << '|';
    for(int j {min}; j <= max; j = j + 1) {
      cout << setw(width) << i * j;
    }
    cout << '\n';
  }
}
