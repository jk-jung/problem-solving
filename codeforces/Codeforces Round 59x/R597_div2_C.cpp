#include <cstring>
#include <cstdio>
#include <cmath>
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

ll f[100005];
ll mod = 1000000007;

void solve() {
    f[0] = f[1] = 1;
    for (int i = 2; i <= 100000; i++)f[i] = (f[i - 1] + f[i - 2]) % mod;
    string s;
    cin >> s;
    s += ' ';
    char last = ' ';
    vi v;
    int cur = 0;
    for (char x: s) {
        if (x == 'm' || x == 'w') {
            cout << 0 << endl;
            return;
        }
        if (last == x && (x == 'n' || x == 'u')) cur++;
        else {
            if (cur)v.pb(cur);
            cur = 0;
            if (x == 'n' || x == 'u')cur = 1;
        }
        last = x;
    }
    ll r = 1;
    for (int x: v)r = (r * f[x]) % mod;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
