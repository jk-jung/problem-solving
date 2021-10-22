#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
    string s;
    cin >> s;
    int n = s.size();
    int r = n - 1;

    for (auto x: {"00", "25", "50", "75"}) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] != x[0]) continue;
                if (s[j] != x[1]) continue;

                r = min(r, n - i - 2);
            }
        }
    }

    cout << r << '\n';
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
