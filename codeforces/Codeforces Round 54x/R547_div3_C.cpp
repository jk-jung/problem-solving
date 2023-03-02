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
    vi v(n), c(n + 1);
    int st = 0, m = 0;
    for (int i = 1, x; i < n; i++) {
        cin >> x;
        st += x;
        v[i] = st;
        m = max(m, st);
    }
    for (int &x: v)x += (n - m);
    for (int x: v) {
        if (x <= 0 || x > n || c[x] == 1) {
            cout << -1;
            return;
        }
        c[x]++;
    }
    for (int x: v)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
