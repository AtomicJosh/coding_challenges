
#include <bits/stdc++.h>

using namespace std;

void printVector(vector<vector<int>> arr) {
  for (uint i = 0; i < arr.size(); i++) {
    for (uint j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}


// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
  //printVector(arr);
  int oldSum = INT_MIN;
  int newSum = 0;

  int iSize = arr.size();
  int jSize = arr[0].size();

  for (int i = 0; i < iSize - 2; i++) {
    for (int j = 0; j < jSize - 2; j++) {
      newSum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
      if (newSum > oldSum) {oldSum = newSum;}
    }
  }

  //cout << "max: " << oldSum << "\n";

  return oldSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
