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


bool ck(string &s, int x) {
    if (s[x] == 'a' && s[x + 1] == 'b' && s[x + 2] == 'c') return true;
    if (x >= 1 && s[x - 1] == 'a' && s[x] == 'b' && s[x + 1] == 'c') return true;
    if (x >= 2 && s[x - 2] == 'a' && s[x - 1] == 'b' && s[x] == 'c') return true;
    return false;
}

void solve() {
    int n, q, c = 0;
    string s;
    cin >> n >> q >> s;
    s += "zzzz";
    for (int i = 0; i < n - 2; i++)
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') c++;

    while (q--) {
        int x;
        char t;
        cin >> x >> t;
        x --;

        if (s[x] != t) {
            if (ck(s, x)) c--;
            s[x] = t;
            if (ck(s, x)) c++;
        }
        cout << c << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
