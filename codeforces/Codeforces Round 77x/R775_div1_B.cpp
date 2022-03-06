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

int cc[1000005];
int ss[1000005];

void solve() {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i <= c; i++)cc[i] = ss[i] = 0;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cc[x]++;
    }
    if (cc[1] == 0) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= c; i++)ss[i] = ss[i - 1] + cc[i];
    for (int v = 2; v <= c; v++) {
        if (cc[v] == 0)continue;

        for (int a = 1; v * a <= c; a++) {
            int e = min(c, v * a + v - 1);
            int s = v * a - 1;

            if (!cc[a] && s < e && ss[e] - ss[s] > 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
