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

    int a = -1;
    int b = -1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '1' && s[i - 1] == '1') {
            a = i;
            break;
        }
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '0' && s[i - 1] == '0') {
            b = i;
        }
    }
    if(a >= 0 && b >= 0 && a < b){
        cout <<"NO\n";
    }
    else {
        cout <<"YES\n";
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
