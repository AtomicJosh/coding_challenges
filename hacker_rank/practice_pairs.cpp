
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the pairs function below.
int pairs(int k, vector<int> arr) {
/**
 * Run a two nested for loop subtracting each pair, each time the difference
 * matches k, increment the result.
 *
 * Better approach: Make the vector into an ordered map, iterate through it, 
 * if arr[i]+k exists, increment the result. Is this any faster? This would
 * still be looping twice. Yes, the first solution iterates nlogn, this is
 * 2n, I think?
 * **/
  int result = 0;
  /*
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i+1; j < arr.size(); j++) {
      if (abs(arr[i]-arr[j])==k) {
        result++;
      }
    }
  }
  */

  // sort the array using a map
  map<int, int> freq;
  for (int i = 0; i < arr.size(); i++) {
    freq[arr[i]] += 1;
  }
  for (int i = 0; i < arr.size(); i++) {
    result+=freq[arr[i]+k];
  }
  return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

    fout << result << "\n";

    fout.close();

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
