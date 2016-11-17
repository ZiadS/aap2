#include <iostream>
#include <stdio.h>
#include <math.h>
#include <gmpxx.h>
#include <vector>
using namespace std;

void trialDivision(mpz_class &n, vector<mpz_class> &primeFactors){
	mpz_class rootN;
	n.get_mpz_t();
	rootN.get_mpz_t();
	rootN = sqrt(n);
	int i = 2;
	while(i < rootN){
			if(n % i == 0){
				cout << i << endl;
				n = n/i;
			}else{
				i++;
			}
		}
		if(n > 1){
			cout << n << endl;
		}
}

int main(){
	vector<mpz_class> primeFactors;
	vector<mpz_class> numberInput;
	mpz_class n;
	mpz_class max = pow(10,16);
	while(cin >> n){
		if(n < 2){
			cout << n << endl;
		}else if(mpz_cmp(n.get_mpz_t(),max.get_mpz_t()) >= 0){
			cout << "fail" << endl;
		}else{
			mpz_class tmp = n;
			//primeFactors.erase(primeFactors.begin(), primeFactors.end());
			trialDivision(tmp, primeFactors);
		}
		cout << endl;
	}
	return 0;
}
