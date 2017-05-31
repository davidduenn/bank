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
    string first, last;
    cout << "Give first name: ";
    cin >> first; cout << endl;
    cout << "Give last name: ";
    cin >> last; cout << endl;

    account account_inst(first,last);

    cout << "Your account id is: " << account_inst.id << endl;

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


void bank::transact(int id, double amnt) {
    for(int c=0; c<accounts.size(); c++) {
        if(accounts[c].id == id) {
            accounts[c].transact(amnt);
        }
    }
}


double bank::get_balance(int id) {
    for(int c=0; c<accounts.size(); c++) {
        if(accounts[c].id == id) {
            return accounts[c].get_balance();
        }
    }
    return 0;
}

