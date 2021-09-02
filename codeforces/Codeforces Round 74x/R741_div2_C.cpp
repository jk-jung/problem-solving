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
    int n;
    string s;
    cin >> n >> s;
    int m = n / 2;
    for (int i = m + 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            cout << 1 << " " << i << " " << 1 << " " << i - 1 << endl;
            return;
        }
    }

    if (s[m - 1] == '0')
        cout << m + 1 << " " << n << " " << m << " " << n << endl;
    else
        cout << m + 1 << " " << n << " " << m << " " << n - 1 << endl;

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
