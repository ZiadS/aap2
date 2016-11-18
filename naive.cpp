#include <iostream>
#include <stdio.h>
#include <math.h>
#include <gmpxx.h>
#include <vector>
#include <time.h>
using namespace std;

void getPrimes(vector<mpz_class> &primes, mpz_class &n){
	mpz_class rootN;
	n.get_mpz_t();
	rootN.get_mpz_t();
	rootN = sqrt(n);
		cout << "root is " << rootN << endl;
	for(mpz_class i = 0; i <= rootN; i++){

		if(mpz_probab_prime_p(i.get_mpz_t(), 50) > 0){
			primes.push_back(i);
			cout << "pushed " << i << endl;
		}
	}
}
void trialDivision(mpz_class &n, vector<mpz_class> &primes){
	int i = 0;

	while(i < primes.size()){
		cout << "index: " << i << " testing " << primes[i] << " on " << n << endl;
			if(n % primes[i] == 0){
				cout << primes[i] << endl;
				n = n/primes[i];
			}else{
				i++;
			}
		}
		if(n > 1){
			cout << n << endl;
		}
}
int main(){
	vector<mpz_class> primes;
	vector<mpz_class> numberInput;
	mpz_class n;
	mpz_class max = 10000000000;
	while(cin >> n){
		numberInput.push_back(n);
	}
for(int i = 0; i < numberInput.size(); ++i){
	n = numberInput[i];
	if(mpz_cmp(n.get_mpz_t(), max.get_mpz_t()) > 0){
		cout << "fail" << endl;
	}else if(n >= 2){
		mpz_class tmp = n;
		getPrimes(primes, tmp);
		trialDivision(tmp, primes);
		primes.erase(primes.begin(), primes.end());
	}
	cout << endl;
	}
	return 0;
}
