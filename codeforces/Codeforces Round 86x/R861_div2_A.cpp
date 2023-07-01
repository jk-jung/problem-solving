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
    int a, b;
    cin >> a >> b;

    int r = -1;
    string t;
    for (int i = a; i <= min(a + 100, b); i++) {
        string s = to_string(i);
        char min_char = '9', max_char = '0';
        for (char c: s) {
            min_char = min(min_char, c);
            max_char = max(max_char, c);
        }
        int dif = max_char - min_char;
        if (dif > r) {
            r = dif;
            t = s;
        }
    }
    cout << t << endl;
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
