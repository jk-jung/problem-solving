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

int n;
int a[100005];


pi calc(int s, int e, int q, int st = 2) {
    int r = st;
    int cur = -1;
    for (int i = s; i <= e; i++) {
        if (i == q)continue;
        if (cur < a[i]) {
            cur = a[i];
            r--;
        }
    }
    return pi(r, a[q]);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    vi t;
    t.pb(0);
    for (int i = 1; i < n; i++) {
        if (a[i] > a[t.back()])t.pb(i);
    }
    set<int> s;
    for (int i = 1; i <= n; i++)s.insert(i);
    for (int x: t)s.erase(a[x]);
    pi r = mp(0, (s.empty() ? 1 : *s.begin()));
    for (int i = 2; i < t.size(); i++) {
        r = min(r, calc(t[i - 2], t[i], t[i - 1], 3));
    }
    if (t.size() >= 2) {
        int m = t.size() - 1;
        r = min(r, calc(t[0], t[1], t[0]));
        r = min(r, calc(t[m - 1], n - 1, t[m]));
    } else if (t.size() == 1) {
        r = min(r, calc(0, n - 1, t[0], 1));
    }
    cout << r.S << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
