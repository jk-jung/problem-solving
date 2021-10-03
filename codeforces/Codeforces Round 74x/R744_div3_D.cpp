#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
    priority_queue<pi> q;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        if (a)q.push({a, i});
    }
    vector<pi> r;
    while (q.size() >= 2) {
        pi a = q.top();
        q.pop();
        pi b = q.top();
        q.pop();

        r.pb({a.S, b.S});
        if (--a.F) q.push(a);
        if (--b.F) q.push(b);
    }

    cout << r.size() << '\n';
    for (auto[s, e]: r) cout << s << " " << e << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
