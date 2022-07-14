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
    set<string> s;
    vector<string> v(n);
    for (auto &x: v)cin >> x, s.insert(x);

    string r;
    for (auto &x: v) {
        char t = '0';
        for (int i = 0; i < x.size(); i++) {
            string a = x.substr(0, i + 1);
            string b = x.substr(i + 1);

            if (s.count(a) && s.count(b)) t = '1';
        }
        r += t;
    }
    cout << r << endl;
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
