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


string f(string s) {
    string r;
    for (char x: s) {
        x = tolower(x);
        if ('a' <= x && x <= 'z') r += x;
    }
    return r;
}

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    set < string > t;
    a = f(a);
    b = f(b);
    c = f(c);
    t.insert(a + b + c);
    t.insert(a + c + b);
    t.insert(b + a + c);
    t.insert(b + c + a);
    t.insert(c + a + b);
    t.insert(c + b + a);

    int n;
    cin >> n;
    while (n--) {
        string x;
        cin >> x;
        cout << (t.count(f(x)) ? "ACC" : "WA") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
