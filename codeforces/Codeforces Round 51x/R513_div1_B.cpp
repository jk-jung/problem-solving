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

int f(string s) {
    int r = 0;
    for (char x: s)r += x - '0';
    return r;
}

void solve() {
    string s;
    cin >> s;
    string r;
    r += s[0] - 1;
    for (int i = 1; i < s.size(); i++)r += '9';

    string b = to_string(stoll(s) - stoll(r));
    cout << f(r) + f(b) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
