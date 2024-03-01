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
    int a = 0;
    string s;
    for (int i = 0; i < 8; i++) {
        cin >> s;
        for(char x:s) {
            if(x =='Q')a += 9;
            if(x =='R')a += 5;
            if(x =='B')a += 3;
            if(x =='N')a += 3;
            if(x =='P')a += 1;
            if(x =='q')a -= 9;
            if(x =='r')a -= 5;
            if(x =='b')a -= 3;
            if(x =='n')a -= 3;
            if(x =='p')a -= 1;
        }
    }
    if(a == 0)cout << "Draw";
    else if(a > 0)cout << "White";
    else cout << "Black";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
