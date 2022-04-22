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

string s[55];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> s[i];

    while (true) {
        bool flag = true;
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 0; j < m; j++) {
                if(s[i][j] == '.' && s[i-1][j] == '*') {
                    swap(s[i][j], s[i-1][j]);
                    flag = false;
                }
            }
        }

        if (flag)break;
    }
    for (int i = 0; i < n; i++)cout << s[i] << endl;
    cout << '\n';
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
