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
    vi v(n), ss(n);
    for (int &x: v)cin >> x;
    string s;
    cin >> s;
    int r = 0;
    for (int i = 0; i < n; i++)if (s[i] == '1')r += v[i];
    ss[0] = v[0];
    for (int i = 1; i < n; i++)ss[i] += ss[i - 1] + v[i];

    int s1 = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (s[i] == '1') {
            r = max(r, s1 + ss[i - 1]);
            s1 += v[i];
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
