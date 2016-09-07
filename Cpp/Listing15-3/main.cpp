#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

int main()
{
  std::map<std::string, int> counts;

  std::ifstream in {"divina_commedia.txt"};

  if(not in) {
    perror("divina_commedia.txt");
  } else {
    std::string word;

    while(in >> word) {
      ++counts[word];
    }

    std::ofstream out {"divina_commedia_parole.txt"};

    if(not out) {
      perror("divina_commedia_parole.txt");
    } else {
      std::string::size_type width {};

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
        perror("divina_commedia_parole.txt");
      }
    }

    in.close();
  }
}
