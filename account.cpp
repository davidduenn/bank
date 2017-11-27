#include <iostream>
#include <stdlib.h> // rand
#include "account.h"
#include <time.h> // time

#define MAX_NUM_ACCOUNTS 9000

using namespace std;


account::account(string first, string last) {
    balance = 0;
    id = 1000 + rand() %MAX_NUM_ACCOUNTS;
    // To-Do: only set id if it's not already in use
    first_name = first;
    last_name = last;
}


int account::transact(double amount) {
    if(balance+amount>=0) {
        balance = balance + amount;
        return 0;
    }
    else {
	cout << "Not enough funds to make withdrawl. Cancelled." << endl;
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

