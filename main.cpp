#include <iostream>
#include <string>
#include "bank.h"
#include "helpers.h"

using namespace std;


// Add error/bad_input checking
int main() {
    bank bank_inst;

    while(1) {
        int answer1 = get_int_input("1 to exit\n2 to print bank\n3 to create account\n4 to access account\n", 1, 3);

        int id = 0;
        int answer2;
        string first, last;
        switch(answer1) {
          case 1:
            return 0;
          case 2:
            bank_inst.print_bank();
            break;
          case 3:
            cout << "Give first name: ";
            cin >> first; cout << endl;
            cout << "Give last name: ";
            cin >> last; cout << endl;
            cout << "Your account id is: ";
            cout << bank_inst.create_account(first, last) << endl;
            break;
          case 4:
            id = get_int_input("Give id: ", 0, 0);
            if(!bank_inst.account_exists(id)) {
              cout << "You don't have an account here\n";
              break;
            }
            answer2 = get_int_input("Deposit (1) or Withdraw (2) or Show Balance (3)?\n", 1, 3);

            double amount;
            switch(answer2) {
              case 1:
                amount = get_int_input("How much would you like to deposit?\n", 0, 0);
                bank_inst.transact(id, amount);
                break;
              case 2:
                amount = get_int_input("How much would you like to withdraw?\n", 0, 0);
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
