#ifndef BANK_CLASS
#define BANK_CLASS

#include <vector>
#include "account.h"


class bank {
    public:
        bank();
        bool account_exists(int);
        void create_account();
        void print_bank();
        void transact(int, double);
        double get_balance(int);

    private:
        vector<account> accounts;
        //should use a different data structure?
        //custom content type instead of vector?
};

#endif

