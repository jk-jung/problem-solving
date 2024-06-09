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
    int n = s.size();
    vi v(n + 1);
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1])v[i + 1]++;
        v[i + 1] += v[i];
    }
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        int r = v[b] - v[a - 1];
        if (a >= 2 && s[a - 1] == s[a - 2]) r--;
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
