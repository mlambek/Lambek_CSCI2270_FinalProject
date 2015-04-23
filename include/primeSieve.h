#ifndef PRIMESIEVE_H
#define PRIMESIEVE_H
#include <vector>

struct prime
{
    int value;
    std::vector<int> mInt;
};

class primeSieve
{
    public:
        primeSieve(int);
        virtual ~primeSieve();
        void build();
        void iInsert(int);
        bool vSearch(int);
        void printPrime();

    protected:
    private:
        int maxNum;
        std::vector<prime> vTable;

};

#endif // PRIMESIEVE_H
