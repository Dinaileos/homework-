#include <cstring>
#include <iostream>

void deposit(long long& balance) {
  long long count;
  std::cin >> count;
  if (count <= 0) {
    std::cout << "error\n";
    return;
  }
  balance += count;
}

void withdraw(long long& balance) {
  long long count;
  std::cin >> count;
  if (count <= 0) {
    std::cout << "error\n";
    return;
  }
  if (count > balance) {
    std::cout << "error\n";
    return;
  }
  balance -= count;
}

void printBalance(long long& balance) {
  std::cout << balance << '\n';
}

void reset(long long& balance) {
  balance = 0;
}

// новая команда: Surprise — может сделать баланс как огромным тк и 0
void Surprise(long long& balance) {
  balance = (balance % 10) * 1000;
}

void (*functions[])(long long&) = {deposit, withdraw, printBalance, reset, Surprise};
const char* names[] = {"deposit", "withdraw", "balance", "reset", "double"};
const int kCount = 5;
int main() {
  long long balance = 0;
  char cmd[64];
  while (std::cin >> cmd) {
    if (std::strcmp(cmd, "stop") == 0) {
      break;
    }
    int index = -1;
    for (int i = 0; i < kCount; ++i) {
      if (std::strcmp(cmd, names[i]) == 0) {
        index = i;
        break;
      }
    }
    if (index == -1) {
      std::cout << "error\n";
    } else {
      functions[index](balance);
    }
  }
}
