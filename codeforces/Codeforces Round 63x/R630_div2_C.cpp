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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int r = 0;
    for (int a = 0, b = k - 1; a <= b; a++, b--) {
        map<int, int> ck;
        int dif = ab(a - b);
        int m = 0, tot = 0;
        for (int x = a; x < n; x += k) {
            int y = x + dif;
            m = max(m, ++ck[s[x]]), tot++;
            if (dif)m = max(m, ++ck[s[y]]), tot++;
        }
        r += tot - m;
    }
    cout << r << endl;
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
