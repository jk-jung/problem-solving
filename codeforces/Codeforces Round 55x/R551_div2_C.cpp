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
    int n;
    string s;
    cin >> n >> s;
    if (n % 2) cout << ":(";
    else {
        if (s[0] == ')' || s[n - 1] == '(') {
            cout << ":(";
            return;
        }
        s[0] = '(';
        s[n-1] = ')';
        int a = (n - 2) / 2, st = 0;
        for (int i = 1; i < n - 1; i++) if (s[i] == '(') a--;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '?') {
                if (a) s[i] = '(', a--;
                else s[i] = ')';
            }
            if (s[i] == '(') st++;
            else st--;
            if (st < 0) {
                cout << ":(";
                return;
            }
        }
        if (st) {
            cout << ":(";
            return;
        }
        cout << s << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
