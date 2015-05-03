#include <iostream>
//#include <windows.h>
#include <vector>
#include "primeSieve.h"

using namespace std;

int primeMax()
{
    int prime;
    bool primeSet = false;
    cout<<"Find all primes up to what number?"<<endl;
    cin>>prime;
    while(primeSet == false){
        if(!cin){
            cout<<"Please enter an integer between 1 and 15000"<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if(prime >= 15000){
            cout<<"Number too large"<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if(prime < 1){
            cout<<"Number too small"<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else{
            primeSet = true;
            break;
        }
        cout<<"Find all primes up to what number?"<<endl;
        cin>>prime;
    }
    return prime;
}


int main()
{
    primeSieve pS(primeMax());
    return 0;
}
