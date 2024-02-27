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

int n, m;
string a;
vi v;
vi rr;

int go(int i, int s, int e) {
    if (i == n)return 1;
    int r = 0;
    if (a[i] == 'L') {
        r = v[s] * go(i + 1, s + 1, e) % m;
    } else {
        r = v[e] * go(i + 1, s, e - 1) % m;
    }
    rr.pb(r);
    return r;
}

void solve() {
    cin >> n >> m;
    v.resize(n);
    rr.clear();
    for (int &x: v)cin >> x;
    cin >> a;

    go(0, 0, n - 1);
    for (int i = n - 1; i >= 0; i--)cout << rr[i] << " ";
    cout << endl;
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
