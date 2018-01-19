#include <iostream>
#include <stdlib.h> // srand
#include <string>
#include "bank.h"
#include "helpers.h"

using namespace std;


int main() {
    bank bank_inst;

    srand(time(nullptr)); // seed random number

    while(1) {
        int answer1 = get_int_input("1 to exit\n2 to print bank\n3 to add member\n4 to access member\n", 1, 4);

        int member_id = 0;
        int account_id = 0;
        int answer2 = 0;
        string member_name = "none";
        int age = 0;
        char currency = '$';
        string account_name = "";
        switch(answer1) {
          case 1:
            return 0;
          case 2:
            bank_inst.print_bank();
            break;
          case 3:
            cout << "Give member name: ";
            cin.ignore(); // clear the cin buffer
            getline(cin, member_name); cout << endl; // getline() can take spaces. cin can't.
            cout << "Give age: ";
            cin >> age; cout << endl;
            cout << "Give currency char: ";
            cin >> currency; cout << endl;
            cout << "Your member id is: ";
            // Check that this is a string, int, char
            cout << bank_inst.add_member(member_name, age, currency) << endl;
            break;
          case 4:
            member_id = get_int_input("Give member id: ", 0, 0);
            /*
            if(!bank_inst.account_exists(id)) {
              cout << "You don't have an account here\n";
              break;
            }
            */
            answer2 = get_int_input("Deposit (1) or Withdraw (2) or Show Balance (3) or Add Account (4)?\n", 1, 4);

            double amount;
            switch(answer2) {
              case 1:
                amount = get_int_input("How much would you like to deposit?\n", 0, 0);
                account_id = get_int_input("Give account id: ", 0, 0);
                bank_inst.transact(member_id, account_id, amount) ?
                  cout << "Not enough money to complete transaction\n" :
                  cout << "Transaction successful\n";
                break;
              case 2:
                amount = get_int_input("How much would you like to withdraw?\n", 0, 0);
                account_id = get_int_input("Give account id: ", 0, 0);
                bank_inst.transact(member_id, account_id, -amount);
                break;
              case 3:
                account_id = get_int_input("Give account id: ", 0, 0);
                cout << "Balance: " << bank_inst.get_balance(member_id, account_id) << endl;
                break;
              case 4:
                cout << "Give account name: ";
                cin >> account_name; cout << endl;
                bank_inst.add_account(member_id, 0, account_name);
                break;
              default:
                cout << "Invalid input." << endl;
                cout << "Answer should have been between 1 and 3." << endl;
                break;
            }
            break;
          default:
            cout << "Invalid input." << endl;
            cout << "Answer should have been between 1 and 4." << endl;
            break;
        }
        clear_screen();
    }
    return 0;
}
