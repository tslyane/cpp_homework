#include <iomanip>
#include <iostream>

#include "weather.h"

int main() {
  int size;
  std::cin >> size;
  int* temp = new int[size];
  for (int i = 0; i < size; i++) {
    std::cin >> temp[i];
  }
  int min_value;
  int max_value;
  double add_temp = AddTemperature(size, temp);
  MinAndMax(size, temp, min_value, max_value);
  int less_0 = LessThan0(size, temp);
  std::cout << std::fixed << std::setprecision(1) << add_temp << '\n';
  std::cout << min_value << ' ' << max_value << '\n';
  std::cout << less_0 << '\n';
  delete[] temp;
  return 0;
}