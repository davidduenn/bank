#ifndef MEMBER_CLASS
#define MEMBER_CLASS

#include <string>
#include "account.h"
using namespace std;

class member {
  public:
    void print_member();
    void add_account(double, string);
    void rm_account();
    member(string, int, char);
    int get_id();
    class member *next_member;
    int transact(int, double);
    double get_balance(int);
  private:
    class account *accounts;
    int id;
    char currency ;
    int age;
    string name;
};

#endif

