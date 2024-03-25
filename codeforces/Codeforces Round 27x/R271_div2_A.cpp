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

string s0 = "qwertyuiop";
string s1 = "asdfghjkl;";
string s2 = "zxcvbnm,./";

void solve() {
    string a, b;
    cin >> a >> b;
    for (char x: b) {
        int i0 = s0.find(x);
        int i1 = s1.find(x);
        int i2 = s2.find(x);
        if (i0 != string::npos) cout << s0[i0 + (a == "R" ? -1 : 1)];
        if (i1 != string::npos) cout << s1[i1 + (a == "R" ? -1 : 1)];
        if (i2 != string::npos) cout << s2[i2 + (a == "R" ? -1 : 1)];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
