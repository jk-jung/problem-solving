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
    vi v(n), u(n);
    int r = 0, c = n;
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    while (c) {
        r++;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (u[i])continue;
            if (v[i] >= cnt) {
                u[i] = 1;
                cnt++;
                c--;
            }
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
