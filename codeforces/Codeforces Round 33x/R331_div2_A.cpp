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
    map<int, int> a, b;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x]++;
        b[y]++;
    }
    if (a.size() == 2 && b.size() == 2) {
        int x1 = a.begin()->F;
        int x2 = (++a.begin())->F;
        int y1 = b.begin()->F;
        int y2 = (++b.begin())->F;
        cout << (x2 - x1) * (y2 - y1) << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
