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
    vi v(n), t;
    for (int &x: v)cin >> x;
    t = v;
    sort(t.begin(), t.end());

    map<int, int> a, b;
    int dif = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int x = v[i];
        int y = t[i];

        if (a[x] == b[x]) dif++;
        if (++a[x] == b[x]) dif--;
        if (a[y] == b[y]) dif++;
        if (++b[y] == a[y]) dif--;

        if (dif == 0) {
            r++;
            a.clear();
            b.clear();
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
