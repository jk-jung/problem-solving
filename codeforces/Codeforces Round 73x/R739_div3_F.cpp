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

int count(vi &v) {
    int r = 0;
    for (int i = 0; i < 10; i++) if (v[i] > 0)r++;
    return r;
}

void solve() {
    string n, r, cur;
    int k;
    cin >> n >> k;

    for (int i = 0; i < n.size(); i++) r += "9";

    vi used(10);
    for (char x: n) {
        for (char y = char(x + 1); y <= '9'; y++) {
            used[y - '0']++;
            string t = cur + y;
            int cnt = count(used);
            if (cnt <= k) {
                char z = '0';
                if (cnt == k) {
                    for (int i = 0; i < 10; i++) {
                        if (used[i]) {
                            z = char(i + '0');
                            break;
                        }
                    }
                }
                while (t.size() < n.size()) t += z;
                r = min(r, t);
            }

            used[y - '0']--;
        }
        used[x - '0']++;
        cur += x;
    }
    if(count(used) <=k) r = min(r, cur);

    cout << r << '\n';
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
