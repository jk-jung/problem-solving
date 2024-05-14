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
    int n;
    cin >> n;
    string s = "<3";
    while (n--) {
        string x;
        cin >> x;
        s += x + "<3";
    }
    string t;
    cin >> t;
    int i = 0;
    for (char c: t) {
        if (i < s.size() && c == s[i])i++;
    }
    cout <<(i == s.size() ? "yes" : "no") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
