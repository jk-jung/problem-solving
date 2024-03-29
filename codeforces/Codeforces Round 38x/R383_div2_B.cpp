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
    int n, y;
    cin >> n >> y;
    vi v(n);
    map<int, int> ck;
    for (int &x: v)cin >> x, ck[x]++;

    ll r = 0;
    for (auto [x, z]: ck) {
        int t = y ^ x;
        if(t < x)continue;
        if (t == x) {
            r += (ll) z * (z - 1) / 2;
        }
        else if (ck.count(t)) {
            r += (ll) z * ck[t];
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
