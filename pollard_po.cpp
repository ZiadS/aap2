#include <iostream>
#include <stdio.h>
#include <math.h>
#include <gmpxx.h>
#include <random>
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
bool pollard_rho(mpz_class &n, vector<mpz_class> &primeFactors){
  //Implementera pollard_rho
  mpz_class x = 2;
  mpz_class y = 2;
  mpz_class d = 1;
  mpz_class tmp;
  mpz_class toAbs;
  //cout << "inne" << endl;
  while(d == 1){
    x = ((x*x) + 1) % n;
    y = (((((y*y) + 1) % n)*((y*y) + 1) % n) + 1) % n;
    toAbs = x - y;
    tmp = abs(toAbs);
    mpz_gcd(d.get_mpz_t(), tmp.get_mpz_t(), n.get_mpz_t());
  }
  if(d == n){
    return false;
  }else{
    if(isPrime(d)){
      primeFactors.push_back(d);
      n = n/d;
    }else{
      primeFactors.push_back(n/d);
      n = d;

    }
    cout << "sending though " << n << endl;
    return true;
  }
}

void getPrimes(vector<mpz_class> &primes){
	mpz_class i = 0;
  mpz_class p;
  mpz_class tmp = 1;
  for(i = 1; i < 200000; ++i){
		mpz_nextprime(p.get_mpz_t(), tmp.get_mpz_t());
    tmp = p;
    primes.push_back(p);
		}
	}

void trialDivision(mpz_class n, vector<mpz_class> &primes, vector<mpz_class> &primeFactors){
	int i = 0;
	mpz_class rootN;
	n.get_mpz_t();
	rootN.get_mpz_t();
	rootN = sqrt(n);
	while(i < primes.size()){
			cout << "testing  " << primes[i] << " on " << n << endl;
			if(isPrime(n)){
				break;
			}
			if(mpz_cmp(primes[i].get_mpz_t(), rootN.get_mpz_t()) > 0){ //Because we dont need to go further
				break;
			}
			if(mpz_divisible_p(n.get_mpz_t(), primes[i].get_mpz_t()) != 0){
				primeFactors.push_back(primes[i]);
				n = n/primes[i];
			}else{
				i++;
			}
		}
		if(n > 1 && isPrime(n)){
			primeFactors.push_back(n);
		}else{
        primeFactors.clear();
      }
}
int main(){
	vector<mpz_class> primes;
	vector<mpz_class> primeFactors;
	getPrimes(primes);
	mpz_class n;
	while(cin >> n){
    primeFactors.clear();
		n.get_mpz_t();
		if(isPrime(n)){ //Is prime just print
			cout << n << endl;
		}else{ //Try to factor
      pollard_rho(n, primeFactors);
    //  cout <<"found: "<< n << endl;
      trialDivision(n, primes, primeFactors);




      if(!primeFactors.empty()){
			for(int i = 0; i < primeFactors.size(); ++i){
				cout << primeFactors[i] << endl;
			}
		}else{
			cout << "fail" << endl;
		}
     //Forsätt med sista talet från trialDivsion och kolla om det är prime
      //Om inte så ska vi köra pollard rho på det

		}
		cout << endl;
	}
	return 0;
}
