#include <iostream>
#include "../../bank.h"
#include "../../helpers.h"

using namespace std;

int main() {
  bank test_bank_inst;

  //int dd = test_bank_inst.add_member("David Duenn", 54, '$');
  for(int i=0; i<8000; i++) {
    int jw = test_bank_inst.add_member("John Wayne", 64, '$');
  }
  //int pf = test_bank_inst.add_member("Pope Francis", 44, '$');

  /*
  test_bank_inst.account_exists(dd) ? cout << "account exists" << endl : cout << "no such account" << endl;
  test_bank_inst.account_exists(jw) ? cout << "account exists" << endl : cout << "no such account" << endl;
  test_bank_inst.account_exists(pf) ? cout << "account exists" << endl : cout << "no such account" << endl;
  test_bank_inst.account_exists(-2) ? cout << "account exists" << endl : cout << "no such account" << endl;

  test_bank_inst.transact(dd,  23) ? cout << "Tranx failed" << endl : cout << "Trnx succeeded" << endl;
  test_bank_inst.transact(jw, 130) ? cout << "Tranx failed" << endl : cout << "Trnx succeeded" << endl;
  test_bank_inst.transact(pf,  24) ? cout << "Tranx failed" << endl : cout << "Trnx succeeded" << endl;

  test_bank_inst.print_bank();

  test_bank_inst.transact(dd, -23) ? cout << "Tranx failed" << endl : cout << "Trnx succeeded" << endl;
  test_bank_inst.transact(jw, 200) ? cout << "Tranx failed" << endl : cout << "Trnx succeeded" << endl;
  test_bank_inst.transact(pf, -80) ? cout << "Tranx failed" << endl : cout << "Trnx succeeded" << endl;
  */

  test_bank_inst.print_bank();

  return 0;
}
