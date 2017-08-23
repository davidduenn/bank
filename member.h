#ifndef MEMBER_CLASS
#define MEMBER_CLASS

#include <string>
using namespace std;

class member {
  public:
    void print_member();
    class account *account_ptr;
    member(string, int, char);
    int get_id();
  private:
    int id;
    char currency ;
    int age;
    string name;
};

#endif

