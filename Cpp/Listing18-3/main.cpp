#include <iostream>
#include <locale>

int main()
{

    int sum {0};
    int x {};
    while (std::cin >> x) {
        sum = sum + x;
    }

    std::cout.imbue(std::locale{""});
    std::cout << "sum = " << sum << std::endl;
}
