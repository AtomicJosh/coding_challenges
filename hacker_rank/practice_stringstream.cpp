
#include <sstream>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
  stringstream ss(str);
  string inty;
  vector<int> ints;
  while (getline(ss, inty, ',')){
    ints.push_back(stoi(inty));
  }
  return ints;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

