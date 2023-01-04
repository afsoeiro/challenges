#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> aux;
    int N;
    int tmp;
    cin >> N;
    while(cin >> tmp)
        aux.push_back(tmp);
    sort(aux.begin(), aux.end());
    for(int i = 0; i < N; i ++) {
        cout << aux[i];
        if(i < N - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}
