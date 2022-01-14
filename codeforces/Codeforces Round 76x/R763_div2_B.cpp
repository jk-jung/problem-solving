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
    vi s(n), e(n), r(n), u(n + 1);
    for (int i = 0; i < n; i++)cin >> s[i] >> e[i];
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (e[i] - s[i] != k)continue;

            if (s[i] == e[i]) r[i] = s[i], u[s[i]] = 1;
            else {
                for (int j = s[i]; j <= e[i]; j++)
                    if (!u[j]) {
                        u[j] = 1;
                        r[i] = j;
                    }
            }
        }
    }

    for (int i = 0; i < n; i++)cout << s[i] << " " << e[i] << " " << r[i] << '\n';
    cout << endl;
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
