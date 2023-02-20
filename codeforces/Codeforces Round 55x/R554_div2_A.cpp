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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    vi c(2);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x, c[x % 2]++;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll r = 0;
    for (int x: a) {
        int t = x % 2;
        if (c[t ^ 1]) c[t ^ 1]--, r ++;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
