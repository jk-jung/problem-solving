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

int c[1000005];

void solve() {
    string s;
    int n, q;
    cin >> s >> q;
    n = s.size();

    for (int i = 1; i <= n; i++) {
        char k = s[i - 1];
        c[i] = c[i - 1];
        if (k == '(' or k == ')') c[i] += (i & 1 ? 1 : -1);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << ab(c[b] - c[a - 1]) << '\n';
    }
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
