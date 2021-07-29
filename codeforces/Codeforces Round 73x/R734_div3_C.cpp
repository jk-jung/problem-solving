#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

inline int cc(string& s, char x) { return (int)count(s.begin(), s.end(), x) * 2- (int)s.size(); }
bool fa(string &a, string &b) { return cc(a, 'a') > cc(b, 'a'); }
bool fb(string &a, string &b) { return cc(a, 'b') > cc(b, 'b'); }
bool fc(string &a, string &b) { return cc(a, 'c') > cc(b, 'c'); }
bool fd(string &a, string &b) { return cc(a, 'd') > cc(b, 'd'); }
bool fe(string &a, string &b) { return cc(a, 'e') > cc(b, 'e'); }
bool (*fp[])(string &a, string &b) = {fa, fb, fc, fd, fe};

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    int r = 0;
    for (int k = 0; k < 5; k++) {
        sort(v.begin(), v.end(), *fp[k]);
        for (int i = 0,c = 0; i < n; i++) {
            c += cc(v[i], char('a' + k));
            if (c > 0)r = max(r, i+1);
        }
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
