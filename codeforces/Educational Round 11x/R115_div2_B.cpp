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

int v[1005][5];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)for (int j = 0; j < 5; j++)cin >> v[i][j];
    for (int x = 0; x < 4; x++) {
        for (int y = x + 1; y < 5; y++) {
            int a = 0, b = 0, c = 0, m = n / 2;
            for (int i = 0; i < n; i++) {
                if (v[i][x] && v[i][y])c++;
                else if (v[i][x])a++;
                else if (v[i][y])b++;
            }

            if(a + c >= m && b + c >= m && a + b + c == n) {
                cout <<"YES\n";
                return;
            }
        }
    }
    cout <<"NO\n";
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
