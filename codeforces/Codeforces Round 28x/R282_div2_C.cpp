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
    int k = -1;
    for (int i = 0; i < s.size(); i++)if (s[i] == '#')k = i;

    int st = 0;
    vi r;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')st++;
        else if (s[i] == ')')st--;
        else if (i == k) {
            int st2 = st;
            int mm = st;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == '(')st2++;
                else st2--;
                mm = min(mm, st2);
            }
            if (st2 <= 0 || (mm != st2)) {
                cout << -1;
                return;
            }
            r.pb(st2);
            st = 0;
            break;
        } else {
            r.pb(1);
            st--;
        }
        if (st < 0) {
            cout << -1;
            return;
        }
    }
    if (st != 0) {
        cout << -1;
        return;
    }
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
