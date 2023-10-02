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

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            set<int> c;
            for (int k = i; k <= j; k++)c.insert(v[k]);
            if (c.size() != 1)continue;
            int ok = 1;
            for (int k = 1; k <= i; k++) if (v[k - 1] >= v[k])ok = 0;
            for (int k = j + 1; k < n; k++)if (v[k - 1] <= v[k])ok = 0;
            if (ok) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
