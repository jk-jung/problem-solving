#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n;
    cin >> n;
    vi v(n);
    int s = 0;
    for (int &x: v)cin >> x, s += x;
    int r = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int t = 0;
            for (int k = i; k <= j; k++) {
                if (v[k] == 1)t--;
                else t++;
            }
            r = max(r, s + t);
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
