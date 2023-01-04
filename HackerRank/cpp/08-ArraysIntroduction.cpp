#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    stringstream ss;
    
    // Grab the amount of numbers
    cin >> N;
    
    // Create an array for it
    int arr[N];
    
    // We will need a counter to store things in an array
    int i = 0;
    int number;
    while(cin >> number){
        arr[i++] = number;
    }
    
    // Time to print them in reverse order...
    for(i = N-1; i >= 0; i --) {
        cout << arr[i];
        if(i)
            cout << " ";
        else
            cout << endl;
    }  
    return 0;
}
