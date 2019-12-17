// g++ -g hacker_rank_quicksort.cpp -o hacker_rank_quicksort.out; and cat argus | ./hacker_rank_quicksort.out
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the quickSort function below.
/*
 * Choose some pivot element, p, and partition your unsorted array, arr, into three smaller arrays: left, right, and equal, where each element in left < p, each element in right > p, and each element in equal = p.
 * For example: Assume arr={5,7,4,3,8} The pivot is at arr[0] = 5. arr is divided into left = {4,3}, equal = {5}, and right = {7,8}.  Putting them all together, you get {4,3,5,7,8}. Another valid solution is {3,4,5,8,7}.
 * Given arr and p = arr[0], partition arr into left, equal, and right using the Divide instructions above. Then print each element in left followed by each element in equal, followed by each element in right on a single line. Your output should be space-separated and does not have to maintain ordering of the elements within the three categories.
 * */

void printArray(vector<int> arr) {
	for (uint i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	//cout << endl;
}

vector<int> quickSort(vector<int> arr) {
  printArray(arr);
	cout << endl;
	int p = arr[0];
	vector<int> left, equal, right;
	equal.push_back(p);
	for (uint i = 1; i < arr.size(); i++) {
		if (arr[i] < p) {left.push_back(arr[i]);}
		if (arr[i] == p) {equal.push_back(arr[i]);}
		if (arr[i] > p) {right.push_back(arr[i]);}
	}
	printArray(left);
	printArray(equal);
	printArray(right);

  return arr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    vector<int> result = quickSort(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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

