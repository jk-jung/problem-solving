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
    int n;
    string s;
    cin >> n >> s;

    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        if (i % 2 == 0) {
            if (x % 2) a = 1;
        } else {
            if (x % 2 == 0) b = 1;
        }
    }
    if (n % 2) cout << (a ? 1 : 2) << endl;
    else cout << (b ? 2 : 1) << endl;
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
