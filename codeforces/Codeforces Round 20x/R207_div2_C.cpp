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
    set<int> ck;
    for (int i = 1; i <= n; i++)ck.insert(i);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        auto it = ck.lower_bound(x);
        vi rm;
        while (it != ck.end() && *it <= y) {
            if (*it != z)
                rm.pb(*it);
            it++;
        }
        for (int x: rm) {
            ck.erase(x);
            r[x] = z;
        }
    }
    for(int i=1; i<=n; i++)cout << r[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
