#include <string.h>
#include <stdio.h>
#include <math.h>
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

vi v[100005];
int r[100005], n;

void dfs(int x, int y, int st) {
    r[x] = (int)v[x].size() * st;
    for (int z: v[x])if (z != y)dfs(z, x, st * -1);
}

void solve() {
    cin >> n;
    for (int i = 1, s, e; i < n; i++) {
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }

    dfs(1, -1, 1);

    for (int i = 1; i <= n; i++) {
        cout << r[i] << " ";
        v[i].clear();
    }
    cout << endl;
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
