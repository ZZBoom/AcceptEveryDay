#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> flag_strings{"Danil", "Olya", "Slava", "Ann",
                                        "Nikita"};
  std::string input;
  while (std::cin >> input) {
    int flag = 0;
    for (auto item : flag_strings) {
      if (input.find(item) != std::string::npos) {
        flag++;
        if (input.find(item) != input.rfind(item)) {
          flag++;
        }
      }
    }
    if (flag == 1) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
