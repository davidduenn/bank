#include <iostream>
#include "bank.h"

using namespace std;

void clear_screen();
int get_input(string, int, int);


// Everything works fine
// Add error/bad_input checking
int main() {
    bank bank_inst;

    while(1) {
        int answer1 = get_input("1 to exit\n2 to print bank\n3 to create account\n4 to access account\n", 1, 3);

        int id = 0;
        int answer2;
        switch(answer1) {
          case 1:
            return 0;
          case 2:
            bank_inst.print_bank();
            break;
          case 3:
            bank_inst.create_account();
            break;
          case 4:
            id = get_input("Give id: ", 0, 0);
            if(!bank_inst.account_exists(id)) {
              cout << "You don't have an account here\n";
              break;
            }
            answer2 = get_input("Deposit (1) or Withdraw (2) or Show Balance (3)?\n", 1, 3);

            double amount;
            switch(answer2) {
              case 1:
                amount = get_input("How much would you like to deposit?\n", 0, 0);
                bank_inst.transact(id, amount);
                break;
              case 2:
                amount = get_input("How much would you like to withdraw?\n", 0, 0);
                bank_inst.transact(id, -amount);
                break;
              case 3:
                cout << "Balance: " << bank_inst.get_balance(id) << endl;
                break;
              default:
                cout << "Invalid option \"" << answer2 << "\"." << endl;
                cout << "Answer should have been between 1 and 3." << endl;
                break;
            }
            break;
          default:
            cout << "Invalid option \"" << answer1 << "\"." << endl;
            cout << "Answer should have been between 1 and 4." << endl;
            break;
        }
        clear_screen();
    }
    return 0;
}


void clear_screen() {
    for(int i=0; i<10; i++) {
        cout << endl;
    }
}

int get_input(string prompt, int lower_bound, int upper_bound) {
  // Note: use 0 for either bound to except it
  cout << prompt;
  int answer;
  // user input of a char forms a loop
  // casting as an int breaks apart numbers into single digits
  // use strings instead
  cin >> answer;
  cout << endl;

  switch(lower_bound) {
    case 0:
      switch(upper_bound) {
        case 0:
          // lower_bound - don't care. upper_bound - don't care.
          return answer;
        default:
          // lower_bound - don't care. upper_bound - care.
          return answer<=upper_bound ? answer : 0;
      }
    default:
      switch(upper_bound) {
        case 0:
          // lower_bound - care. upper_bound - don't care.
          return lower_bound<=answer ? answer : 0;
        default:
          // lower_bound - care. upper_bound - care.
          return lower_bound<=answer<=upper_bound ? answer : 0;
      }
  }
}
