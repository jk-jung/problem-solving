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

char CC = 0;
char ck[19][512][2520];
ll d[19][512][2520];
map<int, ll> d2;
string t;

ll go(int idx, int st, int remainder, int eq) {
    if (idx == -1) {
        for (int i = 0; i < 10; i++)if ((st >> i & 1) && remainder % (i + 1) != 0) return 0;
        return 1;
    }

    int key = idx * 512 * 2520 + st * 2520 + remainder;
    if (eq) {
        if (d2.count(key))
            return d2[key];
    } else {
        if (ck[idx][st][remainder] == CC)
            return d[idx][st][remainder];
        ck[idx][st][remainder] = CC;
    }

    ll &r = eq ? d2[key] : d[idx][st][remainder];
    r = 0;
    for (int j = 0; j <= (eq ? t[idx] - '0' : 9); j++) {
        int nxt = st | (j == 0 ? 0 : 1 << (j - 1));
        r += go(idx - 1, nxt, (remainder * 10 + j) % 2520, eq && j == t[idx] - '0');
    }
    return r;

}

ll count(ll x) {
    d2.clear();
    t = to_string(x);
    reverse(t.begin(), t.end());
    ll r = 0;
    CC = 1;
    for (int i = 0; i <= t.back() - '0'; i++) {
        r += go(t.size() - 2, i == 0 ? 0 : 1 << (i - 1), i, i == t.back() - '0');
    }
    return r;
}

void process() {
    ll a, b;
    cin >> a >> b;
    cout << count(b) - count(a - 1) << endl;
}

void solve() {
    int n;
    cin >> n;
    while (n--)
        process();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
