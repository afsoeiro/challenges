#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, // number of variable-length arrays
        q, // number of queries
        k, // number of elements in each array
        e; // element of an array
    cin >> n >> q;
    
    // A vector of vectors of int.
    vector<vector<int>> dblarr;
    
    // A vector of ints for the query.
    vector<pair<int, int>> queries;
    
    // Grab each array of elements
    for(int i = 0; i < n; i ++) {
        cin >> k;
        vector<int> v2;
        for(int j = 0; j < k; j ++) {
            cin >> e;
            v2.push_back(e);
        }
        dblarr.push_back(v2);
    }
    
    // Grab the queries
    int first, second;
    for(int i = 0; i < q; i ++) {
        cin >> first >> second;
        queries.push_back(make_pair(first, second));
    }
    
    // "Run" the queries and display results
    for(int i = 0; i < queries.size(); i ++) {
        cout << dblarr[queries[i].first][queries[i].second] << endl;
    }
    return 0;
}
