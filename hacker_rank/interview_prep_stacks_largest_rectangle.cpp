// tutorial: https://www.youtube.com/watch?v=VNbkzsnllsU
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
  /* Plan: create two stacks, one for tracking position and one for tracking
   * the height. Also a long max for tracking the max size found so far.
   * size = max_height*(curr_pos - start_pos). Reset the start position when
   * When a lower value is encountered, remove everything taller than it on
   * the height stack.
   * */
  long maxy = 0; 
  stack<int> position, height;
  height.push(0);
  for (uint i = 0; i < h.size(); i++) {
    if (height.empty()) {
      height.push(h[i]); 
      position.push(i);
    }
    else if (h[i]>height.top()) {
      height.push(h[i]); 
      position.push(i);
    }
    else if (h[i]<height.top()) {
      while (h[i]<height.top() && !height.empty()) {
        height.pop(); 
        position.pop();
        maxy = max(maxy, (long)(height.top() * (i - position.top())));
      }
      if (height.empty()) {
        height.push(h[i]); 
        position.push(i);
      }
    }
  }
  cout << "Maxy: " << maxy << "\n";
  return maxy;
}

int main()
{
    /*
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }*/

  std::ifstream f1("inputs.txt");
  
  if (f1) {
    int n; int temp; f1>>n; std::vector<int> h(n);
    for (int i=0; i<n; i++) {f1>>temp; h[n]=temp;}
    cout << n << h[100];
    long result = largestRectangle(h);
    cout << result << "\n";
  }
  else {std::cout << "file didn't open\n";}

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
