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
        cout << "1 Exit\n2 Print bank\n3 Add member\n4 Remove member\n5 Access member\n";
        int answer1 = get_menu_input(5);

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
              cout << "Give age: ";
              age = get_positive_int_input();
            } while(age<0);
            cout << "Give currency char: ";
            cin >> currency; cout << endl;
            cout << "Your member id is: ";
            // Check that this is a string, int, char
            cout << bank_inst.add_member(member_name, age, currency) << endl;
            break;
          case 4:
            cout << "Give member id: ";
            member_id = get_positive_int_input();
            bank_inst.rm_member(member_id) ?
              cout << "Success. Member removed.":
              cout << "Failure. Member not found.";
            break;
          case 5:
            cout << "Give member id: ";
            member_id = get_positive_int_input();
            if(!bank_inst.member_exists(member_id)) {
              // break if member does not exist
              cout << "Failure. Member not found." << endl;
              break;
            }
            cout << "1 Deposit\n2 Withdraw\n3 Show Balance\n4 Add Account\n5 Remove Account\n6 Print Member\n";
            answer2 = get_menu_input(6);

            double amount;
            switch(answer2) {
              case 1:
                cout << "How much would you like to deposit?" << endl;
                amount = get_positive_double_input();
                cout << "Give account id: ";
                account_id = get_positive_int_input();
                bank_inst.transact(member_id, account_id, amount);
                break;
              case 2:
                cout << "How much would you like to withdraw?" << endl;
                amount = get_positive_double_input();
                cout << "Give account id: ";
                account_id = get_positive_int_input();
                bank_inst.transact(member_id, account_id, -amount);
                break;
              case 3:
                cout << "Give account id: ";
                account_id = get_positive_int_input();
                cout << "Balance: " << bank_inst.get_currency(member_id) << bank_inst.get_balance(member_id, account_id) << endl;
                break;
              case 4:
                cout << "Give account name: ";
                cin >> account_name; cout << endl;
                do {
                  cout << "Give inital account balance: ";
                  amount = get_positive_double_input();
                  if(amount == -1) {
                    cout << "Invalid input. Answer should have been a positive number" << endl;
                  }
                } while(amount < 0);
                bank_inst.add_account(member_id, amount, account_name);
                break;
              case 5:
                cout << "Give account id: ";
                account_id = get_positive_int_input();
                bank_inst.rm_account(member_id, account_id) ?
                  cout << "Success. Account removed.":
                  cout << "Failure. Account not found." ;
                break;
              case 6:
                bank_inst.print_member(member_id);
                break;
              default:
                cout << "Invalid input." << endl;
                cout << "Answer should have been between 1 and 6." << endl;
                break;
            }
            break;
          default:
            cout << "Invalid input." << endl;
            cout << "Answer should have been between 1 and 5." << endl;
            break;
        }
        clear_screen();
    }
    return 0;
}
