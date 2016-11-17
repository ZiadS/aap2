#include <iostream>
#include <stdio.h>
#include <math.h>
#include <gmpxx.h>
using namespace std;
int main(){
	mpz_class a, b, c;

  a = 1234;
  b = "-5678";
  c = a+b;
  cout << "sum is " << c << "\n";
  cout << "absolute value is " << abs(c) << "\n";

  cout << "just testing in visual studi" << endl;

	return 0;
}