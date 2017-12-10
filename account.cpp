#include <iostream>
#include "account.h"

using namespace std;


account::account(double balance = 0, string name = "") {
    balance = balance;
    name = name;
}


int account::transact(double amount) {
    double new_balance = balance+amount;
    if(new_balance>=0) {
        balance = new_balance;
        return 0;
    }
    else {
        cout << "Failed. Not enough funds to make withdrawl." << endl;
        return 1;
    }
}


void account::print_account() {
    cout << "----------\n";
    /*
    cout << "id:        " << this->id << endl;
    cout << "full name: " << this->first_name << " " << this->last_name << endl;
    cout << "balance:   " << this->balance << endl;
    */
    cout << "----------\n";
}


double account::get_balance() {
    return balance;
}


int account::get_id() {
  return id;
}
