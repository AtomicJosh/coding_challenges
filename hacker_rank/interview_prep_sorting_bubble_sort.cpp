
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void printvector (vector<int> a) {
  for (uint i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// Complete the countSwaps function below.
void countSwaps(vector<int> a) {
  uint counter = 0;
  bool sorted = false;
  while (!sorted) {
    uint subcounter = 0;
    for (uint j = 0; j < a.size() - 1; j++) {
      // Swap adjacent elements if they are in decreasing order
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
        counter++;
        subcounter = 0;
        //cout << "counter: " << counter << endl;
        //printvector(a);
      }
      else {subcounter++;}
    }
    if (subcounter == a.size()-1) {sorted = true;}
  }
  cout << "Array is sorted in " << counter << " swaps.\n";
  cout << "First Element: " << a.front() << "\n";
  cout << "Last Element: " << a.back() << "\n";
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    countSwaps(a);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
