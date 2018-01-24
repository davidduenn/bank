#ifndef ACCOUNT
#define ACCOUNT

#include <string>
using namespace std;

class account {
    public:
        account(int, double, string);
        ~account();
        int transact(double);
        void print_account(char);
        double get_balance();
        int get_id();
        account* next;
    private:
        double balance;
        int id;
        string name;
};
// Have a super class and have it inherit
// down to the checking or savings account?

#endif

