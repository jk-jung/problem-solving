#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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
vi v[100005];
int a[100005][2];
ll d[100005][2];


ll go(int x, int p, int k) {

    ll &r = d[x][k];
    if(r!=-1) return r;

    for (int i = 0; i < 2; i++) {
        ll t = p == -1 ? 0 : ab(a[x][i] - a[p][k]);
        for (int y: v[x]) {
            if (y == p) continue;
            t += go(y, x, i);
        }
        r = max(r, t);
    }
    return r;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        v[i].clear();
        d[i][0] = d[i][1] = -1;
    }

    for (int i = 1; i <= n; i++)cin >> a[i][0] >> a[i][1];
    for (int i = 1; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }

    cout << go(1, -1, 0) << endl;
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
