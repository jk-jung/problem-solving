#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

vi v[555];
set<int> children[555];
int n;
int m;
queue<int> order;
vi r;

void dfs(int x, int y = 0) {
    bool is_leaf = true;
    for (int i: v[x]) {
        if (i == y)continue;
        is_leaf = false;
        dfs(i, x);
        for (int j: children[i]) {
            children[x].insert(j);
        }
    }
    if (is_leaf)
        children[x].insert(x);
}


void go(int x, int y = 0) {
    r.pb(x);
    while(!order.empty()) {
        int z = order.front();
        if(z == x){
            order.pop();
            break;
        }

        bool ok = false;
        for(int i: v[x]) {
            if (i == y)continue;
            if (children[i].count(z)) {
                go(i, x);
                r.pb(x);
                ok = true;
                break;
            }
        }
        if(!ok)break;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1);
    m = children[1].size();
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        order.push(x);
    }


    go(1);
    if(r.size() != n * 2 -1){
        cout << "-1" << endl;
        return;
    }
    for (int x: r)cout << x << " ";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
