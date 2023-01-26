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

bool sf(pi x, pi y) { return ab(x.S) < ab(y.S); }

void solve() {
    int n;
    cin >> n;
    vector<pi> v(n);
    int i = 0;
    for (auto &[x, y]: v) {
        cin >> x, y = i++;
        x = x < 0 ? x : -x - 1;
    }

    if (v.size() % 2) {
        sort(v.begin(), v.end());
        v[0].F = -v[0].F - 1;
        sort(v.begin(), v.end(), sf);
    }
    for (auto [x, y]: v)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
