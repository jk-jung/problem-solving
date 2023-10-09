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
    vi a(n), b(k);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    if (k != 1) cout << "Yes\n";
    else {
        for (int i = 0; i < n; i++)if (a[i] == 0)a[i] = b[0];
        vi c = a;
        sort(c.begin(), c.end());
        cout << (a == c ? "No\n" : "Yes\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
