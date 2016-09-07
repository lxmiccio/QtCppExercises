#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <map>
#include <string>

typedef std::ifstream inputStream;
typedef std::ofstream outputStream;
typedef std::string string;
typedef std::string::size_type stringSize;
typedef std::map<std::string, int> wordMap;
typedef wordMap::value_type wordPair;

void initializeStreams();
wordMap readFromFile();
string sanitizeWord(string word);
bool nonLetter(char ch);
char lowercase(char ch);
stringSize getMaxWordWidth(wordMap const& words);
stringSize getMaxCountWidth(wordMap const& words);
void printToFile(wordMap const& words);

int main()
{
    std::locale::global(std::locale{""});
    initializeStreams();

    printToFile(readFromFile());
}

void initializeStreams()
{
    std::cin.imbue(std::locale{});
    std::cout.imbue(std::locale{});
}

wordMap readFromFile()
{
    inputStream in {"out_of_mind.txt"};
    wordMap words;

    if(not in) {
        perror("out_of_mind.txt");
    } else {
        string word;

        while(in >> word) {
            string copy = sanitizeWord(word);

            if(not copy.empty()) {
                ++words[copy];
            }
        }

        in.close();
    }

    return words;
}

string sanitizeWord(string word)
{
    word.erase(std::remove_if(word.begin(), word.end(), nonLetter), word.end());

    std::transform(word.begin(), word.end(), word.begin(), lowercase);

    return word;
}

bool nonLetter(char ch)
{
    return not std::isalnum(ch, std::locale());
}

char lowercase(char ch)
{
    return std::tolower(ch, std::locale());
}

stringSize getMaxWordWidth(wordMap const& words)
{
    stringSize maxWordWidth {};

    for(wordPair pair : words) {
        if(pair.first.size() > maxWordWidth) {
            maxWordWidth = pair.first.size();
        }
    }

    return maxWordWidth;
}

stringSize getMaxCountWidth(wordMap const& words)
{
    stringSize maxCountWidth {};

    for(wordPair pair : words) {
        if(std::to_string(pair.second).size() > maxCountWidth) {
            maxCountWidth = std::to_string(pair.second).size();
        }
    }

    return maxCountWidth;
}

void printToFile(wordMap const& words)
{
    outputStream out {"out_of_mind_words.txt"};

    if(not out) {
        perror("out_of_mind_words.txt");
    } else {
        stringSize maxWordWidth = getMaxWordWidth(words);
        stringSize maxCountWidth = getMaxCountWidth(words);

        for(wordPair pair : words) {
            out  << std::left << std::setw(maxWordWidth) << pair.first << std::right << std::setw(maxCountWidth + 3) <<  pair.second << std::endl;
        }

        out.close();

        if(not out) {
            perror("out_of_mind_words.txt");
        }
    }
}
