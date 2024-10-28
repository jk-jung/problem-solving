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

bool ok(string &s, string &d) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != d[i % d.size()])return false;
    }
    return true;
}

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int r = 0;
    for (int i = 1; i <= min(n, m); i++) {
        if (n % i || m % i)continue;

        string t = a.substr(0, i);
        if (ok(a, t) && ok(b, t))r++;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
