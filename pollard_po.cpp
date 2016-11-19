#include <iostream>
#include <stdio.h>
#include <math.h>
#include <gmpxx.h>
#include <random>
#include <vector>
#include <time.h>
using namespace std;

bool pollard_rho(mpz_class &n, vector<mpz_class> &primeFactors){
  //Implementera pollard_rho
}

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <gmpxx.h>
#include <vector>
#include <time.h>
using namespace std;

bool isPrime(mpz_class &x){
	if(mpz_probab_prime_p(x.get_mpz_t(), 5) > 0){
		return true;
	}else{
		return false;
	}
}
void getPrimes(vector<mpz_class> &primes){
	mpz_class i = 2;
	while(primes.size() < 10000){
		if(isPrime(i)){
			primes.push_back(i);
	//		cout << "pushed " << i << endl;
		}
		i++;
	}
}

vector<mpz_class> trialDivision(mpz_class &n, vector<mpz_class> &primes){
	int i = 0;
	vector<mpz_class> v;
	mpz_class rootN;
	n.get_mpz_t();
	rootN.get_mpz_t();
	rootN = sqrt(n);
	while(i < primes.size()){
	//		cout << "testing  " << primes[i] << " on " << n << endl;
			if(primes[i] > rootN){ //Because we dont need to go further
				break;
			}
			if(n % primes[i] == 0){
				v.push_back(primes[i]);
				n = n/primes[i];
			}else{
				i++;
			}
		}
		if(n > 1){
      v.push_back(n);
    }
		return v;
}
int main(){
	vector<mpz_class> primes;
	vector<mpz_class> primeFactors;
	getPrimes(primes);
	mpz_class n;
	while(cin >> n){
		n.get_mpz_t();
		if(isPrime(n)){ //Is prime just print
			cout << n << endl;
		}else{ //Try to factor
      bool morePrimes = true;
			primeFactors = trialDivision(n, primes);

      //Forsätt med sista talet från trialDivsion och kolla om det är prime
      //Om inte så ska vi köra pollard rho på det

		}
		cout << endl;
	}
	return 0;
}
