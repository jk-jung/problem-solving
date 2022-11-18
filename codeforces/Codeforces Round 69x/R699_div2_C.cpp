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
    vi a(n), b(n), c(m), r(m, -1);
    map<int, int> ck;
    map<int, queue<int>> q;
    int idx = 0;
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x, ck[x] = idx++;
    idx = 0;
    for (int &x: c)cin >> x, q[x].push(idx++);


    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            queue<int> &t = q[b[i]];
            if (t.empty()) {
                cout << "NO\n";
                return;
            }
            r[t.front()] = i;
            t.pop();
        }
    }
    for (int i = m - 1, last = -1; i >= 0; i--) {
        if (ck.count(c[i]))
            last = ck[c[i]];

        if (r[i] == -1) {
            if (last == -1) {
                cout << "NO\n";
                return;
            }
            r[i] = last;
        }

        last = r[i];
    }
    cout << "YES\n";
    for (int x: r)cout << x + 1 << " ";
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
