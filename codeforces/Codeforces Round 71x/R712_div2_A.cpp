#include <string.h>
#include <stdio.h>
#include <math.h>
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
    string a = "a" + s;
    string aa = a;
    string b = s + "a";
    string bb = b;
    reverse(aa.begin(), aa.end());
    reverse(bb.begin(), bb.end());

    if(aa == a && bb == b) {
        cout <<"NO\n";
    }else if(aa != a) {
        cout <<"YES\n";
        cout << a << endl;
    }else {
        cout <<"YES\n";
        cout << b << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
