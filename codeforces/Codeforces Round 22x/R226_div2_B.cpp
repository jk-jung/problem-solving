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
    string s;
    cin >> s;
    ll n = s.size();
    vi t;
    ll r = 0;
    for (int i = 3; i < s.size(); i++) {
        if (s[i - 3] == 'b' && s[i - 2] == 'e' && s[i - 1] == 'a' && s[i] == 'r')
            t.pb(i - 3);
    }
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(t.begin(), t.end(), i);
        if (it != t.end()) {
            r += n - *it - 3;
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
