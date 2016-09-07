#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main()
{
  typedef std::map<std::string, int> countMap;
  typedef countMap::iterator countIterator;

//  using countMap = std::map<std::string, int>;
//  using countIterator = countMap::iterator;

  countMap counts;

  std::ifstream in {"divina_commedia.txt"};

  if(not in) {
    perror("divina_commedia.txt");
  } else {
    std::string word;

    while(in >> word) {
      ++counts[word];
    }

    countIterator di {counts.find("di")};

    if(di == counts.end()) {
      std::cout << "\"di\" not found" << std::endl;
    } else if(di->second == 1) {
      std::cout << "\"di\" occurs " << di->second << " time" << std::endl;
    } else {
      std::cout << "\"di\" occurs " << di->second << " times" << std::endl;
    }
  }
}
