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
    deque<pi> q;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        q.push_back({x, i + 1});
    }
    while (q.size() != 1) {
        auto x = q.front();
        q.pop_front();
        x.F -= m;
        if (x.F > 0)q.push_back(x);
    }
    cout << q.front().S << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
