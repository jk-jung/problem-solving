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
    vi v(n), r(n);
    for (int &x: v)cin >> x;

    int cur = 0;
    queue<int> undefined;

    for (int i = 0; i < n; i++) {
        while (i < n && v[i] == cur) undefined.push(i++);
        if (i == n)break;
        int need = v[i] - cur;
        if (need - 1 > undefined.size()) {
            cout << -1 << endl;
            return;
        }
        r[i] = cur++;
        while (cur < v[i]) {
            r[undefined.front()] = cur++;
            undefined.pop();
        }
    }
    while (!undefined.empty())r[undefined.front()] = n + 1, undefined.pop();
    for (int x: r) cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
