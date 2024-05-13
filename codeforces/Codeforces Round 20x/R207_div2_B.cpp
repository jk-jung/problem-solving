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
    vi r(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vi c(4);
        if (r[x])c[r[x]] = 1;
        if (r[y])c[r[y]] = 1;
        if (r[z])c[r[z]] = 1;
        for (int j = 1; j <= 3; j++)
            if (!c[j]) {
                if (r[x] == 0) {
                    r[x] = j;
                }
                else if (r[y] == 0) {
                    r[y] = j;
                }
                else if (r[z] == 0) {
                    r[z] = j;
                }
            }
    }
    for (int i = 1; i <= n; i++)cout << r[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
