
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

int n;
vector<pi> v;
int d[100005];

int go(int x) {
    int &r = d[x];
    if (r != -1) return r;
    r = 1;
    if(x == 2){
        x=x;
    }
    int idx = lower_bound(v.begin(), v.end(), mp(v[x].F - v[x].S, 0)) - v.begin();
    if(idx > 0) r = go(idx - 1) + 1;
    return r;
}

void solve() {
    cin >> n;
    v.resize(n);
    for (auto &t: v)cin >> t.F >> t.S;
    sort(v.begin(), v.end());
    memset(d, -1, sizeof(d));
    int r = 0;
    for (int i = 0; i < n; i++)r = max(r, go(i));
    cout << n - r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
