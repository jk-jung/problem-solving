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

int n;
string s;
map<tuple<int, int, char>, int> ck;

int go(int a, int b, char c) {
    if (a == b) return s[a] == c ? 0 : 1;

    auto k = make_tuple(a, b, c);
    if (ck.count(k)) return ck[k];

    int m = (a + b) / 2;
    int r1 = go(a, m, c + 1);
    int r2 = go(m + 1, b, c + 1);

    for (int i = a; i <= b; i++) {
        if (s[i] != c) {
            if (i <= m) r2++;
            else r1++;
        }
    }

    return ck[k] = min(r1, r2);
}

void solve() {
    cin >> n >> s;
    ck.clear();
    cout << go(0, n - 1, 'a') << endl;
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
