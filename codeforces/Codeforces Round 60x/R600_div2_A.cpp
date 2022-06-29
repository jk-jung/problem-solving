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
    vi a(n), b(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    int flag = 0, val = 1 << 30;
    for (int i = 0; i < n; i++) {
        int t = a[i] - b[i];
        if(t > 0){
            cout << "NO\n";
            return;
        }else if (t) {
            if (val == (1 << 30)) val = t;
            if (flag == 2 || val != t) {
                cout << "NO\n";
                return;
            }
            flag = 1;
        } else {
            flag = flag == 1 ? 2 : 0;
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
