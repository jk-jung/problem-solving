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
    string s, t = "2020";
    cin >> n >> s;
    string ss = s.substr(n - 4);

    for (int i = 0; i < 5; i++) {
        bool ok = true;
        for (int j = i; j < 4; j++) {
            if (t[j] != ss[j]) ok = false;
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
        if (i == 4)break;
        if (t[i] != s[i])break;
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
