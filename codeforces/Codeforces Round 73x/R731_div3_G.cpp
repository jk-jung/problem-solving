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

class SCC {
public:
    int n, ord, scc_id;
    vector<vector<int>> *v, scc;
    vector<int> order, node2scc;
    stack<int> st;

    void init(vector<vector<int>> &_v) {
        v = &_v;
        n = (int) v->size();
        ord = scc_id = 0;

        scc.clear();
        order.clear(), order.resize(n, -1);
        node2scc.clear(), node2scc.resize(n, -1);
        while (!st.empty())st.pop();

        for (int i = 0; i < n; i++) {
            if (order[i] != -1) continue;
            dfs(i);
        }
    }

    int dfs(int x) {
        order[x] = ord++;
        st.push(x);

        int parent = order[x];
        for (int y : (*v)[x]) {
            if (order[y] == -1) parent = min(parent, dfs(y));
            else if (node2scc[y] == -1) parent = min(parent, order[y]);
        }

        if (parent == order[x]) {
            vector<int> nodes;
            while (true) {
                int y = st.top();
                st.pop();
                node2scc[y] = scc_id;
                nodes.pb(y);
                if (y == x)break;
            }
            scc.pb(nodes);
            scc_id++;
        }

        return parent;
    }
} scc;

int n, m;
vector<int> self_cycle, d;
vector<vector<int>> v, rv;

int go(int x) {
    int sx = scc.node2scc[x];

    int &r = d[sx];
    if (r != -1) return r;

    r = 0;
    for (int nx: scc.scc[sx]) {
        for (int y : rv[nx]) {
            int t = go(y);
            if (t == -2) r = -2;
            else if (r != -2)r = min(10, r + t);
        }
    }
    if (r != 0 && (self_cycle[x] || scc.scc[sx].size() > 1))r = -2;
    return r;
}

void solve() {
    cin >> n >> m;
    v.clear(), v.resize(n);
    rv.clear(), rv.resize(n);
    d.clear(), d.resize(n, -1);
    self_cycle.clear(), self_cycle.resize(n, 0);

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        v[s].pb(e);
        rv[e].pb(s);
        if (s == e)self_cycle[s] = 1;
    }
    scc.init(v);
    int nx = scc.node2scc[0];
    d[nx] = self_cycle[0] || scc.scc[nx].size() > 1 ? -2 : 1;

    for (int i = 0; i < n; i++) {
        int r = go(i);
        if (r == -2)r = -1;
        else if (r > 1) r = 2;
        cout << r << " ";
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
