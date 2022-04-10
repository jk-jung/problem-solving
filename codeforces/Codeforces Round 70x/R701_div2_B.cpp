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
    int n, q, k;
    cin >> n >> q >> k;
    vi v(n);
    vector<ll> cnt(n);
    for (int &x: v)cin >> x;

    for (int i = 1; i < n - 1; i++) {
        int a = v[i - 1];
        int c = v[i + 1];
        cnt[i] = c - a - 2;
        cnt[i] += cnt[i - 1];
    }

    while (q--) {
        int s, e;
        cin >> s >> e;
        s --, e --;
        if (s == e)cout << k - 1 << endl;
        else {
            ll r = cnt[e - 1] - cnt[s];
            r += v[s + 1] - 2;
            r += k - v[e - 1] - 1;
            cout << r << endl;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
}
