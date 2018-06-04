#include <iostream>
#include <string>

using namespace std;


void clear_screen() {
    for(int i=0; i<10; i++) {
        cout << endl;
    }
}


// get_int_input() and get_double_input() are similar
// but are difficult to templatize because they use
// stoi() and stod() respectively. Adding function
// pointers to the template didn't work.
int get_int_input() {
  string input;
  cin >> input;
  cout << endl;
  try {
    return stoi(input);
  } catch(const exception& e) {
    cout << "Non-numeric input." << endl;
    return -1;
  }
}

double get_double_input() {
  string input;
  cin >> input;
  cout << endl;
  try {
    return stod(input);
  } catch(const exception& e) {
    cout << "Non-numeric input." << endl;
    return -1;
  }
}


int get_menu_input(int upper_bound) {
  int selection = get_int_input();
  bool valid = (selection > 0) || (selection < upper_bound);
  // Menu selections are >0 and are bounded by upper_bound.
  // Return -1 if invalid selection.
  return valid ? selection : -1;
}

int get_positive_int_input() {
  int input = get_int_input();
  bool valid = (input >= 0);
  // Positive ints are >0.
  // Return -1 if invalid input.
  return valid ? input : -1;
}

double get_positive_double_input() {
  double input = get_double_input();
  bool valid = (input >= 0);
  // Positive doubles are >0.
  // Return -1 if invalid input.
  return valid ? input : -1;
}
