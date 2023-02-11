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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << max(k, (k / a[0]) * b[m - 1] + k % a[0]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
