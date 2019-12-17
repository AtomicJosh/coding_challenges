
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  long long n, q;
  stack<long long> stacky, tracker;
  scanf("%lld", &n);
  while (n--) {
    scanf("%lld", &q);
    switch(q){
      case 1: {
                long long e;
                scanf("%lld", &e);
                stacky.push(e);
                //if (e>maxy) {maxy=e;}
                if (!tracker.empty()) {
                  if (tracker.top()<e) {tracker.push(e);}
                  else {tracker.push(tracker.top());}
                } 
                else {
                  tracker.push(e);
                }
                continue;
              };
      case 2: {
                if (!stacky.empty()) {tracker.pop(); stacky.pop();}
                continue;
              };
      case 3: {
                cout<<tracker.top()<<"\n";
                continue;
              };
      default: {cout << "Incorrect input\n"; continue;}
    }
  }
  return 0;
}
