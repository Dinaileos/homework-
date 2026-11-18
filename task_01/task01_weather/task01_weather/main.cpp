#include <iomanip>
#include <iostream>

double Mean(const int* temp, int count) {
  long long sum = 0;
  for (int i = 0; i < count; ++i) {
    sum += temp[i];
  }
  return static_cast<double>(sum) / count;
}

int MinTemp(const int* temp, int count) {
  int ans = temp[0];
  for (int i = 1; i < count; ++i) {
    if (temp[i] < ans) {
      ans = temp[i];
    }
  }
  return ans;
}

int MaxTemp(const int* temp, int count) {
  int ans = temp[0];
  for (int i = 1; i < count; ++i) {
    if (temp[i] > ans) {
      ans = temp[i];
    }
  }
  return ans;
}

int CountFrostyDays(const int* temp, int count) {
  int ans = 0;
  for (int i = 0; i < count; ++i) {
    if (temp[i] < 0) {
      ++ans;
    }
  }
  return ans;
}

int main() {
  int count;
  std::cin >> count;

  int* temp = new int[count];
  for (int i = 0; i < count; ++i) {
    std::cin >> temp[i];
  }

  std::cout << std::fixed << std::setprecision(1) << Mean(temp, count) << '\n';
  std::cout << MinTemp(temp, count) << ' ' << MaxTemp(temp, count) << '\n';
  std::cout << CountFrostyDays(temp, count) << '\n';

  delete[] temp;
}
