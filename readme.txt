A bank implemented in c++ for exercise

Currently:
  bank: class
  account: class
  instances of banks contain vector of accounts

Future:
  bank: struct
  member: class
  account: class
  instance of bank contains members which contains linked list of accounts

Currently trying to add member class to replace account and make
account class a sub class to member class. Difficult to keep code straight.
May need to rewrite everything and then try to compile.

Just create a new project from the ground up and take major chunks from this project?

Menu:
  exit
  print bank
  create member
  access member
    deposit
    withdraw
    show balance
    add account
