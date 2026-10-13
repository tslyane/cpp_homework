#include <cstring>
#include <iostream>

void deposit(int& sum, int remitt) {
  if (remitt <= 0) {
    std::cout << "error" << '\n';
    return;
  }
  sum = sum + remitt;
}

void withdraw(int& sum, int remitt) {
  if (remitt <= 0 || sum < remitt) {
    std::cout << "error" << '\n';
    return;
  }
  sum = sum - remitt;
}

void balance(int& sum, int remitt) { std::cout << sum << '\n'; }

void reset(int& sum, int remitt) { sum = 0; }

void double_sum(int& sum, int remitt) { sum = sum * 2; }

struct Command {
  const char* name;
  void (*func)(int&, int);
};

int main() {
  int sum = 0;

  Command table[] = {{"deposit", deposit},
                     {"withdraw", withdraw},
                     {"balance", balance},
                     {"reset", reset},
                     {"double", double_sum}};

  char cmd[16];

  while (std::cin >> cmd) {
    if (strcmp(cmd, "stop") == 0) {
      break;
    }
    int remitt = 0;
    if (strcmp(cmd, "deposit") == 0 || strcmp(cmd, "withdraw") == 0) {
      std::cin >> remitt;
    }
    bool found = false;
    for (int i = 0; i < 5; i++) {
      if (strcmp(table[i].name, cmd) == 0) {
        table[i].func(sum, remitt);
        found = true;
        break;
      }
    }
    if (found == false) {
      std::cout << "error" << '\n';
    }
  }
}
