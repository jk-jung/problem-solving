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

int n;
int a[1005];
int b[1005];
int vis[1005];
vi X, Y;

void go(int x) {
    if (x < 0 || x >= n)return;
    if (vis[x])return;
    X.pb(x);
    vis[x] = 1;
    Y.pb(a[x]);
    for (int i = 0; i < n; i++) {
        if (ab(i - x) == b[i] || ab(i - x) == b[x])
            go(i);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i], a[i]--;
    for (int i = 0; i < n; i++)cin >> b[i];


    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            go(i);

            sort(X.begin(), X.end());
            sort(Y.begin(), Y.end());
            if (X != Y) {
                cout << "NO" << endl;
                return;
            }

            X.clear();
            Y.clear();
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
