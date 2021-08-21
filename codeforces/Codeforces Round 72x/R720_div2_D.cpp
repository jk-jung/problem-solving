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
int ter[100005][2];
vector<pi> cut;

int go(int x, int y) {
    ter[x][0] = ter[x][1] = x;
    int cnt = 0;
    for (int z : v[x]) {
        if (z == y)continue;

        int t = go(z, x);
        if (t <= 1 && cnt < 2) {
            cnt++;
            ter[x][0] = ter[x][1];
            ter[x][1] = ter[z][1];
        } else {
            cut.pb({x, z});
        }
    }
    return cnt;
}

void solve() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }

    go(1, 0);

    cout << cut.size() << endl;
    int x = ter[1][0];
    for (int i = 0; i < cut.size(); i++) {
        int y = cut[i].S;

        cout << cut[i].F << " " << y << " " << x <<" " << ter[y][0] << '\n';
        x = ter[y][1];
    }

    cut.clear();
    for (int i = 1; i <= n; i++)v[i].clear();
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
