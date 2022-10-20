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
    bool a = false, b = false;
    for (char x: s) {
        if (x == '<') a = true;
        if (x == '>') b = true;
    }
    if (a && b) {
        int r = 0;
        for (int i = 0; i < n; i++) {
            char x = s[i];
            char y = i == 0 ? s[n - 1] : s[i - 1];
            if (x == '-' || y == '-') r++;
        }
        cout << r << endl;
    } else cout << n << endl;
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
