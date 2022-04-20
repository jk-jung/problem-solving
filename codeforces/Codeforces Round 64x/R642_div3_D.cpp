#include <string.h>
#include <stdio.h>
#include <math.h>
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
    vi r(n);
    priority_queue<pair<int, pi>> q;
    q.push({n, {0, n - 1}});
    int k = 0;
    while (q.size()) {
        k++;
        auto[len, seg] = q.top();
        auto[s, e] = seg;
        s = -s;
        q.pop();
        int m = s + (e - s) / 2;
        r[m] = k;
        if (s != m)q.push({m - s, {-s, m - 1}});
        if (m != e)q.push({e - m, {-m - 1, e}});
    }
    for (int x: r)cout << x << " ";
    cout << endl;
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
