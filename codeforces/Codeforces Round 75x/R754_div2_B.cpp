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
    string s;
    cin >> n >> s;
    vector<vi> r;

    while (true) {
        int e = n - 1;
        vi t;
        for (int i = 0; i < e; i++) {
            if (s[i] == '1') {
                while (e > i && s[e] != '0') e--;
                if(i < e) {
                    t.pb(i);
                    t.pb(e);
                    s[i] = '0';
                    s[e] = '1';
                }
            }
        }
        if(t.size() == 0)break;
        sort(t.begin(), t.end());
        r.pb(t);
    }
    cout << r.size() << endl;
    for (auto &v: r) {
        cout << v.size();
        for (int x: v)cout << " " << x + 1;
        cout << '\n';
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
