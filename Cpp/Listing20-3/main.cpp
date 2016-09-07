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

void initializeStreams(std::locale loc);
wordMap readFromFile(std::locale loc);
string sanitizeWord(string word, std::locale loc);
stringSize getMaxWordWidth(wordMap words);
stringSize getMaxCountWidth(wordMap words);
void printToFile(wordMap words);

int main()
{
    std::locale native {""};
    initializeStreams(native);

    printToFile(readFromFile(native));
}

void initializeStreams(std::locale loc)
{
    std::cin.imbue(loc);
    std::cout.imbue(loc);
}

wordMap readFromFile(std::locale loc)
{
    inputStream in {"out_of_mind.txt"};
    wordMap words;

    if(not in) {
        perror("out_of_mind.txt");
    } else {
        string word;

        while(in >> word) {
            string copy = sanitizeWord(word, loc);

            if(not copy.empty()) {
                ++words[copy];
            }
        }

        in.close();
    }

    return words;
}

string sanitizeWord(string word, std::locale loc)
{
    string copy;

    for(char ch : word) {
        if(isalpha(ch, loc)) {
            copy.push_back(std::tolower(ch, loc));
        }
    }

    return copy;
}

stringSize getMaxWordWidth(wordMap words)
{
    stringSize maxWordWidth {};

    for(wordPair pair : words) {
        if(pair.first.size() > maxWordWidth) {
            maxWordWidth = pair.first.size();
        }
    }

    return maxWordWidth;
}

stringSize getMaxCountWidth(wordMap words)
{
    stringSize maxCountWidth {};

    for(wordPair pair : words) {
        if(std::to_string(pair.second).size() > maxCountWidth) {
            maxCountWidth = std::to_string(pair.second).size();
        }
    }

    return maxCountWidth;
}

void printToFile(wordMap words)
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



//#include <cstdio>
//#include <fstream>
//#include <iomanip>
//#include <iostream>
//#include <locale>
//#include <map>
//#include <string>

//typedef std::ifstream inputStream;
//typedef std::ofstream outputStream;
//typedef std::string string;
//typedef std::string::size_type stringSize;
//typedef std::map<std::string, int> wordMap;
//typedef wordMap::value_type wordPair;

//void initializeStreams(std::locale loc);
//wordMap readFromFile(inputStream& in, std::locale loc);
//string sanitizeWord(string word, std::locale loc);
//stringSize getMaxWordWidth(wordMap words);
//stringSize getMaxCountWidth(wordMap words);
//void printToFile(outputStream& out, wordMap words);

//int main()
//{
//    std::locale native {""};
//    initializeStreams(native);

//    inputStream in {"out_of_mind.txt"};
//    wordMap words;

//    if(not in) {
//        perror("out_of_mind.txt");
//    } else {
//        wordMap words;
//        string word;

//        while(in >> word) {
//            string copy = sanitizeWord(word, native);

//            if(not copy.empty()) {
//                ++words[copy];
//            }
//        }

//        in.close();

//        outputStream out {"out_of_mind_words.txt"};

//        if(not out) {
//            perror("out_of_mind_words.txt");
//        } else {
//            printToFile(out, words);
//        }
//    }
//}

//void initializeStreams(std::locale loc)
//{
//    std::cin.imbue(loc);
//    std::cout.imbue(loc);
//}

//wordMap readFromFile(inputStream& in, std::locale loc)
//{
//    wordMap words;
//    string word;

//    while(in >> word) {
//        string copy = sanitizeWord(word, loc);

//        if(not copy.empty()) {
//            ++words[copy];
//        }
//    }

//    in.close();

//    return words;
//}

//string sanitizeWord(string word, std::locale loc)
//{
//    string copy;

//    for(char ch : word) {
//        if(isalpha(ch, loc)) {
//            copy.push_back(std::tolower(ch, loc));
//        }
//    }

//    return copy;
//}

//stringSize getMaxWordWidth(wordMap words)
//{
//    stringSize maxWordWidth {};

//    for(wordPair pair : words) {
//        if(pair.first.size() > maxWordWidth) {
//            maxWordWidth = pair.first.size();
//        }
//    }

//    return maxWordWidth;
//}

//stringSize getMaxCountWidth(wordMap words)
//{
//    stringSize maxCountWidth {};

//    for(wordPair pair : words) {
//        if(std::to_string(pair.second).size() > maxCountWidth) {
//            maxCountWidth = std::to_string(pair.second).size();
//        }
//    }

//    return maxCountWidth;
//}

//void printToFile(outputStream& out, wordMap words)
//{
//    stringSize maxWordWidth = getMaxWordWidth(words);
//    stringSize maxCountWidth = getMaxCountWidth(words);

//    for(wordPair pair : words) {
//        out  << std::left << std::setw(maxWordWidth) << pair.first << std::right << std::setw(maxCountWidth + 3) <<  pair.second << std::endl;
//    }

//    out.close();

//    if(not out) {
//        perror("out_of_mind_words.txt");
//    }
//}
