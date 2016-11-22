#include <iostream>
#include <stdio.h>
#include <math.h>
#include <gmpxx.h>
#include <random>
#include <vector>
#include <time.h>
using namespace std;


bool isPrime(mpz_class &x){
	if(mpz_probab_prime_p(x.get_mpz_t(), 100) > 0){
		return true;
	}else{
		return false;
	}
}
bool pollard_rho(mpz_class &d, mpz_class n, vector<mpz_class> &primeFactors){

  mpz_class x = 2;
  mpz_class y = 2;
  mpz_class tmp;
  mpz_class toAbs;
  int itr = 200000;
  while(d == 1 && itr != 0){
    x = (((x*x) + 1) % n);
    y = ((((y*y) + 1) % n)*(((y*y) + 1) % n) + 1) % n;
  //  cout << "x " << x << " y " << y << endl;
    toAbs = x - y;
    tmp = abs(toAbs);
    mpz_gcd(d.get_mpz_t(), tmp.get_mpz_t(), n.get_mpz_t());
    itr--;
  }
  if(itr == 0 && d == 1){
    return false;
  }
  if(d == n){
    return false;
  }else{
    return true;
  }
}
bool pollard_algorithm(mpz_class d, mpz_class n, vector<mpz_class> &primeFactors){
  d = 1;
  if(pollard_rho(d, n, primeFactors)){
    mpz_class tmp = n/d;
    if(isPrime(d) && isPrime(tmp)){ // If both d & n is primes, we're done
      primeFactors.push_back(d);
      primeFactors.push_back(tmp);
      return true;
    }else if(isPrime(d) && !isPrime(tmp)){ //If tmp is not prime check if we can factor d more
      primeFactors.push_back(d);
      if(!pollard_algorithm(d, tmp, primeFactors)){
        return false;
      }
    }else if(!isPrime(d) && isPrime(tmp)){ //If d is not prime check if we can factor tmp more
      primeFactors.push_back(tmp);
      if(!pollard_algorithm(d, d, primeFactors)){
        return false;
      }
    }else{ //If none of them are primes
      if(!pollard_algorithm(d, tmp, primeFactors)){
        return false;
      }
      if(!pollard_algorithm(d, d, primeFactors)){
        return false;
      }
    }
  }else{
    return false;
  }
  return true;

}
void getPrimes(vector<mpz_class> &primes){
	mpz_class i = 0;
  mpz_class p;
  mpz_class tmp = 1;
  for(i = 1; i < 20000; ++i){
		mpz_nextprime(p.get_mpz_t(), tmp.get_mpz_t());
    tmp = p;
    primes.push_back(p);
		}
	}

bool trialDivision(mpz_class &n, vector<mpz_class> &primes, vector<mpz_class> &primeFactors){
	int i = 0;
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
				primeFactors.push_back(primes[i]);
				n = n/primes[i];
			}else{
				i++;
			}
		}
		if(n > 1 && isPrime(n)){
      primeFactors.push_back(n);
      return true;
		}else{
        return false;
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
      if(trialDivision(n, primes, primeFactors)){
        for(int i = 0; i < primeFactors.size(); ++i){
  				cout << primeFactors[i] << endl;
  			}
      }else{
        if(pollard_algorithm(1, n, primeFactors)){

          for(int i = 0; i < primeFactors.size(); ++i){
            cout << primeFactors[i] << endl;
          }
        }else{
          cout << "fail" << endl;
        }
      }
		}
		cout << endl;
	}
	return 0;
}
