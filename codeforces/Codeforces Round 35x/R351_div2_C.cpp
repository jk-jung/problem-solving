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
    vi v(n), r(n + 1);
    for (int &x: v)cin >> x;

    for (int i = 0; i < n; i++) {
        vi c(n + 1);
        int k = 0;
        for (int j = i; j < n; j++) {
            int x = v[j];
            c[x]++;
            if (c[x] == c[k]) k = min(k, x);
            else if (c[x] > c[k]) k = x;
            r[k]++;
        }
    }
    for (int i = 1; i <= n; i++)cout << r[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
