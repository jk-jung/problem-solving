#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define ab(x) (((x)<0)?-(x):(x))


bool solve(int x) {
    if (x % 11 == 0)return true;
    if (x % 111 == 0)return true;

    for(int i=1;;i++){
        x -= 111;
        if( x < 0)return false;
        if (x % 11 == 0) return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (solve(n) ? "YES" : "NO") << endl;
    }
}
