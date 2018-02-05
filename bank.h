#ifndef BANK_CLASS
#define BANK_CLASS

#include <string>
#include "member.h"

class bank {
    public:
        bank();
        ~bank();
        int add_member(string, int, char);
        bool rm_member(int);
        bool add_account(int, double, string);
        bool rm_account(int, int);
        void print_bank();
        void print_member(int);
        int transact(int, int, double);
        double get_balance(int, int);
        bool member_exists(int);
        int generate_member_id();
    private:
        class member *members;
        member* get_member(int);
};

#endif

