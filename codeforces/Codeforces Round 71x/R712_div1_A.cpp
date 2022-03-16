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


    int sa = 0, sb = 0, c1 = 0, c0 = 0, u1 = 0, u0 = 0;
    for (char x: s)c0 += x == '0';
    for (char x: s)c1 += x == '1';

    int ck = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if(u1 < c1 / 2) {
                a += '(', sa++;
                b += '(', sb++;
            }else {
                a += ')', sa--;
                b += ')', sb--;
            }
            u1 ++;
        }else {
            if(ck == 0) {
                a += ')', sa--;
                b += '(', sb++;
            }else {
                a += '(', sa++;
                b += ')', sb--;
            }
            ck ^= 1;
        }

        if(sa < 0 || sb < 0) {
            ok = false;
        }
    }
    if(ok){
        cout << "YES\n";
        cout << a << endl;
        cout << b << endl;
        return;
    }

    ck = 1;
    ok = true;
    sa = 0, sb = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            sa += a[i] == '(' ? 1 : -1;
            sb += b[i] == '(' ? 1 : -1;
        }else {
            if(ck == 0) {
                a[i] = ')', sa--;
                b[i] = '(', sb++;
            }else {
                a[i] = '(', sa++;
                b[i] = ')', sb--;
            }
            ck ^= 1;
        }

        if(sa < 0 || sb < 0) {
            ok = false;
        }
    }

    if(ok){
        cout << "YES\n";
        cout << a << endl;
        cout << b << endl;
    }
    else {
        cout << "NO\n";
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
