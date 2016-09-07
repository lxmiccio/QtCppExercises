#include <fstream>
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
      for(auto element : counts) {
        out << element.first << '\t' << element.second << std::endl;
      }
      out.close();
    }

    in.close();
  }
}
