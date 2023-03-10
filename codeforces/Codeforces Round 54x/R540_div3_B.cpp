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
    vi v(n), s(n + 2), c(2);
    for (int &x: v) cin >> x;

    for (int i = n - 1; i >= 0; i--)
        s[i] = s[i + 2] + v[i];

    int r = 0;
    for (int i = 0; i < n; i++) {
        int x = i % 2;
        int y = x ^ 1;
        if (c[x] + s[i + 1] == c[y] + s[i + 2]) r++;
        c[i % 2] += v[i];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
