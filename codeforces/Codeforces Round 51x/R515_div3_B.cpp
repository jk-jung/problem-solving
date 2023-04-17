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

int n, k;
vi v;
int d[1005];

int go(int idx) {
    if (idx == n - 1)return 0;
    int &r = d[idx + 1];
    if (r != -1) return r;
    r = 1 << 20;
    int m = min(n, k);
    if (idx != -1) m = min(n, idx + k + k);
    for (int i = idx + 1; i < m; i++) {
        if (i == n - 1 && i < idx + k && idx != -1)r = 0;
        else if (v[i]) r = min(r, go(i) + 1);
    }
    return r;
}

void solve() {
    cin >> n >> k;
    v.resize(n);
    for (int &x: v)cin >> x;
    memset(d, -1, sizeof(d));
    int t = go(-1);
    if (t > n)t = -1;
    cout << t << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
