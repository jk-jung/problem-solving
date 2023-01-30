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
    int n, s = 0, ss = 0;
    cin >> n;
    vi v(n * 2);
    for (int &x: v) cin >> x, s += x;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)ss += v[i];
    if(ss * 2 == s)cout << -1 << endl;
    else for (int x: v)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
