#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back

// 1: win
// 2: loss
int go(int n) {
    if (n % 2 == 1) return 2;
    int c = 0;
    while(n % 2 == 0)n /= 2, c ++;

    if (n == 1 && c % 2 == 1) return 2;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (go(n) == 1 ? "Alice" : "Bob") << endl;
    }
}

