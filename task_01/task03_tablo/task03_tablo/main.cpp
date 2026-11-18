#include <cstring>
#include <iostream>

bool inBounds(int x, int y) {
  return x >= 0 && x < 10 && y >= 0 && y < 5;
}

bool clear(char (&board)[5][10]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++){
      board[i][j] = ' ';
    }
  }
  return true;
}

bool print(char (&board)[5][10]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      std::cout << board[i][j];
    }
    std::cout << "\n";
  }
  return true;
}

bool put(char (&board)[5][10]) {
  int x, y;
  char c;
  std::cin >> x >> y >> c;
  if (!inBounds(x,y)) {
    return false;
  }
  board[y][x] = c;
  return true;
}

bool text(char (&board)[5][10]) {
  int x, y;
  char word[64];
  std::cin >> x >> y >> word;

  int len = (int)std::strlen(word);

  for (int i = 0; i < len; ++i) {
    if (!inBounds(x + i, y)) return false;
  }
  for (int i = 0; i < len; ++i) {
    board[y][x + i] = word[i];
  }
  return true;
}

bool (*functions[])(char (&)[5][10]) = {put, text, print, clear};
const char* names[] = {"put", "text", "print", "clear"};

int main() {
  char comand[64];
  char board[5][10];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++){
      board[i][j] = ' ';
    }
  }
  while (std::cin >> comand) {
    if (std::strcmp(comand, "quit") == 0) {
      break;
    }
    int index = -1;
    for (int i = 0; i < 4; i++) {
      if (std::strcmp(comand, names[i]) == 0) {
        index = i;
        break;
      }
    }
    if (index == -1) {
      std::cout << "error\n";
    } else if (!functions[index](board)) {
      std::cout << "error\n";
    }
  }
}
