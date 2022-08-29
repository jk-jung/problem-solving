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

int calc(string s) {
    int n = s.size();
    int r = 0;
    int rr = 1 << 30;
    for (char x: s)r += x == '1';
    rr = min(rr, r);
    for (char x: s) {
        if (x == '1') r--;
        else r++;
        rr = min(rr, r);
    }
    return rr;
}

void solve() {
    string s;
    cin >> s;

    int r1 = calc(s);
    reverse(s.begin(), s.end());
    int r2 = calc(s);
    cout << min(r1, r2) << endl;
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
