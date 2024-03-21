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
    int n, p;
    string s;
    cin >> n >> p >> s;
    p--;

    int r = 0;
    vi v;
    for (int i = 0; i < n / 2; i++) {
        int j = n - i - 1;
        if (s[i] != s[j]) {
            r += min(ab(s[i] - s[j]), 26 - ab(s[i] - s[j]));
            v.pb(ab(p - i) < ab(p - j) ? i : j);
        }
    }

    sort(v.begin(), v.end());
    if (!v.empty()) {
        if (v[0] <= p && p < v.back()) r += v.back() - v[0] + min(p - v[0], v.back() - p);
        else r += max(p - v[0], v.back() - p);
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
