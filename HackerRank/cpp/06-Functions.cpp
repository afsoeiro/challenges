#include <iostream>
#include <cstdio>
using namespace std;

#define GRT(X,Y) (X>Y)?X:Y

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int, int, int, int);

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}

int max_of_four(int a, int b, int c, int d) {
    int ret;
    ret = GRT(a, b);
    ret = GRT(ret, c);
    ret = GRT(ret, d);
    return ret;
}
