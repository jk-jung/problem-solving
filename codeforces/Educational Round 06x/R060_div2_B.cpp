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
    ll n, m, k;
    cin >> n >> m >> k;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll cnt = m / (k + 1);
    ll r = cnt * k * v[0] + cnt * v[1] + v[0] * (m % (k + 1));
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
