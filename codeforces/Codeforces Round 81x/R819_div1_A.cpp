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
    vi v(n);
    int r = -(1 << 30);
    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++)r = max(r, v[(i + n - 1) % n] - v[i]);
    for (int i = 1; i < n; i++)r = max(r, v[i] - v[0]);
    for (int i = 0; i < n - 1; i++)r = max(r, v[n - 1] - v[i]);
    cout << r << endl;
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
