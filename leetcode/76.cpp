
#include <assert.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;



class Solution {
public:
  int get_index(char c) {
    if (c >= 'A' && c <= 'Z') {
      return c - 'A';
    }
    return c - 'a' + 26;
  }
  string minWindow(string s, string t) {
    int cnt[52] = {0};
    int t_cnt[52] = {0};
    for (auto c : t) {
      int index = get_index(c);
      cnt[index]++;
    }
    int flag = 0;
    int temp_flag = 0;
    for (int i = 0; i < 52; i++) {
      if (cnt[i] > 0) {
        flag++;
      }
    }
    int st = 0;
    int ed = 0;
    int index = get_index(s[ed]);
    t_cnt[index]++;
    if (t_cnt[index] == cnt[index]) {
      temp_flag++;
    }
    int n = s.size();
    int ans = n + 1;
    int ans_st = 0;
    while(true) {
      while(temp_flag != flag && ed + 1 < n) {
        ed++;
        int index = get_index(s[ed]);
        t_cnt[index]++;
        if (t_cnt[index] == cnt[index]) {
          temp_flag++;
        }
      }
      //printf("st: %d\n ed: %d\n", st, ed);
      //assert();
      int length = ed - st + 1;
      if (ans > length && temp_flag == flag) {
        ans = length;
        ans_st = st;
      }
      while(temp_flag == flag && st + 1 < n) {
        int length = ed - st + 1;
        if (ans > length) {
          ans = length;
          ans_st = st;
        }
        int index = get_index(s[st]);
        if (t_cnt[index] == cnt[index]) {
          temp_flag--;
        }
        t_cnt[index]--;
        st++;
      }
      int length = ed - st + 1;
      if (ans > length && temp_flag == flag) {
        ans = length;
        ans_st = st;
      }
      if (ed < st) {
        ed = st;
      }
      if (ed == n - 1) {
        break;
      }
    }
    if (ans == n + 1) return "";
    return s.substr(ans_st, ans);
  }
};


int main() {
  std::string S = "ab";
  std::string T = "b";
  printf("%s\n", Solution().minWindow(S, T).c_str());
}
