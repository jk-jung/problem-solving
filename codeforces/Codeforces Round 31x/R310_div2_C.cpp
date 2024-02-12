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
    int t = 0;
    int r = n - 1;
    for (int i = 0; i < m; i++) {
        int c = 0;
        cin >> c;
        int cnt = 0;
        for (int j = 0, x; j < c; j++) {
            cin >> x;
            if (x == cnt + 1)cnt++;
        }
        r += c - 1;
        t = max(t, cnt);
    }
    cout << r - (t - 1) * 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
