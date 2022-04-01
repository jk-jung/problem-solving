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
    string s;
    cin >> s;
    int n = s.size();
    vi d(n, -1), prev(n + 1), pos(30, -1);
    for (int i = 0; i < n; i++) {
        int k = s[i] - 'a';
        prev[i] = pos[k];
        pos[k] = i;
    }
    d[0] = 1;
    for (int i = 1; i < n; i++) {
        if (prev[i] == -1) {
            d[i] = d[i - 1] + 1;
        } else {
            int j = prev[i], x = 0;
            if (j > 0)x = d[j - 1];

            d[i] = min(d[i - 1] + 1, x + i - j - 1);
        }
    }
    cout << d[n - 1] << endl;
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
