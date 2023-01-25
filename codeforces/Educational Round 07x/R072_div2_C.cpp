#include <cstring>
#include <cstdio>
#include <cmath>
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
    ll r = 0, zeros = 0, cur = 0;
    for (int i = 0; i < s.size(); i++) {
        char x = s[i];
        if (x == '1') {
            cur = 0;
            for (int j = i; j < min((int) s.size(), i + 20); j++) {
                cur = cur * 2 + (s[j] == '1');
                int len = j - i + 1;
                if (len <= cur && cur <= len + zeros) {
                    r++;
                }
            }
            zeros = 0;
        } else {
            zeros += 1;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
