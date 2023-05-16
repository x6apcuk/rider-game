#include <iostream>
#include <map>

using namespace std;

class Dictionary {
 private:
  map<string, int> dict;

 public:
  Dictionary() {}

  void addWord(string word, int num) {
    dict.insert(pair<string, int>(word, num));
  }

  friend ostream& operator<<(ostream& os, Dictionary& dict);
};

ostream& operator<<(ostream& os, Dictionary& dict) {
  for (auto it = dict.dict.begin(); it != dict.dict.end(); ++it) {
    os << "{" << it->first << ", " << it->second << "} ";
  }
  return os;
}

int main() {
  Dictionary dict;
  dict.addWord("one", 1);
  dict.addWord("two", 2);

  cout << dict << endl;

  return 0;
}