
#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
  // make a map with the frequency count of a
  // subtract each character from that map
  // add up the absolute value of the resulting frequencies
  // that should be the deletions required
  int count = 0;
  map<char, int> freq;
  for (int i = 0; i < a.size(); i++) {
    freq[a[i]]++;
  }
  for (int i = 0; i < b.size(); i++) {
    freq[b[i]]--;
  }
  for (int i = 0; i < freq.size(); i++) {
    count += fabs(freq[i]);
  }
  return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
