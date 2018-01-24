#include <iostream>
#include "bank.h"

using namespace std;


bank::bank() {
  this->members = nullptr;
}


bank::~bank() {
  member *member_iterator = this->members;
  while(member_iterator) {
    // run through members and delete them
    member *target_member = member_iterator;
    member_iterator = member_iterator->next;
    delete target_member;
  }
}


int bank::add_member(string name, int age, char currency) {
  member *new_member = new member(name, age, currency);
  if(this->members == nullptr) {
    // if this is the first member
    this->members = new_member;
  } else {
    // if non-first member
    member *member_iterator = this->members;
    while(member_iterator->next != nullptr) {
      member_iterator = member_iterator->next;
    }
    // put on end of linked list
    member_iterator->next = new_member;
  }
  return new_member->get_id();
}


void bank::rm_member(int id) {
  /*
  member *prev_member = nullptr;
  member *member_iterator = this->members;
  while(member_iterator != nullptr) {
    if(member_iterator->get_id() == id) {
      prev_member->next = member_iterator->next;
      delete member_iterator;
    }
    prev_member = member_iterator;
    member_iterator = member_iterator->next;
  }
  */
}


// should this return a bool instead?
int bank::add_account(int member_id, double balance=0.0, string name="") {
  member *member_ptr = get_member(member_id);
  if(!member_ptr) {
    cout << "Failure. Member not found." << endl;
    return -1;
  } else {
    member_ptr->add_account(balance, name);
    return 1;
  }

}


bool bank::rm_account(int member_id, int account_id) {
  member *member_ptr = get_member(member_id);
  if(!member_ptr) {
    cout << "Failure. Member not found." << endl;
    return 0;
  } else {
    return member_ptr->rm_account(account_id);
  }
}


void bank::print_bank() {
  if(this->members == nullptr) {
    cout << "Bank is empty\n";
  } else {
    member *member_ptr = this->members;
    while(member_ptr != nullptr) {
      // loop through and print members
      member_ptr->print_member();
      member_ptr = member_ptr->next;
    }
  }
}


int bank::transact(int member_id, int account, double amnt) {
  member *member_ptr = get_member(member_id);
  if(!member_ptr) {
    cout << "Failure. Member not found." << endl;
    return -1;
  }
  return member_ptr->transact(account, amnt);
}


double bank::get_balance(int member_id, int account_id) {
  member *member_ptr = get_member(member_id);
  if(!member_ptr) {
    cout << "Failure. Member not found." << endl;
    return -1.0;
  }
  return member_ptr->get_balance(account_id);
}


bool bank::member_exists(int member_id) {
  return (get_member(member_id) ? 1 : 0);
}


member* bank::get_member(int member_id) {
  member *member_ptr = this->members;
  while(member_ptr != nullptr) {
    if(member_ptr->get_id() == member_id) {
      return member_ptr;
    } else {
      member_ptr = member_ptr->next;
    }
  }
  return nullptr;
}
