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
    string a, b;
    cin >> n >> a >> b;
    vi can(n);
    int cnt = 0, s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1')s++;
        else s--;

        if (s == 0)can[i] = 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        int x = a[i] - '0';
        int y = b[i] - '0';

        x ^= cnt;

        if(x != y) {
            if(can[i]) {
                cnt ^= 1;
            }else {
                cout <<"NO\n";
                return;
            }
        }
    }
    cout <<"YES\n";
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
