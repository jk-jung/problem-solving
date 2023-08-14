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
    vi a(n), b(n), r(n);
    for (int i = 0; i < n; i++)cin >> a[i] >> b[i];

    queue<int> q;
    for (int t = 1; t <= 5000; t++) {
        for (int i = 0; i < n; i++)if (a[i] == t)q.push(i);
        while (!q.empty() && b[q.front()] < t)q.pop();
        if (!q.empty()) {
            r[q.front()] = t;
            q.pop();
        }
    }
    for (int x: r)cout << x << " ";
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
