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

int n;
int p[100005];
int c[100005];
vi v[100005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i];
        v[p[i]].pb(i);
    }
    int k = 0;
    for (int x = 1; x <= n; x++) {
        int tot = 1, tt = c[x];
        for (int y: v[x])if (y != p[x])tot++, tt += c[y];
        if (tot == tt) {
            k++;
            cout << x << " ";
        }
    }
    if (k == 0)cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
