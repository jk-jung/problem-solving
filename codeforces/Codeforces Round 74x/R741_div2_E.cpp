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

int n;
int pre[5005][5005];
int d[5005];
string s;

void solve() {
    int r = 0;
    cin >> n >> s;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            pre[j][i] = s[i] == s[j] ? pre[j + 1][i + 1] + 1 : 0;
        }
    }

    for (int i = 0; i < n; i++) {
        d[i] = n - i;
        for (int j = 0; j < i; j++) {
            if (s[i] > s[j])d[i] = max(d[i], d[j] + n - i);
            else if (s[i] == s[j]) {
                int l = pre[j][i];
                if (l + i < n && s[i + l] > s[j + l]) {
                    d[i] = max(d[i], d[j] + n - i - l);
                }
            }
        }
        r = max(r, d[i]);
    }

    cout << r << '\n';

    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)pre[i][j] = 0;
    for (int i = 0; i < n; i++)d[i] = 0;
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
