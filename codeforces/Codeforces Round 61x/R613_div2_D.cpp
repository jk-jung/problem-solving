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

vi v;

int go(int k, int s, int e, int cur = 0, int tmp = 0) {
    if (k == -1)return tmp;
    int nxt = cur | (1 << k);
    int m = upper_bound(v.begin(), v.end(), nxt - 1) - v.begin();
    int r;
    if (m == s) r = go(k - 1, s, e, nxt, tmp);
    else if (m == e + 1) r = go(k - 1, s, e, cur, tmp);
    else {
        r = min(
                go(k - 1, s, m - 1, cur, tmp | (1 << k)),
                go(k - 1, m, e, nxt, tmp | (1 << k))
        );
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    v.resize(n);

    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << go(30, 0, (int)v.size() - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
