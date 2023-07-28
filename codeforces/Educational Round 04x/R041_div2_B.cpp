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
    int n, k;
    cin >> n >> k;
    vi v(n);
    vi a(n), s(n + 1);
    for (int &x: v)cin >> x;
    for (int &x: a)cin >> x;
    for (int i = n - 1; i >= 0; i--)s[i] = s[i + 1] + v[i] * a[i];
    int t = 0;
    for (int i = 0; i < k; i++)t += v[i];
    int r = t + s[k];
    for (int i = k; i < n; i++) {
        if (a[i - k] == 0)t -= v[i - k];
        t += v[i];
        r = max(r, t + s[i + 1]);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
