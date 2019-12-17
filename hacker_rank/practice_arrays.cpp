
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Input Format:
 * The first line of the input contains N, where N is the number of integers. 
 * The next line contains N integers separated by a space.
 * 
 * Constraints:
 * 1 <= N <= 1000
 * 1 <= A_i <= 10000, where A_i is the i^th integer in the array.
 *
 * Output Format
 *
 * Print the N integers of the array in the reverse order in a single line 
 * separated by a space.
 *
 * Sample Input:
 * 4
 * 1 4 3 2
 *
 * Sample Output:
 * 2 3 4 1
 **/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N, i = 0;
    cin >> N; // take in the size of the array N
    int *A = new int[N]; // declare a pointer A to the address of the memory block of size N
    while(cin >> A[i++]); // take in each element of the array
    while(cout<<A[--N]<<" " && N); // print each element of the array starting at the end and stopping when N=0 (by and statement)
    delete[] A; // remove the memory block allocated
    return 0;
}
