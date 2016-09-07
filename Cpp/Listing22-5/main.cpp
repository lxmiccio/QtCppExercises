#include <algorithm>
#include <iostream>
#include <locale>
#include <string>

typedef std::string string;

void initializeStreams();
bool isPalindrome(string string);
bool isNotLetter(char ch);
bool isSameChar(char a, char b);
char lowercase(char ch);

int main()
{
    std::locale::global(std::locale{""});
    initializeStreams();

    string line;

    while(std::getline(std::cin, line)) {
        if(isPalindrome(line)) {
            std::cout << line << " is palindrome" << std::endl;
        }
    }
}

void initializeStreams()
{
    std::cin.imbue(std::locale{});
    std::cout.imbue(std::locale{});
}

bool isPalindrome(string word)
{
    string::iterator end {std::remove_if(word.begin(), word.end(), isNotLetter)};

    std::string reverse {word.begin(), end};
    std::reverse(reverse.begin(), reverse.end());

    return not reverse.empty() and std::equal(word.begin(), end, reverse.begin(), isSameChar);
}

bool isNotLetter(char ch)
{
    return not isalnum(ch, std::locale());
}

bool isSameChar(char a, char b)
{
    return lowercase(a) == lowercase(b);
}

char lowercase(char ch)
{
    return std::tolower(ch, std::locale());
}
