#include <iostream>
#include <string>
using namespace std;


void clear_screen() {
    for(int i=0; i<10; i++) {
        cout << endl;
    }
}


int get_input(string prompt, int lower_bound, int upper_bound) {
  // Note: use 0 for either bound to except it
  cout << prompt;
  int answer;
  // user input of a char forms a loop
  // casting as an int breaks apart numbers into single digits
  // use strings instead
  cin >> answer;
  cout << endl;

  switch(lower_bound) {
    case 0:
      switch(upper_bound) {
        case 0:
          // lower_bound - don't care. upper_bound - don't care.
          return answer;
        default:
          // lower_bound - don't care. upper_bound - care.
          return answer<=upper_bound ? answer : 0;
      }
    default:
      switch(upper_bound) {
        case 0:
          // lower_bound - care. upper_bound - don't care.
          return lower_bound<=answer ? answer : 0;
        default:
          // lower_bound - care. upper_bound - care.
          return lower_bound<=answer<=upper_bound ? answer : 0;
      }
  }
}
