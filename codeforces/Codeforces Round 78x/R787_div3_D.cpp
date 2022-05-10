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

vi v[200005];
vector<vi> r;
int n;

void dfs(int x, vi &t) {
    t.pb(x);
    for (int i = 0; i < v[x].size(); i++) {
        if(i == 0)dfs(v[x][i], t);
        else {
            r.pb(vi());
            dfs(v[x][i], r.back());
        }
    }
}

void solve() {
    cin >> n;
    int root;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x != i)v[x].pb(i);
        else root = x;
    }

    r.pb(vi());
    dfs(root, r[0]);
    cout << r.size() << endl;
    for(auto &t: r) {
        cout << t.size() << endl;
        for(int x:t)cout << x <<" ";
        cout << endl;
    }
    cout << endl;

    for (int i = 1; i <= n; i++)v[i].clear();
    r.clear();
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