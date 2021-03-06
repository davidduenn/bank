#include <iostream>
#include "account.h"

using namespace std;


account::account(int account_id, double balance, string name) {
  this->id = account_id;
  this->balance = balance;
  this->name = name;
  this->next = nullptr;
}


account::~account() {
}


int account::transact(double amount) {
    double new_balance = balance+amount;
    if(new_balance>=0) {
        balance = new_balance;
        return 1;
    }
    else {
        cout << "Failure. Not enough funds to make withdrawl." << endl;
        return 0;
    }
}


void account::print_account(char currency) {
  cout << "  ---\n";
  cout << "  id:        " << this->id << endl;
  cout << "  name:      " << this->name << endl;
  cout << "  balance:   " << currency << this->balance << endl;
}


double account::get_balance() {
    return balance;
}


int account::get_id() {
  return id;
}
