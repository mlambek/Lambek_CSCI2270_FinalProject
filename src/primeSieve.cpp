#include <iostream>
#include "../include/primeSieve.h"

primeSieve::primeSieve(int m)
{
    maxNum = m;
    build();

}
void printOptions()
{
    std::cout<<"1: Check if a number is prime"<<std::endl;
    std::cout<<"2: Find the max gap between all the primes"<<std::endl;
    std::cout<<"3: print primes and multiples"<<std::endl;
    std::cout<<"4: Prime factorization"<<std::endl;
    std::cout<<"5: Quit"<<std::endl;


}
primeSieve::~primeSieve()
{
    //dtor
    bool q = true;
    int v;
    int input;
    while(q)
    {
        printOptions();
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(10000,'\n');

        switch (input)
        {
            case 1:
                std::cout<<"Insert Number: ";
                std::cin>> v;
                if(v < maxNum)
                {
                    checkPrime(v);
                }
                else{std::cout<<"Out of range";}
                std::cout<<std::endl;
                break;
            case 2:
                MaxGap();
                break;
            case 3:
                printPrime();
                break;
            case 4:
                std::cout<<"Insert Number: ";
                std::cin>> v;
                primeFactor(v);
                std::cout<<std::endl;
                break;
            case 5:
                q = false;
                break;
        }
    }
    //printPrime();
    //MaxGap();
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
void primeSieve::MaxGap()
{
    int mg = 0;
    int cg = 0;
    int gindex = 0;
    for(int i = 0; i < vTable.size(); ++i)
    {
        cg = vTable[i].value - vTable[i-1].value;
        if(cg > mg)
        {
            mg = cg;
            gindex = i;
        }
    }
    std::cout << "The max prime gap is inbetween "<<vTable[gindex - 1].value<<" and " << vTable[gindex].value<<std::endl;
}
void primeSieve::checkPrime(int p)
{
    for(int i = 0; i < vTable.size(); ++i)
    {
        if(p == vTable[i].value)
        {
            break;
        }
        if(p%vTable[i].value == 0)
        {
            std::cout<<"Not prime, multiple of: "<<vTable[i].value<<std::endl;
            return;
        }
    }
    std::cout<<p<<" Is prime"<<std::endl;
}
bool primeSieve::isprime(int p)
{
    for(int i = 1; i < vTable.size(); ++i)
    {
        if(p%vTable[i].value == 0)
        {
            //std::cout<<"Not prime, multiple of: "<<vTable[i].value<<std::endl;
            return false;
        }
    }
    return true;
}



void primeSieve::primeFactor(int num)
{
    bool t = true;
    while(t)
    {
        for(int i = 0; i < vTable.size(); ++i)
        {
            if(num % vTable[i].value == 0)
            {
                std::cout<<vTable[i].value<<", "; // fix comma for last factor
                num = num/vTable[i].value;
                //i = 1; // reset index
                break;
            }
            if(isprime(num) == true) //this might be better before if
            {
                //std::cout<<num<<std::endl;
                std::cout<<std::endl;
                t = false;
                break;
            }
        }
    }
}
