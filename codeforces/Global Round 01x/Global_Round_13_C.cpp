#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
#include <map>
#include <array>
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
    int n;
    cin >> n;
    ll r = 0;
    vector<ll> v(n), c(n + 1);
    for (ll &x: v)cin >> x;

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if(c[i] > v[i] - 1) {
            cnt += c[i] - v[i] + 1;
            c[i] = v[i] - 1;
        }
        r += max(0ll, v[i] - 1 - c[i]);
        c[i + 1] += cnt;
        cnt = 0;
        for (int j = i + 2; j < n && v[i] >= 2; j++, v[i]--) {
            c[j] ++;
        }
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
