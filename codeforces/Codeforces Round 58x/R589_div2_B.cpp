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
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    ll r = 1;
    for (int i = 0; i < n; i++) {
        int cnt = 0, flag = 1;
        for (int j = 0; j < m; j++) {
            if (flag) {
                if (b[j] > i) cnt++;
                else if (b[j] == i)flag = 0;
                else if (a[i] > cnt) cnt++;
                else if (a[i] == cnt) flag = 0;
                else {
                    r = (r * 2) % 1000000007;
                }
            } else {
                if (b[j] < i) {
                    r = (r * 2) % 1000000007;
                }
            }
        }
        if (cnt != a[i]) {
            cout << "0\n";
            return;
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
