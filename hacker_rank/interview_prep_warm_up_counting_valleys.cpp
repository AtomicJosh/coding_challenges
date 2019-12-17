
#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
  // inputs: n = s.size(); s = string describing path
  // outputs: result = number of valleys encountered

  int counter = 0;
  int result = 0;

  // iterate through s
  // start a counter to track ups and downs
  // if counter is 0 and the next s[i] is down, increase result by 1
  for (uint i = 0; i < s.size(); i++) {
    if (s[i] == 'D') {
      if (counter == 0) {result++;}
      counter--;
    }
    if (s[i] == 'U') {counter++;}
  }

  return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
