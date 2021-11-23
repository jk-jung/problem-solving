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

class State {
public:
    vector<int> st;
    map<pi, int> ck;
    int r = 0;

    State(vector<pi> &v) {
        for (int i = 0; i < v.size(); i++)ck[v[i]] = i;
        st.resize(v.size(), 0);
        calc();
    }

    void toggle(pi p) {
        if (ck.count(p) == 0)return;
        st[ck[p]] ^= 1;
        calc();
    }

    void calc() {
        r = 0;
        int cnt = 0;
        for (int x: st) {
            if (x) {
                r += (cnt - 1) * cnt / 2;
                cnt = 0;
            } else cnt++;
        }
        r += (cnt - 1) * cnt / 2;
    }
};

class StateManager {
public:
    int n, m, r = 0;
    vector<State> v;
    map<pi, vi> ck;

    StateManager(int _n, int _m) {
        n = _n, m = _m;
        for (int i = 0; i < n; i++) {
            vector<pi> t;
            for (int j = -1, y = i; j < m && y < n; j++, y++) {
                if (j >= 0) t.pb({y, j});
                if (j + 1 == m)break;
                t.pb({y, j + 1});
            }
            if (t.size() >= 2)
                v.pb(State(t));
        }

        for (int j = 0; j < m; j++) {
            vector<pi> t;
            for (int i = 0, x = j; i < n && x < m; i++, x++) {
                t.pb({i, x});
                if (x + 1 == m)break;
                t.pb({i, x + 1});
            }
            if (t.size() >= 2)
                v.pb(State(t));
        }

        for (int i = 0; i < v.size(); i++) {
            for (auto[p, j]: v[i].ck) {
                ck[p].pb(i);
            }
            r += v[i].r;
        }
    }

    int toggle(pi p) {
        for(auto i : ck[p]) {
            r -= v[i].r;
            v[i].toggle(p);
            r += v[i].r;
        }
        return r;
    }
};

int ck[1005][1005];

void solve() {
    int n, m, q, c;
    cin >> n >> m >> q;
    c = n * m;
    StateManager a(n, m);

    while (q--) {
        int x, y;
        cin >> y >> x;
        x--, y--;

        if (ck[y][x]) c++;
        else c--;
        ck[y][x] ^= 1;
        cout << c + a.toggle({y, x}) << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
