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

ll mod = 1000000007;

void solve() {
    int m;
    string s;
    cin >> m >> s;

    ll r = s.size();
    for (int i = 0; i < m; i++) {
        int t = s[i] - '0';
        int n = s.size();

        ll left = i + 1;
        ll right = (r - left + mod) % mod;
        r = (left + right * t) % mod;
        for (int _ = 0; _ < t - 1; _++) {
            if (s.size() >= m)break;
            for (int j = i + 1; j < n; j++) {
                s += s[j];
                if (s.size() >= m)break;
            }
        }
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
