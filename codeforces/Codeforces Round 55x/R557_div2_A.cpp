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
    int n, h, m;
    cin >> n >> h >> m;
    vi v(n + 1, h);
    while (m--) {
        int s, e, t;
        cin >> s >> e >> t;
        for (int i = s; i <= e; i++)v[i] = min(v[i], t);
    }
    int r = 0;
    for (int x: v)r += x * x;
    cout << r - h * h  << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
