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
    vector<pi> v(n);
    int i = 1;
    for (auto &[x, y]: v)cin >> x, y = i++;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll r = 0;
    for (int k = 0; k < n; k++) {
        ll t = v[k].F * k + 1;
        r += t;
    }
    cout << r << endl;
    for(auto [x, y]: v)cout << y <<" ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
