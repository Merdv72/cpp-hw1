#include <cstring>
#include <iostream>
void Deposit(int& n, const int& k) {
  if (k <= 0) {
    std::cout << "error" << std::endl;
    return;
  }
  n += k;
}

void Withdraw(int& n, const int& k) {
  if (k <= 0 || k > n) {
    std::cout << "error" << std::endl;
    return;
  }
  n -= k;
}
void Balance(int& n, const int& k) { std::cout << n << std::endl; }
void Reset(int& n, const int& k) { n = 0; }
void Inc(int& n, const int& k) { n++; }

int main() {
  void (*CurrentFunction[5])(int& n, const int& k) = {Deposit, Withdraw,
                                                      Balance, Reset, Inc};
  const char name[5][32]{"deposit", "withdraw", "balance", "reset", "inc"};
  const bool need_number[5]{true, true, false, false, false};
  char func[32];
  int n(0);
  int k(0);
  std::cin >> func;
  while (std::strcmp(func, "stop")) {
    k = 0;
    int index(-1);
    for (int i(0); i < sizeof(name) / sizeof(name[0]); ++i) {
      if (!std::strcmp(name[i], func)) {
        index = i;
        if (need_number[i]) {
          std::cin >> k;
        }
        break;
      }
    }
    if (index == -1) {
      std::cout << "error" << std::endl;
      std::cin >> func;
      continue;
    }
    CurrentFunction[index](n, k);
    std::cin >> func;
  }
  return 0;
}