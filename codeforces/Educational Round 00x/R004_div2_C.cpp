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
    int r = 0;
    vi v;
    for (char x: s) {
        if (x == '<' || x == '{' || x == '[' || x == '(') v.pb(x);
        else {
            if (v.empty()) {
                cout << "Impossible\n";
                return;
            }
            char y = v.back();
            v.pop_back();
            if (x == '>' && y != '<') r++;
            if (x == '}' && y != '{') r++;
            if (x == ']' && y != '[') r++;
            if (x == ')' && y != '(') r++;
        }
    }
    if (!v.empty()) cout << "Impossible\n";
    else cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
