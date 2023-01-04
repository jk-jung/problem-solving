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
    vi v(n);
    for (int &x: v)cin >> x;

    int r = 0;
    {
        priority_queue<int> q;
        ll s = 0;
        for (int i = m; i < n; i++) {
            q.push(-v[i]);
            s += v[i];
            if (s < 0) {
                s += q.top() * 2;
                r++;
                q.pop();
            }
        }
    }

    if (m - 2 >= 0) {
        ll s = v[m - 1];
        if (s > 0)s *= -1, r++;
        priority_queue<int> q;
        for (int i = m - 2; i >= 1; i--) {
            q.push(v[i]);
            s += v[i];
            if (s > 0) {
                s -= q.top() * 2;
                q.pop();
                r++;
            }
        }
    }

    cout << r << endl;
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
