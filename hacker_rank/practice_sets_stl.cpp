
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  set<int> s;
  int q, op, x;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> op >> x;
    //cout << "op: " << op << "; x: " << x << endl;
    switch (op) {
      case 1: {
		//cout << "insert: " << x << endl; 
		s.insert(x);
		break;
	      }
      case 2: {
		//cout<<"erase: " << x << endl; 
		s.erase(x);
		break;
	      }
      case 3: {
	        set<int>::iterator itr=s.find(x);
		if (itr==s.end()) {cout << "No" << endl; break;}
		else {cout << "Yes" << endl; break;}
	      }// if x is present in set, print yes, else no
      default: {
		 cout << "Invalid entry" << endl;
		 break;
	       }
    }
  }

    return 0;
}
