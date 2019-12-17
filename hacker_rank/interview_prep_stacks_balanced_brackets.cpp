
//This works and it matches the results in the 
//submission but it isn't being fully accepted.
#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
  // Plan: iterate through s, if the char is an opening bracket, add it to the
  // stack. If it is a closing bracket, check that the top of the stack matches.
  // If it doesn't, it isn't balanced. If anything other than the brackets,
  // disregard it. If the end of the stack is reached, it is balanced.
  stack<char> brackers;
  for (char& c:s) {
    //cout << "c: " << c << "\n";
    //cout << "top: " << brackers.top() << "\n";
    if (c=='{'){
      brackers.push(c); 
      //cout<<"added {\n"; 
      continue;
    }
    else if (c=='['){
      brackers.push(c); 
      //cout<<"added [\n"; 
      continue;
    }
    else if (c=='('){
      brackers.push(c); 
      //cout<<"added (\n"; 
      continue;
    }
    else if (c==')'){
      if (!brackers.empty()){
        if (brackers.top()=='('){
          brackers.pop(); 
          //cout<<"removed (\n"; 
          continue;
        }
        else {
          cout << "NO\n"; 
          return "NO";
        }
      }
      else {
        cout << "NO\n"; 
        return "NO";
      }
    }
    else if (c==']'){
      if (!brackers.empty()){
        if (brackers.top()=='['){
          brackers.pop(); 
          //cout<<"removed [\n"; 
          continue;
        }
        else {
          cout << "NO\n"; 
          return "NO";
        }
      }
      else {
        cout << "NO\n"; 
        return "NO";
      }
    }
    else if (c=='}'){
      if (!brackers.empty()){
        if (brackers.top()=='{'){
          brackers.pop(); 
          //cout<<"removed {\n"; 
          continue;
        }
        else {
          cout << "NO\n"; 
          return "NO";
        }
      }
      else {
        cout << "NO\n"; 
        return "NO";
      }
    }
    else {continue;}
    
    }
  if (brackers.empty()) {cout << "YES\n"; return "YES";}
  else {cout<< "NO\n"; return "NO\n";}
  
  return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
