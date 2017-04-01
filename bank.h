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
        // Two below should actully be function pointers!!!
        void deposit(int, double);
        void withdraw(int, double);
        double get_balance(int);

    private:
        vector<account> accounts;
};

#endif

