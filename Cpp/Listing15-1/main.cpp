#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main()
{
  std::ifstream in {"divina_commedia.txt"};
  std::vector<std::string> words;
  std::vector<int> counts;

  if(not in) {
    perror("divina_commedia.txt");
  } else {
    std::string string;

    while(in >> string) {
      //      std::vector<int>::iterator count {counts.begin()};
      //      for(std::vector<std::string>::iterator word {words.begin()}; word != words.end() and not found; word++, count++) {
      //        if(*word == string) {
      //          *count = *count + 1;
      //          found = true;
      //        }
      //      }

      //      if(not found) {
      //        words.push_back(string);
      //        counts.push_back(1);
      //      }

      std::vector<std::string>::iterator word {words.begin()};
      std::vector<int>::iterator count {counts.begin()};
      for( ; word != words.end() and *word != string; word++, count++);

      if(word != words.end() and *word == string) {
        *count = *count + 1;
      } else {
        words.push_back(string);
        counts.push_back(1);
      }
    }

    std::ofstream out {"divina_commedia_parole.txt"};

    if(not out) {
      perror("divina_commedia_parole.txt");
    } else {
      std::vector<int>::iterator count {counts.begin()};
      for(std::vector<std::string>::iterator word {words.begin()}; word != words.end(); ++word, ++count) {
        out << *word << '\t' << *count << std::endl;
      }
      out.close();
    }

    in.close();
  }
}
