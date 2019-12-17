
#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
/**
 * Find all substrings that are all of the same characters or all the same
 * except the middle character.
 *
 * Brute force: with i iterating up to s.size(), j up to s.size()-1+1, k up to i
 * iterate through s[i]==s[k]++ to see if they are all the same.
 * if (i>2 && i%2==1) then skip 1/2+1
 * if they are all the same, then increment result.
 * 
 * Can save the first iteration by setting result = s.size() and i=2.
 * I can't think of a more optimized approach.
 *
 * **/
  
  long count = 0;
  vector<std::pair<char, int>> frequencies;
  int i=0, j=0;

  // 1st pass: Build a list of tuples such that the string "aaabbc" can be squashed down to [("a", 3), ("b", 2), ("c", 1)
  for ( i = 0; i < n; i++)
  {
    for( j = i+1; j < n; j++){
      if (s[j] == s[i])
        continue;
      else
        break;
    }
    frequencies.push_back(std::make_pair(s[i],j-i));
    i = j-1;
  }
  
  for (i=0; i < frequencies.size(); i++) {cout << frequencies[i].first << frequencies[i].second << "\n";}

  // 2nd pass: add to answer all combinations of substrings from these tuples which would represent palindromes which have all same letters. The equation for 3! = 3*2*1 which is n*(n+1)/2 = 3*4/2.
  for (i=0; i < frequencies.size(); i++)
    count += (frequencies[i].second+1) * frequencies[i].second / 2; 

  // 3rd pass: traverse this list to specifically find the second case mentioned in problem.
  for (i=1; i < frequencies.size()-1; i++) {
    cout << frequencies[i].first << frequencies[i].second << "\n";
    cout << "if (frequencies[i].second == 1 && frequencies[i-1].first == frequencies[i+1].first): if ("<<frequencies[i].second<<" == 1 && "<<frequencies[i-1].first<<" == "<<frequencies[i+1].first<<")\n";
    if (frequencies[i].second == 1 && frequencies[i-1].first == frequencies[i+1].first) {
      count += min(frequencies[i-1].second, frequencies[i+1].second);
    }
  }
  cout << "count: " << count;
  return count;

  /*
  long result = s.size();
  for (int i = 2; i <= s.size(); i++) { // check for substrings of size i
    cout << "\nsize: " << i;
    for (int j = 0; j < s.size()-i+1; j++) { // check through the all of s
      cout << "\n";
      for (int k = 0; k < i; k++) { // check each char (k) of the substring
        cout << s[j+k];
        if (i>2 && i%2==1 && k==i/2) {continue;} // skip middle char
        if (s[j+k]!=s[j]) {break;} // if all the chars are not the same, exit the loop
        
        // if at the end of substring and all are the same, increment result
        if (k==i-1) {result++;}
      }
    }
  }
  cout << "\nresult: " << result << "\n"; 
  return result;
  */
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
