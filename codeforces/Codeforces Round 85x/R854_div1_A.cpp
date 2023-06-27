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
    int n, m;
    cin >> n >> m;
    vi v(m);
    for (int &x: v)cin >> x;
    vi r(n + 1 + m, 1 << 30);
    int tt = 0;
    set<int> ck;
    for (int x: v) {
        ck.insert(x);
        int pos = n - ck.size() + 1;
        if(pos < 0)break;
        r[pos] = min(r[pos], ++tt);
    }
    for (int i = 1; i <= n; i++) {
        int x = r[i];
        cout << (x == (1 << 30) ? -1 : x) << " ";
    }
    cout << endl;
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
