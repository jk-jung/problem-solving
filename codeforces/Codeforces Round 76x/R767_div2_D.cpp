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
    for (auto &x: v)cin >> x;
    for (auto &x: v) {
        int m = (int) x.size();
        if (x[0] == x[m - 1]) {
            cout << "YES\n";
            return;
        }
    }

    map<string, int> cnt2;
    map<string, int> cnt3, cnt32;
    for (auto &x: v) {
        int m = (int) x.size();
        if(m == 2) {
            string k = string("") + x[1] + x[0];
            string t = string("") + x[0] + x[1];
            if (cnt2.count(k) || cnt32.count(k)) {
                cout << "YES\n";
                return;
            }
            cnt2[t] = 1;
        }else {
            string k2 = string("") + x[2] + x[1];
            string k3 = string("") + x[2] + x[1] + x[0];
            string t2 = string("") + x[0] + x[1];
            string t3 = string("") + x[0] + x[1] + x[2];
            if (cnt2.count(k2) || cnt3.count(k3)) {
                cout << "YES\n";
                return;
            }
            cnt32[t2] = 1;
            cnt3[t3] = 1;
        }
    }
    cout << "NO\n";
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
