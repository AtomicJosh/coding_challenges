
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

  uint Q = 0;
  map<string, int> m;
  string qname;
  int qtype, qmarks;

  cin >> Q;
  cout << "Q: " << Q << "\n";

  for (uint i(0); i<Q; i++) {
    cin >> qtype;
    cout << "qtype: " << qtype << "\n";
    switch (qtype) {
      case 1: { // add qmarks to the student qname
        cin >> qname >> qmarks;
	cout << "add qname: " << qname << "; qmarks: " << qmarks << "\n";
        m.insert(make_pair(qname, qmarks));
      }
      case 2: { // erase the marks of student qname
        cin >> qname;
	cout << "erase qname: " << qname << "\n";
        m.erase(qname);
      }
      case 3: { // print the marks of student qname
        cin >> qname;
	cout << qname << " marks: " << m[qname] << "\n";
      }
      default: {
        cout << "Error: Not a valid type \n";
      }
    }
  }


  return 0;
}



