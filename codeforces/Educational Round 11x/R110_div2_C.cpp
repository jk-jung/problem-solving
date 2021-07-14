#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

ll d[200005][3];

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i <= n; i++)d[i][0] = d[i][1] = d[i][2] = 0;

    ll r = 0;
    for (int i = 1; i <= n; i++) {
        char k = s[i - 1];
        if (k == '?') {
            d[i][0] = d[i - 1][0];
            d[i][1] = d[i - 1][1];
            d[i][2] = d[i - 1][2] + 1;
        } else if (k - '0' == i % 2) {
            d[i][0] = d[i - 1][0] + d[i - 1][2] + 1;
        } else {
            d[i][1] = d[i - 1][1] + d[i - 1][2] + 1;
        }
        r += d[i][0] + d[i][1] + d[i][2];
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
