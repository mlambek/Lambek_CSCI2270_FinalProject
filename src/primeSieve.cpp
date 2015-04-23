#include <iostream>
#include "primeSieve.h"

primeSieve::primeSieve(int m)
{
    maxNum = m;
    build();

}

primeSieve::~primeSieve()
{
    //dtor
    printPrime();
}

void primeSieve::build()
{
    //start with 2 counters
    int curNum = 2; //for current number you are investigating
    int vPlace = 0; //for the place in the array
    bool found;

    //loop until all numbers needed are found
    while(curNum <= maxNum)
    {
        if(!vSearch(curNum)){
            prime s;
            s.value = curNum;
            vTable.push_back(s);
            for(int i = 0; i < maxNum/curNum; ++i)
            {
                if(!vSearch((i+1)*curNum))
                    vTable[vPlace].mInt.push_back((i+1)*curNum);
            }
            ++vPlace;
        }
        ++curNum;
    }
}

bool primeSieve::vSearch(int v)
{
    //find out if the current number already exists in the table
    for(int i = 0; i < vTable.size(); ++i)
    {
        for(int j = 0; j < vTable[i].mInt.size(); ++j)
        {
            if(vTable[i].mInt[j] == v)
                return true;
        }
    }
    return false;
}

void primeSieve::printPrime()
{
    std::cout << "Primes |   Multiples"<<std::endl;
    std::cout << 1 << std::endl;
    for(int i = 0; i < vTable.size(); ++i){
        std::cout << vTable[i].value << ": " << vTable[i].mInt[0];
        for(int j = 1; j < vTable[i].mInt.size(); ++j)
            std::cout << ", " << vTable[i].mInt[j];

        std::cout<<std::endl;
    }

    std::cout<<std::endl;
}
