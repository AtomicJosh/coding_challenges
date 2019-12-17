
#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
  // Problem: https://www.hackerrank.com/challenges/angry-children/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms
  // Create a dequeue of size k, move it along arr, find the max, min, and difference at 
  // each iteration. Keep the lowest diff and its starting index, that iteration 
  // is the answer. 
  /**
   * A better solution would be, since it is already sorted, to find the difference
   * between arr[i] and arr[i+k], and find the minimum of that difference.
   * **/ 
  int mindiff = INT_MAX;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < arr.size()-k+1; i++){
    
    vector<int>::const_iterator front = arr.begin()+i;
    vector<int>::const_iterator back = arr.begin()+i+k;
    auto result = minmax_element(front, back);
    cout << "front: " << *front << "; end: " << *back << "\n";
    cout << "Max: " << *result.second << "; Min: " << *result.first << "\n";
    int diff = abs(*result.second - *result.first);
    if (diff <  mindiff) mindiff=diff;
  }
  cout << "mindiff: " << mindiff << "\n";
  return mindiff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
