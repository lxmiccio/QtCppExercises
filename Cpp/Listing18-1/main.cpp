#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

int main()
{
  typedef std::map<std::string, int> countMap;
  typedef std::string::size_type stringSize;

  std::string okay{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_"};
  countMap counts;

  std::ifstream in {"out_of_mind.txt"};

  if(not in) {
    perror("out_of_mind.txt");
  } else {
    std::string word;

    while(in >> word) {
      std::string copy;

      for(char ch : word) {
        if(okay.find(ch) != std::string::npos) {
          copy.push_back(ch);
        }
      }

      if(not copy.empty()) {
        ++counts[copy];
      }
    }

    std::ofstream out {"out_of_mind_words.txt"};

    if(not out) {
      perror("out_of_mind_words.txt");
    } else {
      stringSize width {0};

      for(auto element : counts) {
        if(element.first.size() > width) {
          width = element.first.size();
        }
      }

      const int count_size {10};
      for(auto element : counts) {
        out << std::left << std::setw(width) << element.first << std::right << std::setw(count_size) << element.second << std::endl;
      }
      out.close();

      if(not out) {
        perror("out_of_mind_words.txt");
      }
    }

    in.close();
  }
}
