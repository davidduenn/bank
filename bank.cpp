#include <iostream>
#include "bank.h"

using namespace std;


bank::bank() {
  this->members = nullptr;
}


/*
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
todo: is bank::member_exists() needed? 10/Dec/2017
*/


int bank::create_member(string name, int age, char currency) {
    member *new_member = new member(name, age, currency);
    return new_member->get_id();
}


void bank::print_bank() {
    if(this->members == nullptr) {
        cout << "Bank is empty\n";
        return;
    }

    member *member_ptr = this->members;
    while(member_ptr != nullptr) {
      member_ptr->print_member();
      member_ptr = member_ptr->next_member;
    }
}


int bank::transact(int id, int account, double amnt) {
  member *member_ptr = this->members;
  while(member_ptr != nullptr) {
    if(member_ptr->get_id() == id) {
      member_ptr->transact(account, amnt);
      return 0;
    } else {
      member_ptr = member_ptr->next_member;
    }
  }
  cout << "Failed. Member not found." << endl;
  return 1;
}

double bank::get_balance(int member_id, int account_id) {
  member *member_ptr = this ->members;
  while(member_ptr != nullptr) {
    if(member_ptr->get_id() == member_id) {
      return member_ptr->get_balance(account_id);
    } else {
      member_ptr = member_ptr->next_member;
    }
  }
  cout << "Failed. Member not found." << endl;
  return 1;
}

// todo transact and get_balance are mostly 
// the same code. Pull common code to a 
// function
