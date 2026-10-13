#include <cstring>
#include <iostream>

bool Clear(char** n, const int& a, const int& b, const char* k, int l) {
  for (int i(0); i < 5; ++i) {
    for (int j(0); j < 10; ++j) {
      n[i][j] = ' ';
    }
  }
  return true;
}
bool Put(char** n, const int& a, const int& b, const char* k, int l) {
  if (a > 4 || a < 0 || b < 0 || b + l - 1 > 9) {
    return false;
  }
  n[a][b] = *k;
  return true;
}
bool Text(char** n, const int& a, const int& b, const char* k, int l) {
  if (a > 4 || a < 0 || b < 0 || b + l - 1 > 9) {
    return false;
  }
  for (int i(0); i < l; ++i) {
    Put(n, a, b + i, k + i, 1);
  }
  return true;
}

bool Print(char** n, const int& a, const int& b, const char* k, int l) {
  for (int i(0); i < 5; ++i) {
    for (int j(0); j < 10; ++j) {
      std::cout << n[i][j];
    }
    std::cout << std::endl;
  }
  return true;
}
int main() {
  char r0[10], r1[10], r2[10], r3[10], r4[10];
  char* table[5] = {r0, r1, r2, r3, r4};
  Clear(table, 0, 0, nullptr, 0);
  bool (*CurrentFunction[4])(char** n, const int& a, const int& b,
                             const char* k, int l) = {Clear, Put, Text, Print};
  const char name[4][32]{"сlear", "put", "text", "print"};
  const bool need_str[4]{false, true, true, false};
  char func[32];
  int a(0);
  int b(0);
  char str[32]("");
  std::cin >> func;
  while (std::strcmp(func, "quit")) {
    int index(-1);
    for (unsigned i(0); i < sizeof(name) / sizeof(name[0]); ++i) {
      if (!std::strcmp(func, name[i])) {
        index = i;
        if (need_str[i]) {
          std::cin >> a >> b >> str;
        }
        break;
      }
    }
    if (index == -1 or
        !CurrentFunction[index](table, b, a, str, std::strlen(str))) {
      std::cout << "error" << std::endl;
    }
    std::cin >> func;
  }
}