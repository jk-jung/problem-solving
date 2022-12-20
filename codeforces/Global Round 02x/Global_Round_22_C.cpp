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

int a, b;
bool d[105][105][105][105];
char c[105][105][105][105], C;

int go(int a0, int b0, int a1, int b1) {
    if (a0 + a1 == a && b0 + b1 == b) return a0 % 2 == 0;
    bool &r = d[a0][b0][a1][b1];
    char &ck = c[a0][b0][a1][b1];
    if (ck == C)return r;
    ck = C;

    r = 0;
    if ((a0 + b0 + a1 + b1) % 2) {
        int st = 0;
        if (a0 + a1 < a) {
            st++;
            if (go(a0, b0, a1 + 1, b1)) st--;
        }
        if (b0 + b1 < b) {
            st++;
            if (go(a0, b0, a1, b1 + 1))st--;
        }
        if (st == 0)r = 1;
    } else {
        if (a0 + a1 < a && go(a0 + 1, b0, a1, b1)) r = 1;
        if (b0 + b1 < b && go(a0, b0 + 1, a1, b1)) r = 1;
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    a = b = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x % 2) a++;
        else b++;
    }
    C++;
    cout << (go(0, 0, 0, 0) ? "Alice" : "Bob") << endl;
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
