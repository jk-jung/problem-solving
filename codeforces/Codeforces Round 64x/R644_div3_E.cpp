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
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &s: v)cin >> s;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            if (v[i][j] == '1') {
                if (v[i + 1][j] == '0' && v[i][j + 1] == '0') {
                    cout << "NO\n";
                    return;
                }
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
