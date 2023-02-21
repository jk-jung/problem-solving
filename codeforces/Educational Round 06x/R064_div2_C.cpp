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
    int n, z;
    cin >> n >> z;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    int s = 0, e = n / 2, r = 0;
    while (s <= e) {
        int m = (s + e) / 2;
        int t = 0;
        vi used(n);
        for (int i = 0, j = m; i < n; i++) {
            if (used[i])continue;
            while (j < n && v[j] - v[i] < z) j++;
            if (j < n) {
                used[j++] = 1;
                t++;
            }
        }
        if(t >= m)r = m, s = m + 1;
        else e = m -1;
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
