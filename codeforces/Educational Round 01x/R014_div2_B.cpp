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

set<char> sym = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y', 'o', 'v', 'w', 'x'};
void solve() {
    string s;
    cin >> s;
    for (int a = 0, b = s.size() - 1; a <= b; a++, b--) {
        char x = s[a], y = s[b];
        if(a == b) {
            if(sym.find(x) == sym.end()) {
                cout << "NIE";
                return;
            }
        }else {
            if (x != y) {
                if (x == 'b' && y == 'd')continue;
                if (x == 'd' && y == 'b')continue;
                if (x == 'p' && y == 'q')continue;
                if (x == 'q' && y == 'p')continue;
                cout << "NIE";
                return;
            } else {
                if (sym.find(x) == sym.end()) {
                    cout << "NIE";
                    return;
                }
            }
        }
    }
    cout << "TAK";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
