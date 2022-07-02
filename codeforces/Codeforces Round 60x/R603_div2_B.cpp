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

void solve() {
    int n, r = 0;
    cin >> n;
    vector<string> v(n);
    for (auto &s: v)cin >> s;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] == v[j]) {
                r++;
                for (int k = '0'; k <= '9'; k++) {
                    v[i][0] = k;
                    int cnt = 0;
                    for (auto x: v) if (v[i] == x)cnt++;
                    if (cnt == 1)break;
                }
                break;
            }
        }
    }
    cout << r << endl;
    for (auto x: v)cout << x << endl;
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
