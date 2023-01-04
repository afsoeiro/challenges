#include <iostream>
#include <cstdio>
using namespace std;
string convert(int);

int main() {
    // Complete the code.
    int a;
    int b;
    cin >> a >> b;
    for(int i = a; i <= b; i ++)
        cout << convert(i) << endl;
    return 0;
}
string convert(int number) {
    string conversionMatrix[] = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
     };
     if(number > 9) {
        if(number % 2)
            return "odd";
        return "even";
     }
     return conversionMatrix[number - 1];
}
