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
    int n, m;
    cin >> n >> m;
    int k = -1, r = 1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int t = -1;
        for (int j = 0; j < m; j++)
            if (s[j] == 'R') {
                t = j;
                break;
            }
        if (t != -1) {
            if (k == -1)k = t;
            if (t < k) r = 0;
        }
    }
    cout << (r ? "YES\n" : "NO\n");
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
