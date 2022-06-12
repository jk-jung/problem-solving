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
    int n;
    string s, a, b;
    cin >> n >> s;

    bool flag = true;
    for (int i = 0; i < n; i++) {
        if(s[i] == '0') {
            a += '0';
            b += '0';
        }else if(flag){
            if(s[i] == '2') {
                a += '1';
                b += '1';
            }else {
                a += '1';
                b += '0';
                flag = false;
            }
        }else {
            a += '0';
            b += s[i];
        }
    }
    cout << a << '\n' << b << endl;
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
