// g++ hacker_rank_insertion_sort_2.cpp -o hacker_rank_insertion_sort_2.out && ./hacker_rank_insertion_sort_2.out
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void printVector(int n, vector<int> arr) {
	for (int j = 0; j < n; j++) {
		cout << arr[j] << " ";
		if (j == n-1) { cout << endl; }
	}
}

void insertionSort1(int n, vector<int> arr) {
    int store = arr[n-1];
    bool togBreak = false;
    for (int i = n-1; i >= 0; i--) {
        if (i==0) { arr[0]=store; }
        else {
            arr[i] = arr[i-1];

            if (store >= arr[i]) {
                arr[i] = store;
                togBreak = true;
            }
        }
        for (int j = 0; j < n; j++) {
            cout<<arr[j]<<" ";
            if (j == n-1) {cout<<endl;}
        }

        if (togBreak) {break;}
    }
}

// Complete the insertionSort2 function below.
void insertionSort2(int n, vector<int> arr) {
/*
Sample Output

1 4 3 5 6 2
1 3 4 5 6 2
1 3 4 5 6 2
1 3 4 5 6 2
1 2 3 4 5 6

Explanation

Skip testing 1 against itself at position 0. It is sorted.
Test position 1 against position 0: 4 > 1, no more to check, no change.
Print arr
Test position 2 against positions 1 and 0:

- 3 < 4, new position may be 1. Keep checking.
- 3 > 1, so insert 3 at position 1 and move others to the right.

Print arr

Test position 3 against positions 2, 1, 0 (as necessary): no change.
Print arr
Test position 4 against positions 3, 2, 1, 0: no change.
Print arr
Test position 5 against positions 4, 3, 2, 1, 0, insert 2 at position 1 and move others to the right.
Print arr

break insertionSort2
run
6
1 4 3 5 6 2

*/
	printVector(n, arr);
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] < arr[j]) {
				//cout << arr[i] << " is < " << arr[j] << endl;
				if (arr[i] > arr[j - 1]) {
					int temp = arr[i];
					//cout << arr[i] << " is > " << arr[j-1] << endl;
					//cout << "Swap " << arr[j] << " and " << arr[i] << endl;
					for (int k = i; k >= j; k--) {
						//cout << "Move " << arr[k-1] << " to " << arr[k] << endl;
						arr[k] = arr[k - 1];
					}
					arr[j] = temp;
				  printVector(n, arr);
				}
			}
		}
	}
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort2(n, arr);

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
