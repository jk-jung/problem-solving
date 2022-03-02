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

int n;

pair<int, int> cnt(string &a) {
    pi r;
    for (char x: a) {
        if (x == '0') r.F++;
        else r.S++;
    }
    return r;
}

string calc(string &a, string &b) {
    pi ac = cnt(a), bc = cnt(b);

    if (min(ac.F, bc.F) < n)return "";

    int pa = 0, pb = 0, m = n * 2, zero = max(ac.F, bc.F);
    string r;
    while (pa < m || pb < m) {
        int aa = 0, bb = 0;
        while (pa < m && a[pa] != '0') pa++, aa++;
        while (pb < m && b[pb] != '0') pb++, bb++;

        aa = max(aa, bb);
        while (aa--)r.push_back('1');
        if (zero > 0) {
            r.push_back('0');
            zero--;
            pa ++;
            pb ++;
        }
    }
    return r;
}

string calc2(string &a, string &b) {
    pi ac = cnt(a), bc = cnt(b);

    if (min(ac.S, bc.S) < n)return "";

    int pa = 0, pb = 0, m = n * 2, zero = max(ac.S, bc.S);
    string r;
    while (pa < m || pb < m) {
        int aa = 0, bb = 0;
        while (pa < m && a[pa] != '1') pa++, aa++;
        while (pb < m && b[pb] != '1') pb++, bb++;

        aa = max(aa, bb);
        while (aa--)r.push_back('0');
        if (zero > 0) {
            r.push_back('1');
            zero--;
            pa ++;
            pb ++;
        }
    }
    return r;
}

void solve() {
    string s[3];
    cin >> n;
    cin >> s[0] >> s[1] >> s[2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j)continue;
            string r = calc(s[i], s[j]);
            if (r.length() > 0) {
                cout << r << endl;
                return;
            }
            r = calc2(s[i], s[j]);
            if (r.length() > 0) {
                cout << r << endl;
                return;
            }
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
