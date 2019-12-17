/**
 * Input Format:
 * The first line contains two space-separated integers denoting the respective
 * values of n (the number of variable-length arrays) and q (the number of queries).
 * Each line i of the n subsequent lines contains a space-separated sequence in 
 * the format k a[i]_0 a[i]_1 ... a[i]_k-1 describing the k-element array located
 * at a[i].
 * Each of the q subsequent lines contains two space-separated integers describing
 * the respective values of i (an index in array a) and j (an index in the array
 * referenced by a[i]) for a query.
 *
 * Constraints:
 * - 1 <= n <= 10^5
 * - 1 <= q <= 10^5
 * - 1 <= #k <= 3*10^5
 * - n <= sum(k) <= 3*10^5
 * - 0 <= #i < n
 * - 0 <= #j < k
 * - All indices in this challenge are zero-based.
 * - All the given numbers are non negative and are not greater than
 *
 * Output Format:
 * For each pair of i and j values (i.e., for each query), print a single integer 
 * denoting the element located at index j of the array referenced by a[i]. There 
 * should be a total of q lines of output.
 *
 * Sample Input:
 * 2 2
 * 3 1 5 4
 * 5 1 2 8 9 3
 * 0 1
 * 1 3
 *
 * Sample Output:
 * 5
 * 9
 ***/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// inputs:
// first line: "n q" n = number of variable length arrays; q = number of queries
// next n lines: variable length arrays
// next q lines: queries


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int n, q, k, l;
  string s, v;
  cin >> n >> q;
  vector<vector<int>> theray(n);
  
  for (int i = 0; i < n; i++) {
    cin >> k;
    cout << "k: " << k << endl;
    for (int j = 0; j < k; j++) {
      cin >> l;
      cout << "l: " << l << endl;
      theray[i].push_back(l);
    }
  }

  for (int i = 0; i < q; i++) {
    cin >> k >> l;
    cout << theray[k][l] << endl;
  }
  return 0;
}
