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


int f(string &s) {
    int r = 0;
    for (char x: s) if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') r++;
    return r;
}

void solve() {
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    if (f(a) == 5 && f(b) == 7 && f(c) == 5)cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
