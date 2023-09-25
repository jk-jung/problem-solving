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
    vi a(n);
    vector<pi> b(n);
    for (int &x: a)cin >> x;
    for (int i = 0; i < n; i++) {
        b[i].second = i;
        cin >> b[i].first;
    }
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        b[i].F = a[i];
        swap(b[i].F, b[i].S);
    }
    sort(b.begin(), b.end());
    for (auto &[x, y]: b)cout << y << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
