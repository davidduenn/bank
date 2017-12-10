#ifndef BANK_CLASS
#define BANK_CLASS

#include <string>
#include "member.h"


class bank {
    public:
        bank();
        //bool account_exists(int);
        int create_member(string, int, char);
        void print_bank();
        int transact(int, int, double);
        double get_balance(int, int);
    private:
        class member *members;
        //should use a different data structure?
};

#endif

