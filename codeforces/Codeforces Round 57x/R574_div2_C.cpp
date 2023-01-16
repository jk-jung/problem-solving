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

int a[100005][2];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i][0];
    for (int i = 0; i < n; i++)cin >> a[i][1];
    ll x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int b = a[i][0], c = a[i][1];
        ll nx = max(x, y + b);
        ll ny = max(y, x + c);
        x = nx;
        y = ny;
    }
    cout << max(x, y) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
