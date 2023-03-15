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
    int n, m, k;
    cin >> n >> m >> k;
    vi v(n), t;
    for (int &x: v)cin >> x;

    for (int i = 1; i < n; i++)t.pb(v[i] - v[i - 1] - 1);
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    int r = 1;
    for (int x: t) r += x + 1;
    for (int i = 0; i < k - 1; i++)r -= t[i];
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
