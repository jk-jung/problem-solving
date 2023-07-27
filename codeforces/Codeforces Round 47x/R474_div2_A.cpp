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
    char t = 'a';
    int st = 0, r = 1;
    int a = 0, b = 0, c = 0;
    for (char x: s) {
        if (st == 0) {
            if (x == 'a')a++, st = 1;
            else {
                cout << "NO";
                return;
            }
        } else if (st == 1) {
            if(x == 'a')a++;
            else if(x == 'b')b++, st = 2;
            else {
                cout << "NO";
                return;
            }
        }else if(st == 2) {
            if (x == 'b')b++;
            else if (x == 'c')c++, st = 3;
            else {
                cout << "NO";
                return;
            }
        }
        else {
            if(x == 'c')c ++;
            else {
                cout << "NO";
                return;
            }
        }
    }
    if(b > 0 && (a == c || b == c))cout <<"YES";
    else cout <<"NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
