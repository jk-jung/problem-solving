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
    vi r(n, -1);
    set<int> s;
    for (int i = 1; i <= n; i++)s.insert(i);
    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++)
        if (s.count(v[i]))s.erase(v[i]), r[i] = v[i];
    for (int &x: r)if (x == -1)x = *s.begin(), s.erase(s.begin());
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
