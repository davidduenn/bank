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
  account_ptr = NULL;
}

int member::get_id() {
  return id;
}
