#include <iostream>
#include <stdlib.h>
#include "account.h"

#define NUM_ACCOUNTS 100

using namespace std;


account::account() {
    balance = 0;
    id = rand() %NUM_ACCOUNTS + 1000;
    first_name = "first";
    last_name = "last";
}


void account::deposit(double amount) {
    balance = balance + amount;
}


int account::withdrawl(double amount) {
    if(balance>amount) {
        balance = balance-amount;
        cout << "Transaction successful\n";
        return 0;
    }
    else {
        cout << "Not enough money to complete transaction\n";
        return 1;
    }
}


void account::print_account() {
    cout << "----------\n";
    cout << "id:        " << this->id << endl;
    cout << "full name: " << this->first_name << " " << this->last_name << endl;
    cout << "balance:   " << this->balance << endl;
    cout << "----------\n";
}


void account::set_name(string first, string last) {
    first_name = first;
    last_name = last;
}

double account::get_balance() {
    return balance;
}

