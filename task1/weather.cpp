#include "weather.h"
double AddTemperature(int size, const int* temp) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += temp[i];
  }
  double answer = sum * 1.0 / size;
  return answer;
}

void MinAndMax(int size, const int* temp, int& min_val, int& max_val) {
  int count = 0;
  min_val = temp[0];
  max_val = temp[0];
  while (count < size) {
    if (min_val > temp[count]) {
      min_val = temp[count];
    }
    if (max_val < temp[count]) {
      max_val = temp[count];
    }
    count++;
  }
}

int LessThan0(int size, const int* temp) {
  int answer = 0;
  for (int i = 0; i < size; i++) {
    if (temp[i] < 0) {
      answer++;
    }
  }
  return answer;
}