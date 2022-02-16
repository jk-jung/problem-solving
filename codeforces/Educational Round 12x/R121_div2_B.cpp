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
    string s;
    cin >> s;
    int n = s.size();
    int r = -1, idx = -1;
    for (int i = 0; i < n - 1; i++) {
        int k = (s[i] - '0') + (s[i + 1] - '0');
        if (k < 10) continue;
        idx = i;
    }
    if (idx == -1) {
        idx = 0;
        for (int i = 0; i < n; i++) {
            int k = (s[i] - '0') + (s[i + 1] - '0');
            if (k > s[i] - '0') {
                idx = i;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (idx == i) {
            int k = (s[i] - '0') + (s[i + 1] - '0');
            cout << k;
            i++;
        } else cout << s[i];
    }
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
