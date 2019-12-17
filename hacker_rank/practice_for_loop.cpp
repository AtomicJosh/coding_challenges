#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string words(int input){
  if ((input >= 1) && (input <= 9)) {
    switch (input) {
      case 1: return "one";
      case 2: return "two";
      case 3: return "three";
      case 4: return "four";
      case 5: return "five";
      case 6: return "six";
      case 7: return "seven";
      case 8: return "eight";
      case 9: return "nine";
      default: return "not eight";
    }
  } else if ((input > 9) && ((input % 2)==0)) {
    return "even"; 
  } else if ((input > 9) && ((input % 2)==1)) {
    return "odd";
  } else {
    return "Invalid number";
  }
} 

int main() {
    // Complete the code.
    string a, b;
    cin >> a >> b;
    
    for (int i = stoi(a); i <= stoi(b); i++) {
      cout << words(i) << "\n";
    }

    //while (getline(cin, line))
    //{
    //  cout << words(stoi(line)) << "\n";
    //}
    return 0;
}
