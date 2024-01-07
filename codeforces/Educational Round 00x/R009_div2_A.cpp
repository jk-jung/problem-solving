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
    int n, p;
    cin >> n >> p;
    vector<string> v(n);
    for (auto &x: v)cin >> x;

    ll r = 0;
    ll c = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == "half") {
            c *= 2;
        } else {
            c = c * 2 + 1;
        }
        if (c % 2)r += p / 2;
        r += c / 2 * p;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
