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
    int n, m;
    cin >> n >> m;
    vi v(n);
    set<int> ck;
    for (int &x: v)cin >> x;
    queue<pi> q;

    for (int x: v)q.push({x, 0}), ck.insert(x);
    vi r;
    ll rst = 0;
    while (r.size() < m + n) {
        auto [x, dis] = q.front();
        q.pop();

        r.pb(x);
        rst += dis;
        for (int i = -1; i <= 1; i++) {
            int y = x + i;
            if (!ck.count(y)) {
                ck.insert(y);
                q.push({y, dis + 1});
            }
        }
    }
    cout << rst << endl;
    for (int i = n; i < r.size(); i++)cout << r[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
