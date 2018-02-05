#include <iostream>
#include "member.h"

using namespace std;


member::member(string name="", int age=0, char currency='$', int id=0) {
  this->name = name;
  this->age = age;
  this->currency = currency;
  this->id = id;
  this->accounts = nullptr;
  this->next = nullptr;
}


member::~member() {
  account *account_iterator = this->accounts;
  while(account_iterator) {
    // run through accounts and delete them
    account *target_account = account_iterator;
    account_iterator = account_iterator->next;
    delete target_account;
  }
}


void member::print_member() {
  cout << "-----" << endl;
  cout << "Name: " << name << endl;
  cout << "Age: " << age << " Y.O." << endl;
  cout << "Member ID: " << id << endl;
  if(this->accounts == nullptr) {
    cout << "No accounts" << endl;
  } else {
    account *account_iterator = this->accounts;
    while(account_iterator != nullptr) {
      // loop through and print accounts
      account_iterator->print_account(currency);
      account_iterator = account_iterator->next;
    }
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


bool member::rm_account(int id) {
  if(!this->accounts) {
    // fail if account linked list is empty
    return 0;
  }
  if(this->accounts->get_id() == id) {
    // if the first account is our target
    // take it out of the linked list and delete it
    account *target_account = this->accounts;
    this->accounts = this->accounts->next;
    delete target_account;
    return 1;
  } else {
    // if non-empty and target is not first one
    account *prev_account = this->accounts;
    account *account_iterator = this->accounts->next;
    while(account_iterator) {
      // iterate through accounts
      if(account_iterator->get_id() == id) {
        // take the target account out of the linked list
        prev_account->next = account_iterator->next;
        delete prev_account;
        return 1;
      }
      prev_account = account_iterator;
      account_iterator = account_iterator->next;
    }
  }
}


int member::get_id() {
  return id;
}


int member::transact(int account_id, double amnt) {
  account *account_ptr = get_account(account_id);
  if(!account_ptr) {
    cout << "Failed. Account not found" << endl;
    return 0;
  }
  return account_ptr->transact(amnt);
}


double member::get_balance(int account_id) {
  account *account_ptr = get_account(account_id);
  if(!account_ptr) {
    cout << "Failed. Account not found" << endl;
    return -1;
  }
  return account_ptr->get_balance();
}


account* member::get_account(int account_id) {
  account *account_ptr = this->accounts;
  while(account_ptr != nullptr) {
    if(account_ptr->get_id() == account_id) {
      return account_ptr;
    } else {
      account_ptr = account_ptr->next;
    }
  }
  return nullptr;
}
