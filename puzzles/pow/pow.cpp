#include <iostream>
using namespace std;

double pow(double x, int n);
double powRecursive(double x, int n);
double powIterative(double x, int n);

#define POW(x, y) powIterative(x, y)

int main() {
  cout << POW(2,8) << endl;
  cout << POW(2, 0) << endl;
  cout << POW(2, -2) << endl;
}

// Simple solution
double pow(double x, int n) {
  double returnVal = 1;
  if (n != 0) {
    for (int i = 0; i < abs(n); i++) {
      returnVal = n > 0 ? returnVal * x : returnVal / x;
    }
  }
  return returnVal;   
}

// Recursive solution
double powRecursive(double x, int n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    return x;
  }
  if (n > 1) {
    if (n % 2 == 0) {
      return pow(x, n/2) * pow(x, n/2);
    }
    else {
      return pow(x, n/2) * pow(x, n/2) * x;
    }
  }
  else {
    uint absN = abs(n);
    if (absN % 2 == 0) {
      return (1 / (pow(x, absN/2) * pow(x, absN/2)));
    }
    else {
      return (1 / (pow(x, absN/2) * pow(x, absN/2) * x));
    }
  }
}

// Lograithmic Iterative solution
double powIterative(double x, int n) {
  long long N = n;
  if (N < 0) {
    N = -N;
    x = 1/x;
  }

  double answer = 1;
  double product = x;
  for (long long i = N; i; i /= 2) {
    if (i % 2 == 1) {
      answer *= product;
    }
    product *= product;
  }
  return answer;
}
