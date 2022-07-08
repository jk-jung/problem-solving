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
    vi r;
    for (int i = 2; i < s.size(); i++) {
        if (s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o') {
            if (i + 2 < s.size() && s[i + 1] == 'n' && s[i + 2] == 'e') {
                s[i] = '!';
                r.pb(i + 1);
            } else {
                r.pb(i);
            }

        }
        if (s[i - 2] == 'o' && s[i - 1] == 'n' && s[i] == 'e')
            r.pb(i);
    }
    cout << r.size() << endl;
    for (int x: r)cout << x << " ";
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
