#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        cin >> n;

        if(n%2 == 1) {
            cout<< "3 1 2 ";
            for(int i=4;i<=n; i+= 2) {
                cout<< i + 1 << " " << i << " ";
            }
        }
        else {
            for(int i=1;i<=n; i+= 2) {
                cout<< i + 1 << " " << i << " ";
            }
            cout<<endl;
        }

    }

}
