#include <iostream>
#include "../../bank.h"
#include "../../helpers.h"

using namespace std;

int main() {
  bank test_bank_inst;

  int dd = test_bank_inst.create_account("David", "Duenn");
  int jw = test_bank_inst.create_account("John", "Wayne");
  int pf = test_bank_inst.create_account("Pope", "Francis");

  cout << test_bank_inst.account_exists(dd) << endl;
  cout << test_bank_inst.account_exists(jw) << endl;
  cout << test_bank_inst.account_exists(pf) << endl;
  cout << test_bank_inst.account_exists(-2) << endl;

  test_bank_inst.transact(dd,  23) ? cout << "Tranx failed" << endl : cout << "Trnx succeeded" << endl;
  test_bank_inst.transact(jw, 130) ? cout << "Tranx failed" << endl : cout << "Trnx succeeded" << endl;
  test_bank_inst.transact(pf,  24) ? cout << "Tranx failed" << endl : cout << "Trnx succeeded" << endl;

  test_bank_inst.print_bank();

  test_bank_inst.transact(dd, -23) ? cout << "Tranx failed" << endl : cout << "Trnx succeeded" << endl;
  test_bank_inst.transact(jw, 200) ? cout << "Tranx failed" << endl : cout << "Trnx succeeded" << endl;
  test_bank_inst.transact(pf, -80) ? cout << "Tranx failed" << endl : cout << "Trnx succeeded" << endl;

  test_bank_inst.print_bank();

  return 0;
}
