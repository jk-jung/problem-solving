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
    int n, m;
    cin >> n >> m;
    vi v[100005], ss(100005);

    while (n--) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    set<int> s;
    for (int i = 0; i <= m; i++) {
        if (!v[i].empty()) {
            s.insert(i);
            sort(v[i].begin(), v[i].end());
            reverse(v[i].begin(), v[i].end());
        }
    }

    int r = 0, cur = 0;
    for (int i = 0; !s.empty(); i++) {
        vi rm;
        for (int x: s) {
            if (v[x].size() == i)rm.pb(x);
            else if(v[x].size() > i && ss[x] + v[x][i] <= 0)rm.pb(x);
        }
        for (int x: rm) {
            s.erase(x);
            cur -= ss[x];
        }
        for (int x: s) {
            cur += v[x][i];
            ss[x] += v[x][i];
        }
        r = max(r, cur);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
