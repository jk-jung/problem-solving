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
    pi a, b;
    cin >> a.F >> a.S;
    cin >> b.F >> b.S;

    int s = max(a.F, b.F);
    int e = min(a.S, b.S);
    int len = e - s + 1;
    if (len <= 0)cout << 1 << endl;
    else {
        int r = len - 1;
        if (a.F < s || b.F < s)r++;
        if (a.S > e || b.S > e)r++;
        cout << r << endl;
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
