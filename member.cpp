#include <iostream>
#include <stdlib.h> // rand
#include "member.h"

#define MAX_NUM_ACCOUNTS 9000

using namespace std;


void member::print_member() {
  cout << "-----" << endl;
  cout << "Name: " << name << endl;
  cout << "Age: " << age << " Y.O." << endl;
  cout << "Member ID: " << id << endl;
  if(this->accounts == nullptr) {
    cout << "No accounts" << endl;
  } else {
    // loop through and print accounts
    account *account_iterator = nullptr;
    do {
      this->accounts->print_account(currency);
      account_iterator = this->accounts->next;
    } while(account_iterator != nullptr);
  }
}

void member::add_account(double balance, string name) {
  if(this->accounts == nullptr) {
    // if this is the first account
    account *new_account = new account(0, balance, name);
    this->accounts = new_account;
  } else {
    // if non-first account
    account *account_iterator = this->accounts;
    while(account_iterator->next != nullptr) {
      account_iterator = account_iterator->next;
    }
    // put on end of linked list
    int new_account_id = account_iterator->get_id()+1;
    account *new_account = new account(new_account_id, balance, name);
    account_iterator->next = new_account;
  }
}

void member::rm_account() {
  // delete account
}

member::member(string name="", int age=0, char currency='$') {
  id = 1000 + rand() %MAX_NUM_ACCOUNTS;
  // To-Do: only set id if it's not already in use
  this->name = name;
  this->age = age;
  this->currency = currency;
  this->accounts = nullptr;
  this->next_member = nullptr;
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
