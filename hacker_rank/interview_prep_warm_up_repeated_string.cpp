
#include <bits/stdc++.h>
//#include <algorithm>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
  long result = (n/s.size()) * (std::count(s.begin(), s.end(), 'a')) + (std::count(s.begin(), (s.begin() + (n % s.size())), 'a'));

  //cout << result;
  return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
