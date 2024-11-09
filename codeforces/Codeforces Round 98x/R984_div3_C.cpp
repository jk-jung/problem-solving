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
int n, m;
string s;
set<int> c;

void check(int i) {
    if (i < 0 || i + 3 >= n)return;
    if (c.count(i))c.erase(i);
    if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
        c.insert(i);
}

void solve() {
    c.clear();
    cin >> s >> m;
    n = s.size();

    for (int i = 0; i < n - 3; i++) {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
            c.insert(i);
    }
    while (m--) {
        int k;
        char v;
        cin >> k >> v;
        k--;
        s[k] = v;
        for (int i = -4; i <= 4; i++)check(k - i);
        cout << (c.empty() ? "NO\n" : "YES\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
