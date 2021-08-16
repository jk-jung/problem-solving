#include <string.h>
#include <stdio.h>
#include <math.h>
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

int n;
string s;
map<pair<int, char>, int> ck;
map<pair<int, char>,  char> from;

int go(int x, char last) {
    if (x == n) return 0;

    auto t = mp(x, last);
    if (ck.find(t) != ck.end()) return ck[t];
    int &r = ck[{x, last}];

    if (s[x] == '?') {
        int r1 = go(x + 1, 'R') + ('R' == last ? 1 : 0);
        int r2 = go(x + 1, 'B') + ('B' == last ? 1 : 0);
        if (r1 <= r2) {
            r = r1;
            from[t] = 'R';
        } else {
            r = r2;
            from[t] = 'B';
        }
    } else {
        r = go(x + 1, s[x]) + (s[x] == last ? 1 : 0);
        from[t] = s[x];
    }

    return r;
}

string trace(int x, char last) {
    if(x == n) return string("") + last;
    return last + trace(x+1, from[mp(x, last)]);

}
void solve() {

    cin >> n >> s;
    ck.clear();
    from.clear();

    go(0, 'x');
    cout << trace(0, 'x').substr(1)<< endl;
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
