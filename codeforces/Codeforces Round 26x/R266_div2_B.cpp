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

ll n;
ll rr = 1ll << 60;
ll r1, r2;

void check(ll a, ll b, ll sw) {
    b = max(b, (n + a - 1) / a);
    if (a * b < rr) {
        rr = a * b, r1 = a, r2 = b;
        if (sw)swap(r1, r2);
    }
}

void solve() {
    ll a, b;
    cin >> n >> a >> b;
    n *= 6;


    for (int i = 0; i < 100000; i++)check(a + i, b, 0);
    for (int i = 0; i < 100000; i++)check(b + i, a, 1);
    cout << r1 * r2 << endl;
    cout << r1 << ' ' << r2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
