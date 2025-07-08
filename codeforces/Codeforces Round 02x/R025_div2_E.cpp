#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

ll pw[300005];
ll MOD = 1000000009;
ll K = 29;

string match(string &a, string &b) {
    int r = a.size();
    ll A = 0, B = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int j = a.size() - i - 1;
        A = (A + a[i] * pw[j]) % MOD;
        if (j < b.size()) {
            B = (B * K + b[j]) % MOD;
        } else {
            B = (B * K) % MOD;
            A = ((A - a[i + b.size()] * pw[j - b.size()]) % MOD + MOD) % MOD;
        }
        if (A == B) r = i;
    }


    if (r == a.size())return a + b;
    if (a.size() - r >= b.size())return a;
    return a.substr(0, r) + b;
}

int calc(string &a, string &b, string &c) {
    string d = match(a, b);
    return int(match(d, c).size());
}

void solve() {
    pw[0] = 1;
    for (int i = 1; i <= 300000; i++)pw[i] = pw[i - 1] * K % (MOD);
    string a, b, c;
    cin >> a >> b >> c;
    int r = 1 << 30;
    r = min(r, calc(a, b, c));
    r = min(r, calc(a, c, b));
    r = min(r, calc(b, a, c));
    r = min(r, calc(b, c, a));
    r = min(r, calc(c, a, b));
    r = min(r, calc(c, b, a));

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
