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

string s;

void solve() {
    getline(cin, s);
    int a = 0, n = s.size();
    if (n >= 5 && s.substr(0, 5) == "miao.")a += 1;
    if (n >= 5 && s.substr(n - 5) == "lala.") a += 2;
    if (a == 1)cout << "Rainbow's" << endl;
    else if (a == 2)cout << "Freda's" << endl;
    else cout << "OMG>.< I don't know!" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    getline(cin, s);
    while (test_case--)
        solve();
}
