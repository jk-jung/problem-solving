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
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    vi t = v;
    sort(t.begin(), t.end());
    vi r;
    for (int i = 0; i < n; i++)if (v[i] == t[0])r.pb(i);
    int k = 1 << 30;
    for (int i = 1; i < r.size(); i++)k = min(k, r[i] - r[i - 1]);
    cout << k << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
