#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    string s;
    cin >> s;
    int t = 0;
    for (char x: s)t += isupper(x);
    if ((islower(s[0]) && t == s.size() - 1) || s.size() == t) {
        for (char x: s) {
            if (isupper(x))cout << char(tolower(x));
            else cout << char(toupper(x));
        }
    } else {
        cout << s;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
