#include <iostream>
#include "bank.h"
#include "account.h"

using namespace std;


bank::bank() {
}


bool bank::account_exists(int account_id){
    if(accounts.empty())
        return 0;

    for(int c=0; c<accounts.size(); c++) {
        if(accounts[c].id == account_id) {
            return 1;
        }
    }
    return 0;
}


void bank::create_account() {
    account account_inst;
    cout << "Your account id is: " << account_inst.id << endl;

    string first, last;
    cout << "Give first name: ";
    cin >> first; cout << endl;
    cout << "Give last name: ";
    cin >> last; cout << endl;

    account_inst.set_name(first, last);

    accounts.push_back(account_inst);
}


void bank::print_bank() {
    if(!accounts.size()) {
        cout << "Bank is empty\n";
    }

    for(int c=0; c<accounts.size(); c++) {
        accounts[c].print_account();
    }
}


// The two below should actually be function pointers!!!
void bank::deposit(int id, double amnt) {
    for(int c=0; c<accounts.size(); c++) {
        if(accounts[c].id == id) {
            accounts[c].deposit(amnt);
        }
    }
}
/*
 * should use a different data structure?
 * custom content type instead of vector?
 */


void bank::withdraw(int id, double amnt) {
    for(int c=0; c<accounts.size(); c++) {
        if(accounts[c].id == id) {
            accounts[c].withdrawl(amnt);
        }
    }
}


double bank::get_balance(int id) {
    for(int c=0; c<accounts.size(); c++) {
        if(accounts[c].id == id) {
            return accounts[c].get_balance();
        }
    }
    cout << "You don't have an account here\n";
    return 0;
}

