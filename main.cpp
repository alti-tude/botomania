#include<bits/stdc++.h>
using namespace std;
#include "utils.h"

ostream &operator<<(ostream& op, pair<int,int> b){
    op << "(" << b.first << " " << b.second << ")" << endl;
    return op;
}

int main(){
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int ar[100];
    for(int i=0;i<100;i++){
        cin >> ar[i];
    } 

    int player;
    cin >> player;

    vector<pair<int,int> > val_moves = valid_moves(ar, player);

    for(auto it:val_moves) cout << it;
    return 0;
}