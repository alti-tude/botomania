#include<bits/stdc++.h>
#include "utils.h"
using namespace std;

bool isVal(int* grid, pair<int, int> mov, int player){
    int i=mov.first;
    int j=mov.second;
    int c =0;
    if(grid[i*10+j]!=0) return false;
    
    for(i=mov.first-1, j=mov.second, c=0;grid[i*10+j]==3-player and i>=0;i--) c++;
    if(i>=0 and c!=0 and grid[i*10+j]==player) return true;

    for(i=mov.first+1, j=mov.second, c=0;grid[i*10+j]==3-player and i<10;i++) c++;
    if(i<10 and c!=0 and grid[i*10+j]==player) return true;

    for(i=mov.first, j=mov.second-1, c=0;grid[i*10+j]==3-player and j>=0;j--) c++;
    if(j>=0 and c!=0 and grid[i*10+j]==player) return true;

    for(i=mov.first, j=mov.second+1, c=0;grid[i*10+j]==3-player and j<10;j++) c++;
    if(j<10 and c!=0 and grid[i*10+j]==player) return true;

    for(i=mov.first-1, j=mov.second-1, c=0;grid[i*10+j]==3-player and i>=0 and j>=0;i--, j--) c++;
    if(i>=0 and c!=0 and j>=0 and grid[i*10+j]==player) return true;

    for(i=mov.first+1, j=mov.second+1, c=0;grid[i*10+j]==3-player and i<10 and j<10;i++, j++) c++;
    if(i<10 and c!=0 and j<10 and grid[i*10+j]==player) return true;

    for(i=mov.first-1, j=mov.second+1, c=0;grid[i*10+j]==3-player and i>=0 and j<10;i--, j++) c++;
    if(i>=0 and c!=0 and j<10 and grid[i*10+j]==player) return true;
    
    for(i=mov.first+1, j=mov.second-1, c=0;grid[i*10+j]==3-player and i<10 and j>=0;i++, j--) c++;
    if(i<10 and c!=0 and j>=0 and grid[i*10+j]==player) return true;

    return false;
}

void flip(int* grid, pair<int, int> mov, int player){
    int i=mov.first;
    int j=mov.second;
    int c =0;
    
    bool flip = false;
    for(i=mov.first-1, j=mov.second, c=0;grid[i*10+j]==3-player and i>=0;i--) c++;
    if(i>=0 and c!=0 and grid[i*10+j]==player) flip = true;
    for(i=mov.first-1, j=mov.second, c=0;grid[i*10+j]==3-player and i>=0;i--) grid[i*10+j]=3-player;

    flip = false;
    for(i=mov.first+1, j=mov.second, c=0;grid[i*10+j]==3-player and i<10;i++) c++;
    if(i<10 and c!=0 and grid[i*10+j]==player) flip=true;
    for(i=mov.first+1, j=mov.second, c=0;grid[i*10+j]==3-player and i<10;i++) grid[i*10+j]=3-player;

    flip = false;
    for(i=mov.first, j=mov.second-1, c=0;grid[i*10+j]==3-player and j>=0;j--) c++;
    if(j>=0 and c!=0 and grid[i*10+j]==player) flip=true;
    for(i=mov.first, j=mov.second-1, c=0;grid[i*10+j]==3-player and j>=0;j--) grid[i*10+j]=3-player;

    flip = false;
    for(i=mov.first, j=mov.second+1, c=0;grid[i*10+j]==3-player and j<10;j++) c++;
    if(j<10 and c!=0 and grid[i*10+j]==player) flip=true;
    for(i=mov.first, j=mov.second+1, c=0;grid[i*10+j]==3-player and j<10;j++) grid[i*10+j]=3-player;

    flip = false;
    for(i=mov.first-1, j=mov.second-1, c=0;grid[i*10+j]==3-player and i>=0 and j>=0;i--, j--) c++;
    if(i>=0 and c!=0 and j>=0 and grid[i*10+j]==player) flip=true;
    for(i=mov.first-1, j=mov.second-1, c=0;grid[i*10+j]==3-player and i>=0 and j>=0;i--, j--) grid[i*10+j]=3-player;

    flip = false;
    for(i=mov.first+1, j=mov.second+1, c=0;grid[i*10+j]==3-player and i<10 and j<10;i++, j++) c++;
    if(i<10 and c!=0 and j<10 and grid[i*10+j]==player) flip=true;
    for(i=mov.first+1, j=mov.second+1, c=0;grid[i*10+j]==3-player and i<10 and j<10;i++, j++) grid[i*10+j]=3-player;

    flip = false;
    for(i=mov.first-1, j=mov.second+1, c=0;grid[i*10+j]==3-player and i>=0 and j<10;i--, j++) c++;
    if(i>=0 and c!=0 and j<10 and grid[i*10+j]==player) flip=true;
    for(i=mov.first-1, j=mov.second+1, c=0;grid[i*10+j]==3-player and i>=0 and j<10;i--, j++) grid[i*10+j]=3-player;

    flip = false; 
    for(i=mov.first+1, j=mov.second-1, c=0;grid[i*10+j]==3-player and i<10 and j>=0;i++, j--) c++;
    if(i<10 and c!=0 and j>=0 and grid[i*10+j]==player) flip=true;
    for(i=mov.first+1, j=mov.second-1, c=0;grid[i*10+j]==3-player and i<10 and j>=0;i++, j--) grid[i*10+j]=3-player;

}
vector<pair<int, int> > valid_moves(int* grid, int player){
    vector<pair<int,int> > v;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(isVal(grid, make_pair(i,j), player)) v.push_back(make_pair(i,j));
        }
    }

    // cout << v.size() << endl;
    return v;
}