#include <iostream>
#include <stdlib.h> // rand
#include "member.h"

#define MAX_NUM_ACCOUNTS 9000

using namespace std;


void member::print_member() {
  cout << "Name: " << name << endl;
  cout << "Age: " << age << " Y.O." << endl;
  cout << "Balance: " << currency << "XYZ" << endl;
}

member::member(string name="", int age=0, char currency='$') {
  id = 1000 + rand() %MAX_NUM_ACCOUNTS;
  // To-Do: only set id if it's not already in use
  name = name;
  age = age;
  currency = currency;
  accounts = nullptr;
}

int member::get_id() {
  return id;
}

int member::transact(int account_id, double amnt) {
  account *account_ptr = this->accounts;
  while(account_ptr != nullptr) {
    if(account_ptr->get_id() == account_id) {
      account_ptr->transact(amnt);
      return 0;
    } else {
      account_ptr = account_ptr->next;
    }
  }
  cout << "Failed. Account not found" << endl;
  return 1;
}

double member::get_balance(int account_id) {
  account *account_ptr = this->accounts;
  while(account_ptr != nullptr) {
    if(account_ptr->get_id() == account_id) {
      return account_ptr->get_balance();
    } else {
      account_ptr = account_ptr->next;
    }
  }
  cout << "Failed. Account not found" << endl;
  return 1;
}

// todo transact and get_balance are mostly 
// the same code. Pull common code to a 
// function
