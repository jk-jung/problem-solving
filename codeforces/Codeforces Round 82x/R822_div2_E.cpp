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

int a[355][355];

void solve() {
    int n;
    cin >> n;
    vi v(n);

    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++) {
        int t = ((v[i] - i * i) % n + n) % n;
        for (int j = 0; j < n; j++)a[i][j] = (i * j + t) % n;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
