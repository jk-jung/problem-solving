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


void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &x: v)cin >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool ok = true;
            for (int k = 0; k < n; k++)if (k != i && v[k][j] == v[i][j])ok = false;
            for (int k = 0; k < m; k++)if (k != j && v[i][k] == v[i][j])ok = false;
            if (ok)cout << v[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
