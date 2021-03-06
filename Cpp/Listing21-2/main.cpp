#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void modify(int& x);
int triple(int x);
//int triple(int const& x);
void print_vector(std::vector<int> const& v);
void add(std::vector<int>& v, int a);

int main()
{
    int a {42};
    modify(a);
    std::cout << "a=" << a << std::endl;

    int b {triple(14)};
    std::cout << "b=" << b << std::endl;

    std::vector<int> data {10, 20, 30, 40};
    print_vector(data);

    add(data, 42);
    print_vector(data);
}

void modify(int& x)
{
    x = 10;
}

int triple(int x)
{
    return 3 * x;
}

void print_vector(std::vector<int> const& v)
{
    std::cout << "{";
    std::string separator{" "};
    for (std::vector<int>::const_iterator i {v.begin()}, end {v.end()}; i != end; ++i) {
        std::cout << separator << *i;
        separator = ", ";
    }
    std::cout << "}" << std::endl;
}

void add(std::vector<int>& v, int a)
{
    for (auto iter(v.begin()), end(v.end()); iter != end; ++iter) {
        *iter = *iter + a;
    }
}
