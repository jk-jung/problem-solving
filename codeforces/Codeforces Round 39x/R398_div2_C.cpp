#include <cstring>
#include <cstdio>
#include <cmath>
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

int n, s, root;
vi v[1000005];
int b[1000005];
vi r;

int dfs(int x) {
    int st = b[x];
    for (int y: v[x]) st += dfs(y);

    if (st == s && x != root) {
        r.pb(x);
        if (r.size() == 2) {
            cout << r[0] << " " << r[1];
            exit(0);
        }
        return 0;
    } else return st;
}

void solve() {
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x >> b[i];
        if (!x)root = i;
        else v[x].pb(i);
        s += b[i];
    }
    if (s % 3)cout << -1;
    else {
        s /= 3;
        dfs(root);
        cout << -1;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
