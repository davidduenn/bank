#ifndef BANK_CLASS
#define BANK_CLASS

#include <string>
#include <vector>
#include "account.h"


class bank {
    public:
        bank();
        bool account_exists(int);
        int create_account(string, string);
        void print_bank();
        int transact(int, double);
        double get_balance(int);

    private:
        vector<account> accounts;
        //should use a different data structure?
        //custom content type instead of vector?
};

#endif

