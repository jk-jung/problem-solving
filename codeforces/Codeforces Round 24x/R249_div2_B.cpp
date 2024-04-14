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
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        vector<pi> v;
        for (int j = i; j < n; j++) if (j - i <= k)v.pb(mp(-s[j], j));
        sort(v.begin(), v.end());

        auto [c, idx] = v[0];
        for (int j = idx; j > i; j--)swap(s[j], s[j - 1]), k--;
    }
    cout << s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
