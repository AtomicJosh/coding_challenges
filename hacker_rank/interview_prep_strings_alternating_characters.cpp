
#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
  int count = 0;
  uint i = 1;
  while (i < s.size()) {
    if (s[i] == s[i-1]) {
      s.erase(s.begin() + i);
      count++;
    }
    else {
      i++;
    }
  }
  cout << "count: " << count << "\n";
  return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
