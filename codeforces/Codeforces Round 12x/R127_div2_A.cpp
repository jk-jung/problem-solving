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
    vector<string> r;
    for (int i = 0; i < (1 << s.size()); i++) {
        string t;
        for (int k = 0; k < s.size(); k++)if (i >> k & 1)t += s[k];
        string tt = t;
        reverse(tt.begin(), tt.end());
        if (tt == t)
            r.pb(t);
    }
    sort(r.begin(), r.end());
    cout << r.back() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
