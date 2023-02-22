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
    vi v(m);
    for (int &x: v)cin >> x;
    map<int, int> ck;
    set<pi> used;
    int r = n * 3 - 2;
    for (int x: v) {
        for (int y: {x - 1, x + 1}) {
            if (y <= 0 || y > n)continue;
            if (ck.count(y))used.insert({x, y});
        }
        used.insert({x, x});
        ck[x] = 1;
    }
    cout << r - int(used.size()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
