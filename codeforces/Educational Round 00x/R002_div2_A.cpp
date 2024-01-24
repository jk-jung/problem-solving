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
    vector<string> a, b;
    s += ';';
    string c;
    for (char x: s) {
        if (x == ';' || x == ',') {
            bool ok = true;
            for(char y : c)if(y < '0' || y > '9')ok = false;
            if(ok && (c.size() == 1 || c.size() > 1 && c[0] != '0'))a.pb(c);
            else b.pb(c);
            c = "";
        } else c += x;
    }
    if(a.empty())cout << "-\n";
    else {
        cout << "\"";
        for (int i = 0; i < a.size(); i++) {
            if (i)cout << ",";
            cout << a[i];
        }
        cout << "\"\n";
    }
    if(b.empty())cout << "-\n";
    else {
        cout << "\"";
        for (int i = 0; i < b.size(); i++) {
            if (i)cout << ",";
            cout << b[i];
        }
        cout << "\"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
