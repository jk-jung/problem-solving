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
    int n, k;
    cin >> n >> k;
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x;
    for (auto &[x, y]: v)cin >> y;
    sort(v.begin(), v.end());

    ll t = k;
    priority_queue<int> q1, q2;
    for (auto [x, y]: v)q2.push(-y);
    int i = 0;
    while(i < n) {
        int x = v[i].F, y = v[i].S;
        if (t >= x) {
            q1.push(-y);
            i ++;
            continue;
        }
        while (!q1.empty() && !q2.empty() && q1.top() == q2.top()) {
            q1.pop();
            q2.pop();
        }
        k += q2.top();
        t += k;
        if (k <= 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
