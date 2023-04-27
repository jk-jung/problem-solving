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


int calc(vector<pi> &v) {
    sort(v.begin(), v.end());
    v.pop_back();
    int a = -(1 << 30), b = +(1 << 30);
    for (auto &[x, y]: v) {
        a = max(a, x);
        b = min(b, y);
    }
    return max(0, b - a);
}

void solve() {
    int n;
    cin >> n;
    vector<pi> v(n), t;
    for (auto &[x, y]: v) cin >> x >> y;
    t = v;
    for (auto &[x, y]: t)x *= -1, y *= -1, swap(x, y);
    sort(v.begin(), v.end());
    sort(t.begin(), t.end());

    cout << max(calc(v), calc(t)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
