#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)cin >> v[i];

    int m = max(1, n - 200);
    ll r = -99999999999ll;
    for (int i = m + 1; i <= n; i++) {
        for (int j = m; j < i; j++)r = max(r, ll(i) * j - k * (v[i] | v[j]));
    }
    cout << r << endl;
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
