#include <cstring>
#include <iostream>

void clear(char board[5][10]) {
  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 10; x++) {
      board[y][x] = ' ';
    }
  }
}

bool put(int x, int y, char c, char board[5][10]) {
  if (0 <= y && y <= 4 && 0 <= x && x <= 9) {
    board[y][x] = c;
    return true;
  } else {
    return false;
  }
}

bool text(int x, int y, char* word, char board[5][10]) {
  int lenght = strlen(word);
  if (y < 0 || y > 4 || x < 0 || x + lenght > 10) {
    return false;
  }
  for (int i = 0; i < lenght; i++) {
    put(x + i, y, word[i], board);
  }
  return true;
}

void print(char board[5][10]) {
  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 10; x++) {
      std::cout << board[y][x];
    }
    std::cout << '\n';
  }
}

int main() {
  char board[5][10];
  clear(board);
  char cmd[16];
  int x;
  int y;
  char c;
  char word[16];
  while (std::cin >> cmd) {
    if (strcmp(cmd, "quit") == 0) {
      break;
    } else if (strcmp(cmd, "clear") == 0) {
      clear(board);
    } else if (strcmp(cmd, "put") == 0) {
      std::cin >> x >> y >> c;
      bool ans = put(x, y, c, board);
      if (ans == false) {
        std::cout << "error\n";
      }
    } else if (strcmp(cmd, "text") == 0) {
      std::cin >> x >> y >> word;
      bool ans = text(x, y, word, board);
      if (ans == 0) {
        std::cout << "error\n";
      }
    } else if (strcmp(cmd, "print") == 0) {
      print(board);
    }
  }
  return 0;
}