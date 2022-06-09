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

string s, t;
int p[205];
int ck[205];
int n;
vi v;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


void dfs(int x) {
    if (ck[x])return;
    ck[x] = 1;
    v.pb(x);
    dfs(p[x]);
}

ll calc() {
    int m = v.size();
    ll r = 0;
    while (true) {
        char x = t[v[0]];
        for (int i = 0; i < m - 1; i++) {
            t[v[i]] = t[v[i + 1]];
        }
        t[v.back()] = x;

        bool ok = true;
        for (int y: v)if (s[y] != t[y])ok = false;

        r++;
        if (ok)break;
    }
    return r;
}

void solve() {
    cin >> n;
    cin >> s;
    t = s;
    for (int i = 0; i < n; i++)cin >> p[i], p[i]--, ck[i] = 0;

    ll r = 1;
    for (int i = 0; i < n; i++) {
        if (!ck[i]) {
            v.clear();
            dfs(i);
            r = lcm(r, calc());
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
