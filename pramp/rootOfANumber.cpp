//In this question we’ll implement a function root that calculates the n’th
//root of a number. The function takes a nonnegative number x and a positive integer n,
//and returns the positive n’th root of x within an error of 0.001

include <iostream>
using namespace std;

double multiplyNTimes(double val, int n){
  if(n == 0) return 0;
  double ans = val; n--;
  for(int i = 0; i < n; i++)
    ans *= val;
  return ans;
}
double root(double x, unsigned int n){
  if(x == 0 || n == 0) return 0;
  
  double left = 0, right = x;
  double error = 0.001;
  
  while(right - left >= error){
    double middle = left + ((right-left)/2);
    double ans = multiplyNTimes(middle,n);
    if(ans >= x)
      right = middle;
    else
      left = middle;
  }
  
  return left + ((right-left)/2);
  
}

int main() {
  return 0;
}