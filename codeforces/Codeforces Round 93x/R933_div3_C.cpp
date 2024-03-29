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


int r = 0;

int process(string s, string t) {
    int r = 0;
    for (int i = 0; i <= (int) s.size() - (int) t.size(); i++) {
        if (s.substr(i, t.size()) == t) {
            r++;
        }
    }
    return r;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int a = process(s, "mapie");
    int b = process(s, "map");
    int c = process(s, "pie");
    cout << b + c - a << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
