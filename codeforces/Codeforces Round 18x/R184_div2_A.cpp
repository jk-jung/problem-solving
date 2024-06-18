#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n;
    cin >> n;
    vi v(n), cnt(5), r;
    for (auto &x: v)cin >> x;

    for (int a: v) {
        if (a == 0) {
            cnt[0] = 1;
            continue;
        }
        if (a == 100) {
            cnt[1] = 1;
            continue;
        }
        if (a % 10 == 0) {
            cnt[2] = a;
            continue;
        }
        if (a < 10) {
            cnt[3] = a;
            continue;
        }
        cnt[4] = a;
    }
    if (cnt[0]) r.pb(0);
    if (cnt[1]) r.pb(100);
    if (cnt[2]) r.pb(cnt[2]);
    if (cnt[3]) r.pb(cnt[3]);
    if (!cnt[2] && !cnt[3] && cnt[4]) r.pb(cnt[4]);
    cout << r.size() << endl;
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
