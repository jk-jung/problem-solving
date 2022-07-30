/*
 * Idea
 * the numbers providing contribution are only
 * at the "peak" and "valley"points of the array.
 */

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

int n;
vi a, b, ck, nxt;

int dfs(int x) {
    ck[x] = 1;
    int y = nxt[x];
    return 1 + (ck[y] ? 0 : dfs(y));
}

void solve() {
    cin >> n;
    a.resize(n), b.resize(n), nxt.resize(n);
    for (int &x: a)cin >> x, x--;
    for (int &x: b)cin >> x, x--;

    for (int i = 0; i < n; i++)nxt[a[i]] = b[i];

    ck.clear(), ck.resize(n);
    ll r = 0;
    int L = 1, R = n;
    for (int i = 0; i < n; i++) {
        if (!ck[a[i]]) {
            int cy = dfs(a[i]);
            for (int k = 0; k < cy / 2; k++, R--, L++) {
                r += R * 2 - L * 2;
            }
        }
    }
    cout << r << endl;
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