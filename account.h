#ifndef ACCOUNT
#define ACCOUNT

#include <string>
using namespace std;

class account {
    public:
        int id;
        string first_name;
        string last_name;

        account();
        void deposit(double);
        int withdrawl(double);
        void print_account();
        void set_name(string, string);
        double get_balance();

    private:
        double balance;
};

#endif

