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
    vi a(5), b(5);
    int p, q;
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    cin >> p >> q;

    int r = 0;
    for (int i = 0; i < 5; i++) {
        int v = 500 * (i + 1);
        r += max(3 * v / 10, (250 - a[i]) * v / 250 - 50 * b[i]);
    }
    cout << r + 100 * p - 50 * q << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
