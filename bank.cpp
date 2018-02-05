#include <iostream>
#include <stdlib.h> // rand
#include "bank.h"

#define MAX_NUM_MEMBERS 9000

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
  member *new_member = new member(name, age, currency, generate_member_id());
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


bool bank::rm_member(int id) {
  if(!this->members) {
    // fail if member linked list is empty
    return 0;
  }
  if(this->members->get_id() == id) {
    // if the first member is our target
    // take it out of the linked list and delete it
    member *target_member = this->members;
    this->members = this->members->next;
    delete target_member;
    return 1;
  } else {
    // if non-empty and target is not first one
    member *prev_member = this->members;
    member *member_iterator = this->members->next;
    while(member_iterator) {
      // iterate through members
      if(member_iterator->get_id() == id) {
        // take the target member out of the linked list
        prev_member->next = member_iterator->next;
        delete member_iterator;
        return 1;
      }
      prev_member = member_iterator;
      member_iterator = member_iterator->next;
    }
  }
}


bool bank::add_account(int member_id, double balance=0.0, string name="") {
  member *member_ptr = get_member(member_id);
  if(!member_ptr) {
    cout << "Failure. Member not found." << endl;
    return 0;
  } else {
    member_ptr->add_account(balance, name);
    return 1;
  }

}


bool bank::rm_account(int member_id, int account_id) {
  member *member_ptr = get_member(member_id);
  if(!member_ptr) {
    cout << "failure. member not found." << endl;
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


int bank::generate_member_id() {
  int id = 0;
  int tries = 0;
  do {
    // create id and return if it's not in use
    id = 1000 + rand() %MAX_NUM_MEMBERS;
    if(tries++ > (MAX_NUM_MEMBERS * 0.9)) {
      cout << "MAX_NUM_MEMBERS being hit. Increase MAX_NUM_MEMBERS." << endl;
    }
  } while (member_exists(id));
  return id;
}
