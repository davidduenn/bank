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
        int answer1 = get_int_input("1 to exit\n2 to print bank\n3 to add member\n4 to remove member\n5 to access member\n", 1, 5);

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
            do {
            age = get_int_input("Give age: ", 0, -1);
            } while(age<0);
            cout << "Give currency char: ";
            cin >> currency; cout << endl;
            cout << "Your member id is: ";
            // Check that this is a string, int, char
            cout << bank_inst.add_member(member_name, age, currency) << endl;
            break;
          case 4:
            member_id = get_int_input("Give member id: ", 0, -1);
            bank_inst.rm_member(member_id) ?
              cout << "Success. Member removed.":
              cout << "Failure. Member not found.";
            break;
          case 5:
            member_id = get_int_input("Give member id: ", 0, -1);
            if(!bank_inst.member_exists(member_id)) {
              // break if member does not exist
              cout << "Failure. Member not found." << endl;
              break;
            }
            answer2 = get_int_input("Deposit (1), Withdraw (2), Show Balance (3), Add Account (4), Remove Account (5), Print Member (6)?\n", 1, 5);

            double amount;
            switch(answer2) {
              case 1:
                amount = get_int_input("How much would you like to deposit?\n", 0, -1);
                account_id = get_int_input("Give account id: ", 0, -1);
                bank_inst.transact(member_id, account_id, amount);
                break;
              case 2:
                amount = get_int_input("How much would you like to withdraw?\n", 0, -1);
                account_id = get_int_input("Give account id: ", 0, -1);
                bank_inst.transact(member_id, account_id, -amount);
                break;
              case 3:
                account_id = get_int_input("Give account id: ", 0, -1);
                cout << "Balance: " << bank_inst.get_balance(member_id, account_id) << endl;
                break;
              case 4:
                cout << "Give account name: ";
                cin >> account_name; cout << endl;
                bank_inst.add_account(member_id, 0, account_name);
                break;
              case 5:
                account_id = get_int_input("Give account id: ", 0, -1);
                bank_inst.rm_account(member_id, account_id) ?
                  cout << "Success. Account removed.":
                  cout << "Failure. Account not found." ;
                break;
              case 6:
                bank_inst.print_member(member_id);
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
