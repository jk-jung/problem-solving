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

int n;
string v[2];
int t[4];
int inf = 1 << 30;

void calc(char a, char b) {
    t[0] = t[1] = t[2] = 0;
    if(a == '*' && b == '*')t[1] = t[2] = 1, t[0] = inf;
    else if(a == '*') t[2] = 1, t[0] = inf;
    else if(b == '*') t[1] = 1, t[0] = inf;
    else t[1] = t[2] = inf;
}

void solve() {
    cin >> n >> v[0] >> v[1];
    for(int i=0;;i++) {
        if(v[0][i] == '*' || v[1][i] == '*') {
            v[0] = v[0].substr(i);
            v[1] = v[1].substr(i);
            break;
        }
    }
    while(v[0].back() == '.' && v[1].back() == '.') {
        v[0].pop_back();
        v[1].pop_back();
    }
    n = v[0].size();
    vector<vi> d1(n, vi(2)), d2(n, vi(2));

    for (int i = 0; i < n; i++) {
        char c0 = v[0][i];
        char c1 = v[1][i];
        if(i == 0){
            if(c0 == '*' && c1 == '*'){
                d1[i][0] = 1;
                d1[i][1] = 1;
            }else if(c0 == '*') {
                d1[i][0] = 0;
                d1[i][1] = 1;
            }else {
                d1[i][0] = 1;
                d1[i][1] = 0;
            }
        }
        else {
            int a = d1[i - 1][0];
            int b = d1[i - 1][1];
            if(c0 == '.' && c1 == '.') {
                d1[i][0] = a + 1;
                d1[i][1] = b + 1;
            }else if(c0 == '*' && c1 == '*'){
                d1[i][0] = min(a + 2, b + 2);
                d1[i][1] = min(a + 2, b + 2);
            }else if(c0 == '*') {
                d1[i][0] = min(a + 1, b + 2);
                d1[i][1] = min(a + 2, b + 2);
            }else {
                d1[i][0] = min(a + 2, b + 2);
                d1[i][1] = min(a + 2, b + 1);
            }
        }
    }
    cout << min(d1[n-1][0], d1[n-1][1]) << endl;
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
