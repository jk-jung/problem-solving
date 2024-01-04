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
    vi v(n), r(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    int c = 0;
    for (int i = 0; i < n; i += 2) r[i] = v[c++];
    for (int i = 1; i < n; i += 2) r[i] = v[c++];
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1 && r[i] < r[i - 1]) {
            cout << "Impossible\n";
            return;
        }
        if (i % 2 == 0 && r[i] > r[i - 1]) {
            cout << "Impossible\n";
            return;
        }
    }
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
