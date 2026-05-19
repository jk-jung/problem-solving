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

void solve() {
    int a, b;
    cin >> a >> b;
    int c = a * b;
    ll r = 0;
    for (ll i = 0; i <= c; i++) {
        ll y = b - (i + a - 1) / a;
        ll aa = (y + 1) * y / 2;
        ll bb = (i + 1) * i / 2;
        r = max(r, aa * (i + 1) + bb * (y + 1));
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
