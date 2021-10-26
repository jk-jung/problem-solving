// you can solve it by Union and Find

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

vector<pi> v[200005];

int ck[200005], CK, C;
int st[200005];

int dfs(int x, int who) {
    C ++;
    ck[x] = CK;
    st[x] = who;
    int cnt = who == 1;
    for (auto[y, k]: v[x]) {
        int nw = k == 'i' ? 1 : 2;
        if (who == 1) nw = 3 - nw;

        if (ck[y] == CK) {
            if (st[y] != nw) return -1;
        } else {
            int t = dfs(y, nw);
            if(t == -1)return -1;
            cnt += t;
        }
    }

    return cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++)v[i].clear();
    for (int i = 0, s, e; i < m; i++) {
        string k;
        cin >> s >> e >> k;
        v[--s].pb({--e, k[0]});
        v[e].pb({s, k[0]});
    }

    CK++;

    int r = 0;
    for (int i = 0; i < n; i++) {
        if (ck[i] == CK)continue;
        C = 0;
        int c = dfs(i, 1);
        if(c == -1) {
            cout << -1 <<'\n';
            return;
        }
        r += max(c, C - c);
    }
    cout << r <<'\n';
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
