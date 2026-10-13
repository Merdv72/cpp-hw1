#include <iomanip>
#include <iostream>

double AverageTemperature(const int* arr, const int& n) {
  double av{0};
  for (int i(0); i < n; ++i) {
    av += arr[i];
  }
  av /= n;
  return av;
}

int* MaxMinTemperature(const int* arr, const int& n) {
  int* ans = new int[2]{arr[0], arr[0]};
  for (int i(1); i < n; ++i) {
    if (arr[i] < ans[0]) {
      ans[0] = arr[i];
    }
    if (ans[1] < arr[i]) {
      ans[1] = arr[i];
    }
  }
  return ans;
}

int DaysBelowZero(const int* arr, const int& n) {
  int cnt{0};
  for (int i(0); i < n; ++i) {
    if (arr[i] < 0) {
      ++cnt;
    }
  }
  return cnt;
}

int main() {
  int n;
  std::cin >> n;
  int* temperature = new int[n];
  for (int i(0); i < n; ++i) {
    std::cin >> temperature[i];
  }
  std::cout << std::fixed << std::setprecision(1)
            << AverageTemperature(temperature, n) << std::endl;
  int* boundries = MaxMinTemperature(temperature, n);
  std::cout << *boundries << ' ' << *(boundries + 1) << std::endl;
  std::cout << DaysBelowZero(temperature, n) << std::endl;
  delete[] temperature;
  delete[] boundries;
  return 0;
}