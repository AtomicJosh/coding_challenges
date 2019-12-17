
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int n;
  cin >> n;

  vector<int> nints(n);

  for (int i = 0; i < n; i++){
    cin >> nints[i];
  }

  // do the lower_bound sorting here; already sorted
//  sort(nints.begin(), nints.end());

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int qs, lb;
    cin >> qs;
    lb = (lower_bound(nints.begin(), nints.end(), qs) - nints.begin());
    // yes if the number is present and at which index
    // no if not present and the index of the next smallest number just greater than that number
    if (nints[lb]==qs) {cout << "Yes ";}
    else {cout << "No ";}
    cout << lb + 1 << "\n";
  }
    
  return 0;
}
