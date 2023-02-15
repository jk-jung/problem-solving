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
    vi a, b;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x % 2)a.pb(x);
        else b.pb(x);
    }
    if (a.size() > b.size()) swap(a, b);
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    ll r = 0;
    for (int i = a.size() + 1; i < b.size(); i++) r += b[i];
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
