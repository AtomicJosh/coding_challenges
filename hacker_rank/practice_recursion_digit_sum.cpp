
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the superDigit function below.
int superDigit(string n, int k) {
  // using the property (a+b)%x = ((a%x)+(b%x))%x
  // reference here: http://applet-magic.com/digitsummod9.htm
  //string p;
  //for (int i = 0; i < k; i++) {
  //  p += n;
  //}
  int remainder = 0;
  for (int j=0; j<k; j++){
    for (int i=0; i<n.size();i++){
      remainder = (remainder + (n[i]-'0'))%9;
    }
  }
  remainder%=9;
  cout << "result: " <<remainder;
  return remainder;

  /**
   * Base case: if n.size==1, return stoi(n)
   * Turns out this problem is miscategorized and times out with recursion on
   * the larger test cases. This should be mathematically solved instead.
   * The recursive method below works properly for smaller test cases.
   * 
  if (n.size()==1 && k==1) {return stoi(n);}
  else if (n.size()>1 || k>1) {
    // calculate the superdigit
    int sum = 0;
    string p_string;
    for (int i = 0; i < k; i++) {
      p_string += n;
    }
    //int *ptr = NULL;
    for (int i = 0; i < p_string.size(); i++) {
      sum += p_string[i]-'0';
    }
    cout << "sum: " << sum << "\n";
    int super = superDigit(to_string(sum), 1);
    cout << "super: " << super << "\n";
    return super;
  }
  else {return 0;} */
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    string n = nk[0];

    int k = stoi(nk[1]);

    int result = superDigit(n, k);

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
