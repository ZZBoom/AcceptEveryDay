#include <assert.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  std::string beginWord_;
  std::string endWord_;
  std::vector<int> vis;
  int min_len;
  bool is_valid(const std::string &a, const std::string &b) {
    if (a.size() != b.size()) {
      return false;
    }
    int num = 0;
    for (auto i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) {
        num++;
      }
    }
    return num == 1;
  }
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    if (std::find(wordList.begin(), wordList.end(), endWord) ==
        wordList.end()) {
      return 0;
    }
    endWord_ = endWord;
    min_len = 0;
    vis = std::vector<int>(wordList.size(), 0);
    struct WordInfo {
      std::string word;
      int step;
    }; 
    std::queue<WordInfo> que;
    que.push({beginWord, 1});
    while (false == que.empty()) {
      auto item = que.front();
      que.pop();
      if (item.word == endWord_) {
        return item.step;
      }
      for (int i = 0; i < wordList.size(); i++) {
        if (vis[i]) {
          continue;
        }
        if (is_valid(wordList[i], item.word)) {
          vis[i] = 1;
          que.push({wordList[i], item.step + 1});
        }
      }
    }
    return 0;
  }
};

int main() {
  std::string a = "hit";
  std::string b = "cog";
  std::vector<std::string> str_list{"hot", "dot", "dog", "lot", "log", "cog"};
  printf("%d\n", Solution().ladderLength(a, b, str_list));
  return 0;
}
