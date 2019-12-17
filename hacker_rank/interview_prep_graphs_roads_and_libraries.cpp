/**

Problem: https://www.hackerrank.com/challenges/torque-and-development?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=graphs

Input that is failing:
1
6 6 2 5
1 3
3 4
2 4
1 2
2 3
5 6

**/
#include <bits/stdc++.h>
//#include <execinfo.h>
//#include <signal.h>
//#include <unistd.h>

using namespace std;

vector<string> split_string(string);

/*
void handler(int sig) {
  void *array[10];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}
*/

long dfs(int c, vector<int> visited, vector<vector<int>> cities){
  visited[c]=1;
  long count = 0;
  cout << "c1: " << c << "\n";
  for (uint j = 0; j < cities[c].size(); j++) {
    cout << "c: " << c << "; j: " << j << "\n";
    cout << "cities[" << c << "][" << j << "]: " << cities[c][j] << "\n";
    
    if (visited[(cities[c][j]-1)]==0) {
      count += dfs((cities[c][j]-1), visited, cities)+1;
    }
  }
  return count;
}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
  //if (c_road>=c_lib) {return c_road*c_lib;}
  // initialize everything including visited to false
  vector<int> visited(n);
  long libraries = 0, roads = 0;
  for (int a = 0; a <= n; a++) {
    visited[a]=0;
  }

  for (int b = 0; b < n; b++) {
    cout << "b: " << b << "\n";
    if (!visited[b]) {
      roads += dfs(b, visited, cities);
      libraries++; // this should count all closed graphs
    }
    /*
    visited.push_back(cities[i][0]);
    for (int j = 0; j < cities[i].size(); j++) {
      cout << cities[i][j] << " ";
    }
    cout << "\n";
    */
  }
  long cost = (c_lib * libraries) + (c_road * roads);
  cout << "libraries: " << libraries << "; roads: " << roads << "; cost: " << cost;
  return cost;
}

int main()
{
    //signal(SIGSEGV, handler);
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
