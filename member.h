#ifndef MEMBER_CLASS
#define MEMBER_CLASS

#include <string>
#include "account.h"
using namespace std;

class member {
  public:
    member(string, int, char);
    ~member();
    void print_member();
    void add_account(double, string);
    void rm_account();
    int get_id();
    class member *next;
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

