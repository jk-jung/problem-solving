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
    for (int i = 0; i <= s.size(); i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            string r = s.substr(0, i) + c + s.substr(i);
            string t = r;
            reverse(t.begin(), t.end());
            if (r == t) {
                cout << r << endl;
                return;
            }
        }
    }
    cout <<"NA";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
