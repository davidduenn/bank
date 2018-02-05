#ifndef MEMBER_CLASS
#define MEMBER_CLASS

#include <string>
#include "account.h"

class member {
  public:
    member(string, int, char, int);
    ~member();
    void print_member();
    void add_account(double, string);
    bool rm_account(int);
    int get_id();
    class member *next;
    int transact(int, double);
    double get_balance(int);
    char get_currency();
  private:
    class account *accounts;
    account* get_account(int);
    int id;
    char currency ;
    int age;
    string name;
};

#endif

