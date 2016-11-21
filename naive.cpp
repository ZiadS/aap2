#include <iostream>
#include <stdio.h>
#include <math.h>
#include <gmpxx.h>
#include <vector>
#include <time.h>
using namespace std;

bool isPrime(mpz_class &x){
	if(mpz_probab_prime_p(x.get_mpz_t(), 2) > 0){
		return true;
	}else{
		return false;
	}
}
void getPrimes(vector<mpz_class> &primes){
	mpz_class p = 2;
	int max = 1000000;
	for(int k = 0; k < max; ++k){
		if(isPrime(p)){
			primes.push_back(p);
	//		cout << "pushed " << i << endl;
		}
		++p;
	}
}

vector<mpz_class> trialDivision(mpz_class n, vector<mpz_class> &primes){
	int i = 0;
	vector<mpz_class> v;
	mpz_class rootN;
	n.get_mpz_t();
	rootN.get_mpz_t();
	rootN = sqrt(n);
	while(i < primes.size()){
	//		cout << "testing  " << primes[i] << " on " << n << endl;
			if(isPrime(n)){
				break;
			}
			if(mpz_cmp(primes[i].get_mpz_t(), rootN.get_mpz_t()) > 0){ //Because we dont need to go further
				break;
			}
			if(mpz_divisible_p(n.get_mpz_t(), primes[i].get_mpz_t()) != 0){
				v.push_back(primes[i]);
				n = n/primes[i];

			}else{
				i++;
			}
		}
		if(n > 1 && isPrime(n)){
			v.push_back(n);
			return v;
		}else{
			v.clear();
			return v;
		}
}
int main(){
	vector<mpz_class> primes;
	vector<mpz_class> primeFactors;
	getPrimes(primes);
//	cout << "biggest prime: " << primes.size() << endl;
	mpz_class n;
	while(cin >> n){
//		n.get_mpz_t();
		if(isPrime(n)){ //Is prime just print
			cout << n << endl;
		}else{ //Try to factor
			primeFactors = trialDivision(n, primes);
			if(!primeFactors.empty()){
			for(int i = 0; i < primeFactors.size(); ++i){
				cout << primeFactors[i] << endl;
			}
		}else{
			cout << "fail" << endl;
		}

		}
		cout << endl;
	}
	return 0;
}
