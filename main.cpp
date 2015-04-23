#include <iostream>
#include <windows.h>
#include <vector>
#include "primeSieve.h"

using namespace std;

int primeMax()
{
    string prime;
    cout<<"Find all primes up to what number?"<<endl;
    cin>>prime;

    return atoi(prime.c_str());
}


int main()
{
    primeSieve pS(primeMax());

    pS.printPrime();

    return 0;
}
