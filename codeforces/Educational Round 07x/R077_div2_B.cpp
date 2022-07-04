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
    // 10 7
    // 1: 8 6
    // 2: 6 5
    // 3: 4 4
    // 4: 2 3
    // 5: 0 2

    int a, b;
    cin >> a >> b;
    if (a > b)swap(a, b);
    if (a * 2 == b)cout << "YES" << endl;
    else if ((a + b) % 3 == 0 && a >= 3) {
        int t = (a + b) / 3;
        int y = b - t;
        int x = t - y;

        if(x > 0 && y > 0) {
            cout <<"YES\n";
        }else {
            cout <<"NO\n";
        }
    } else cout << "NO" << endl;
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
