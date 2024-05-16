#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    int r = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        int j = v[i];
        if (v[i] == i)r++;
        else if (v[j] == i) t = 1;
    }
    if (t == 1)cout << r + 2;
    else if (r == n)cout << r;
    else cout << r + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
