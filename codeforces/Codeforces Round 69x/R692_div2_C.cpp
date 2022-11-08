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

int a[200005];
int ck[200005];

bool dfs(int x, int root) {
    if (x == 0 || ck[x]) return false;
    ck[x] = 1;
    if (x != root && a[x] == root) return true;
    return dfs(a[x], root);
}

void solve() {
    int n, m, r = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)a[i] = ck[i] = 0;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        a[x] = y;
        if (x != y) r++;
    }


    for (int i = 1; i <= n; i++)
        if (a[i] && !ck[i] && dfs(i, i)) {
            r++;
        }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
