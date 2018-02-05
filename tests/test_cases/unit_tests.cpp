#include <iostream>
#include <assert.h>
#include "../../bank.h"
#include "../../helpers.h"

using namespace std;

int main() {
  // Create test banks
  bank test_bank_inst1;
  bank test_bank_inst2;

  // Populate banks with members
  int dd = test_bank_inst1.add_member("David Duenn", 94, '$');
  int pf = test_bank_inst1.add_member("Pope Francis", 44, '$');
  int pr = test_bank_inst2.add_member("The President", 64, '$');
  int pm = test_bank_inst2.add_member("Prime Minister", 74, '$');

  // Create multiple members
  for(int i=0; i<100; i++) {
    int jw = test_bank_inst1.add_member("John Wayne", 62, '$');
  }

  // Check if members exist
  assert(test_bank_inst1.member_exists(dd)); // Success
  assert(test_bank_inst1.member_exists(pf)); // Success
  assert(!test_bank_inst1.member_exists(20)); // Member does not exist
  assert(test_bank_inst2.member_exists(pr)); // Success
  assert(test_bank_inst2.member_exists(pm)); // Success
  assert(!test_bank_inst2.member_exists(-2)); // Member does not exist

  // Create accounts
  assert(test_bank_inst1.add_account(dd, 300, "savings")); // Success
  assert(test_bank_inst2.add_account(pm, 500, "checking")); // Success

  // Run transactions
  assert(test_bank_inst1.transact(dd, 0,  -23)); // Success
  assert(test_bank_inst1.transact(dd, 0,  130)); // Success
  assert(test_bank_inst2.transact(pm, 0,   26)); // Success
  assert(test_bank_inst2.transact(pm, 0,  -24)); // Success
  assert(!test_bank_inst1.transact(pf, 3,  130)); // Account does not exist
  assert(!test_bank_inst2.transact(pm, 0, -900)); // Not sufficient funds

  // Get balances
  assert(test_bank_inst1.get_balance(dd,  0) > 0); // Success
  assert(test_bank_inst1.get_balance(dd, 23) < 0); // Account does not exist
  assert(test_bank_inst1.get_balance(pf, 23) < 0); // Account does not exist
  assert(test_bank_inst2.get_balance(pr,  0) < 0); // Account does not exist
  assert(test_bank_inst2.get_balance(pm,  0) > 0); // Success
  assert(test_bank_inst2.get_balance(3,   0) < 0); // Member does not exist
  assert(test_bank_inst2.get_balance(-2,  0) < 0); // Member does not exist

  // Print banks
  test_bank_inst1.print_bank();
  test_bank_inst2.print_bank();

  // Remove accounts
  assert(test_bank_inst1.rm_account(dd, 0)); // Removes account

  // Remove members
  assert(test_bank_inst2.rm_member(pm)); // Removes member and associated account

  // Print banks
  test_bank_inst1.print_bank();
  test_bank_inst2.print_bank();

  return 0;
}
