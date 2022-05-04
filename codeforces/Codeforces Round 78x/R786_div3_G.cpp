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

int n, m;
vi v[200005];
int out[200005];
int d[200005];

int go(int x) {
    int &r = d[x];
    if (r) return r;
    r = 1;

    if (v[x].size() >= 2) {
        for (int y: v[x]) if (out[y] >= 2)r = max(r, go(y) + 1);
    }
    return r;
}

void solve() {
    cin >> n >> m;
    for (int i = 0, s, e; i < m; i++) {
        cin >> s >> e;
        v[e].pb(s);
        out[s]++;
    }
    int r = 0;
    for (int i = 1; i <= n; i++)r = max(r, go(i));
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
