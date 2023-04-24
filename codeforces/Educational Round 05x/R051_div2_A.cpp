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

int ok(string &s) {
    int a = 0, b = 0, c = 0;
    for (char x: s) {
        if ('a' <= x && x <= 'z') a = 1;
        if ('A' <= x && x <= 'Z') b = 1;
        if ('0' <= x && x <= '9') c = 1;
    }
    return a + b + c;
}

void solve() {
    string s;
    cin >> s;

    int t = ok(s);
    if (t == 3) {
        cout << s << endl;
    } else if (t == 2) {
        for (int i = 0; i < s.size(); i++) {
            string s1 = s;
            string s2 = s;
            string s3 = s;
            s1[i] = 'a';
            s2[i] = 'A';
            s3[i] = '0';
            if (ok(s1) == 3) {
                cout << s1 << endl;
                return;
            }
            if (ok(s2) == 3) {
                cout << s2 << endl;
                return;
            }
            if (ok(s3) == 3) {
                cout << s3 << endl;
                return;
            }
        }
    } else if (t == 1) {
        char x = s[0];
        if ('a' <= x && x <= 'z') cout << "A0" << s.substr(2) << endl;
        if ('A' <= x && x <= 'Z') cout << "a0" << s.substr(2) << endl;
        if ('0' <= x && x <= '9') cout << "Aa" << s.substr(2) << endl;
    }
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
