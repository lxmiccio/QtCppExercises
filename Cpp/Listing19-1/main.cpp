#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <map>
#include <string>

int main()
{
    std::locale native {""};
    std::cin.imbue(native);
    std::cout.imbue(native);

    typedef std::ifstream inputStream;
    typedef std::ofstream outputStream;
    typedef std::string::size_type stringSize;
    typedef std::map<std::string, int> wordMap;

    inputStream in {"out_of_mind.txt"};
    wordMap words;

    if(not in) {
        perror("out_of_mind.txt");
    } else {
        std::string word;

        while(in >> word) {
            std::string copy;

            for(char ch : word) {
                if(std::isalnum(ch, native)) {
                    copy.push_back(std::tolower(ch, native));
                }
            }

            if (not copy.empty()) {
                ++words[copy];
            }
        }

        stringSize maxWordWidth {};
        stringSize maxCountWidth {};
        for(auto element : words) {
            if(element.first.size() > maxWordWidth) {
                maxWordWidth = element.first.size();
            }
            if(std::to_string(element.second).size() > maxCountWidth) {
                maxCountWidth = std::to_string(element.second).size();
            }
        }

        outputStream out {"out_of_mind_words.txt"};

        if(not out) {
            perror("out_of_mind_words.txt");
        } else {
            for(auto element : words) {
                out  << std::left << std::setw(maxWordWidth) << element.first << std::right << std::setw(maxCountWidth + 3) << element.second << std::endl;
            }

            out.close();
        }

        in.close();
    }
}
