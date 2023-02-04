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

vector<pi> r;

int n;
int v[300005];
int pos[300005];

void sw(int x, int y) {
    swap(v[x], v[y]);
    swap(pos[v[x]], pos[v[y]]);
    r.pb({x, y});
}

void change(int x, int y) {
    if (x > y)swap(x, y);
    if (ab(x - y) * 2 >= n) {
        sw(x, y);
    } else if (x < n / 2 && y < n / 2) {
        sw(x, n - 1);
        sw(y, n - 1);
        sw(x, n - 1);
    } else if (x >= n / 2 && y >= n / 2) {
        sw(x, 0);
        sw(y, 0);
        sw(x, 0);
    } else {
        sw(x, n - 1);
        change(y, n - 1);
        sw(x, n - 1);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        --v[i];
        pos[v[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == i)continue;
        change(i, pos[i]);
    }
    cout << r.size() << endl;
    for (auto [x, y]: r)cout << x + 1 << " " << y + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
