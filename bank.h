#ifndef BANK_CLASS
#define BANK_CLASS

#include <string>
#include "member.h"


class bank {
    public:
        bank();
        //bool account_exists(int);
        int add_member(string, int, char);
        int add_account(int, double, string);
        void rm_account();
        void print_bank();
        int transact(int, int, double);
        double get_balance(int, int);
    private:
        class member *members;
        member* get_member(int);
        //should use a different data structure?
};

#endif

