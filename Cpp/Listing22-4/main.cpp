#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
/** Predicate for sorting into descending order. */

int descending(int a, int b);

int main()
{
    std::vector<int> data{};

    data.insert(data.begin(), std::istream_iterator<int>(std::cin), std::istream_iterator<int>());

    std::sort(data.begin(), data.end(), descending);

    std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, "\n"));
}

int descending(int a, int b)
{
    return a > b;
}
