#include <string.h>
#include <stdio.h>
#include <math.h>
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

string s;
vi v;

bool can(int x) {
    int n = v.size();
    if (x == v.size()) return true;

    for (int i = 0; i <= x; i++) {
        int a = v[i];
        int b = v[n - (x - i) - 1];
        int zero = b - a + 1 - n + x;
        if (zero <= x) return true;
    }
    return false;
}

void solve() {
    cin >> s;
    v.clear();
    for (int i = 0; i < s.size(); i++)if (s[i] == '1')v.pb(i);

    int a = 0, b = v.size(), r = -1;
    while (a <= b) {
        int m = (a + b) / 2;
        if (can(m))r = m, b = m - 1;
        else a = m + 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
