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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll tre[1 << 20];
int sz = 1 << 19;


void up(ll *t, int i, ll v) {
    int s = sz + i;
    while (s) {
        t[s] = gcd(t[s], v);
        s /= 2;
    }
}

ll read(ll *t, int s, int e) {
    s += sz;
    e += sz;
    ll r = 0;
    while (s <= e) {
        if (s % 2 == 1) r = gcd(r, t[s]), s++;
        if (e % 2 == 0) r = gcd(r, t[e]), e--;
        s /= 2;
        e /= 2;
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    map<ll, int> ck, ck2;
    for (sz = 1; sz <= n; sz *= 2);
    for (int i = 0; i <= sz * 2; i++)tre[i] = 0;
    for (int i = 0; i < n; i++)cin >> v[i];

    if(n == 1) {
        cout << 1 << endl;
        return;
    }

    for (int i = 1; i < n; i++) {
        ll t = ab(v[i] - v[i - 1]);
        up(tre, i - 1, t);
    }

    int r = 1;
    for (int i = 0; i < n; i++) {
        int s = i;
        int e = n - 2;
        int k = -1;
        if (i == 0) {
            i = 0;
        }
        while (s <= e) {
            int m = (s + e) / 2;
            ll g = read(tre, i, m);
            if (g >= 2) {
                k = m;
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        if(k-i + 2 == 4) {
            k = k;
        }
        r = max(r, k - i + 2);
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
