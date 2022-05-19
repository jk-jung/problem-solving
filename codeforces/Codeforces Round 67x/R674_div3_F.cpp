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

int n;
string s;
ll a = 0, b = 0;
ll mod = 1000000007;

void add(ll &x, ll y) {
    x = (x + y) % mod;
}

void solve() {
    cin >> n >> s;

    ll r = 0;
    ll base = 1;
    for (char x: s) {
        if (x == 'a')add(a, base);
        if (x == 'b')add(b, a);
        if (x == 'c')add(r, b);
        if (x == '?') {
            ll aa = a, bb = b, rr = r;
            add(a, aa * 2 + base);
            add(b, bb * 2 + aa);
            add(r, rr * 2 + bb);
            base = (base * 3) % mod;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
