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
    vi v(n), s(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    int r = 1;
    s[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        int t = 0;
        s[i] = 1;
        for (int j = i + 1; j < n; j++)
            if (s[j] && v[i] < v[j]) {
                s[j] = 0;
                break;
            }
        for (int j = i; j < n; j++) t += s[j];
        r = max(r, t);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
