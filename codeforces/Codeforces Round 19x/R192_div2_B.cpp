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
    vi deg(n);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        deg[a - 1]++;
        deg[b - 1]++;
    }
    for (int i = 0; i < n; i++) {
        if (deg[i])continue;
        cout << n - 1 << endl;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
