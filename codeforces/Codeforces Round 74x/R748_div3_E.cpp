#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <set>

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
    int n, k;
    cin >> n >> k;
    vector<vi> v(n);
    set<int> ss;
    vi deg(n), used(n);

    for (int i = 1, s, e; i < n; i++) {
        cin >> s >> e;
        v[--s].pb(--e);
        v[e].pb(s);
        deg[s]++, deg[e]++;
    }
    vi rm;
    for (int i = 0; i < n; i++) {
        ss.insert(i);
        if (deg[i] <= 1)rm.pb(i), used[i] = 1;
    }

    for (int t = 0; t < k; t++) {
        vi nt;
        for (int x: rm) {
            for (int y: v[x]) if (--deg[y] <= 1 && !used[y])
                nt.pb(y), used[y] = 1;
            ss.erase(x);
        }
        rm = nt;
        if (ss.empty())break;
    }
    cout << ss.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
