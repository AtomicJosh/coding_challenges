
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
  map <string, int> m;
  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int w;
    string x;
    cin >> w;
    switch (w) 
    {
      case 1: 
      {
        string x;
        int y;
        cin >> x >> y;
        m[x] += y;
        break;
      }
      case 2:
      { 
        cin >> x;
        m.erase(x);
        break;
      }
      case 3:
      {
        cin >> x;
        cout << m[x] << endl;
        break;
      }
      default:
      {
        cout << "Invalid case \n";
        break;
      }

    }
  }

	return 0;
}



