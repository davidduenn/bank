#include <iostream>
#include "bank.h"

using namespace std;

void clear_screen();


// Everything works fine
// Add error/bad_input checking
int main() {
    bank bank_inst;

    while(1) {
        int ans = -1;
        cout << "1 to exit\n";
        cout << "2 to print bank\n";
        cout << "3 to create account\n";
        cout << "4 to access account\n";
        cin >> ans; cout << endl;
        if(ans == 1) {
            break;
        }
        else if(ans == 2) {
            bank_inst.print_bank();
            cout<<"Enter char to proceed: ";string s; cin>>s;//Waits for key press
        }
        else if(ans == 3) {
            bank_inst.create_account();
        }
        else if(ans == 4) {
            cout << "Give id: ";
            int id = 0;
            cin >> id; cout << endl;

            //get_wahl:
            cout << "Deposit (1) or Withdraw (2) or Show Balance (3)?\n";
            int wahl;
            cin >> wahl; cout << endl;

            /*
            try {
                if(wahl<1 || wahl>3) {
                    throw wahl;
                }
            }
            catch(int wahl) {
                cout << "Not a good answer\n";
                goto get_wahl;
            }
            */

            if(wahl == 1) {
                cout << "How much would you like to deposit?\n";
                double amnt;
                cin >> amnt; cout << endl;
                bank_inst.deposit(id, amnt);
            }
            else if(wahl == 2) {
                cout << "How much would you like to withdraw?\n";
                double amnt;
                cin >> amnt; cout << endl;
                bank_inst.withdraw(id, amnt);
            }
            else if(wahl == 3) {
                cout << "Balance: " << bank_inst.get_balance(id) << endl;
                cout<<"Enter char to proceed: ";string s; cin>>s;//Waits for key press
            }
            else {
                throw wahl;
            }
        }
        else {
            // invalid option
        }
        clear_screen();
    }
    return 0;
}


void clear_screen() {
    for(int i=0; i<75; i++) {
        cout << endl;
    }
}

