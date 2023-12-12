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
    vi r(n, -1);
    for (int &x: v)cin >> x, x--;
    queue<int> q;
    q.push(0);
    r[0] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vi t = {x - 1, x + 1, v[x]};
        for (int y: t) {
            if (y < 0 || y >= n || r[y] != -1)continue;
            r[y] = r[x] + 1;
            q.push(y);
        }
    }
    for (int x: r)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
