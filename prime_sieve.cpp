#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

const long long MAX =100000000;

vector <long long>primes;
vector < bool > isprime(MAX,false);

void sieve()
{
    isprime[1] = true;
    primes.push_back(0);
    primes.push_back(2);

    for(long long i = 4;i<= MAX ;i+=2 )
        isprime[i] = true;

    for(long long i=3;i<= sqrt(MAX) ;i += 2){

        if( !isprime[i]){
            for(long long j = i*i ; j<= MAX ;j = j+2*i){
                isprime[j] = true;
            }

            primes.push_back(i);
        }
    }

}
void print_primes(int n)
{
    for(int i=1;i<=n;i++){
        cout<<"Prime"<<"["<<i<<"] = "<<primes[i]<<endl;
    }
}

bool Cheak_prime(long long n)
{
    if(isprime[n])
        return false;
    else
        return true;
}

int main()
{
    time_t t1= clock();
    sieve();
    time_t t2= clock();
    cout<<primes.size()<<endl;
    cout<<"time taken "<<(t2-t1)/double(CLOCKS_PER_SEC)<<endl;

    int n;
    cin>>n;
    cout<<(Cheak_prime(n) == 1 ? "Prime" : "Not prime") <<endl;


    return 0;
}
