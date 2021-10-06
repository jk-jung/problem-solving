#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
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
    ll n, m, k;
    cin >> n >> m >> k;
    ll M = n * (n - 1) / 2;
    if (m < n - 1) {
        cout << "NO\n";
    } else if (m > M) {
        cout << "NO\n";
    } else {
        int d = 0;
        if (n == 1) d = 0;
        else if (m == M) d = 1;
        else d = 2;

        cout << (d < k - 1 ? "YES" : "NO") << '\n';
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
