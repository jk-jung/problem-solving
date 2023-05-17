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
    ll n, d;

    cin >> n >> d;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    int r = 2;
    for (int i = 1; i < n; i++) {
        ll t = (ll) v[i] - v[i - 1];
        if (t == d * 2) r++;
        else if (t > d * 2)r += 2;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
