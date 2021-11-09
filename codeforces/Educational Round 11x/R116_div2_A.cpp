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


bool ok(string &s) {
    int n = s.size(), a = 0, b = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b') a++;
        if (s[i] == 'b' && s[i + 1] == 'a') b++;
    }
    return a == b;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> v;
    v.pb(s);
    v.pb("a" + s.substr(1));
    v.pb("b" + s.substr(1));
    v.pb(s.substr(0, n - 1) + "a");
    v.pb(s.substr(0, n - 1) + "b");
    for (auto t : v) {
        if(ok(t)) {
            cout << t << endl;
            return;
        }
    }


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
