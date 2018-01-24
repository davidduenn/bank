#ifndef BANK_CLASS
#define BANK_CLASS

#include <string>
#include "member.h"


class bank {
    public:
        bank();
        ~bank();
        int add_member(string, int, char);
        int add_account(int, double, string);
        void rm_member();
        void print_bank();
        int transact(int, int, double);
        double get_balance(int, int);
        bool member_exists(int);
    private:
        class member *members;
        member* get_member(int);
        //should use a different data structure?
};

#endif

