#ifndef ACCOUNT
#define ACCOUNT

#include <string>
using namespace std;

class account {
    public:
        int id;
        string first_name;
        string last_name;

        account(string first, string last);
        int transact(double);
        void print_account();
        void set_name(string, string);
        double get_balance();

    private:
        double balance;
};

#endif

