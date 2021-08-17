#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

void solve() {
    ll x, y;
    cin >> x >> y;
    if (y == 1) {
        cout << "NO\n";
        return;
    }

    if ( y == 2 ) {
        cout << "YES\n";
        cout << x << " " << x * 2 << " " << x * 3 << '\n';
    }
    else {
        cout << "YES\n";
        cout << x << " " << x * (y - 1) << " " << x * y << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
