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
    int n, t = 0;
    cin >> n;
    vi v(n);
    ll r = 0;
    for (int &x: v)cin >> x, r += ab(x);
    v.pb(1);
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == 0 && v[i - 1] < 0) v[i] = -1;
        if (v[i] > 0 && v[i - 1] < 0)t++;
    }
    cout << r << " " << t << endl;
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
