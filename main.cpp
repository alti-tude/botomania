#include<bits/stdc++.h>
using namespace std;
#include "utils.h"

#define inf (long long)(1e6)

int PLAYER1;
time_t start_time = 0;
time_t MAX_TIME = 4;

bool broken = false;

ostream &operator<<(ostream& op, pair<int,int> b){
    op << "(" << b.first << " " << b.second << ")" << endl;
    return op;
}



long long int heuristic(int* grid){
    ifstream fin;
    fin.open("heu.txt");

    long long int heu[100];

    for(int i=0;i<10;i++) 
        for(int j=0;j<10;j++)
            fin >> heu[i*10+j];

    long long int val = 0;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            if(grid[i*10+j] == PLAYER1) val += heu[i*10+j];
            if(grid[i*10+j] == 3-PLAYER1) val -= heu[i*10+j];
        }

    int c=0;
    for(int i=0;i<100;i++) 
        if(grid[i]==PLAYER1) c++;
        else if(grid[i]==3-PLAYER1) c--;
    
    val = val + c;
    return val;
}

long long int minimax(int* grid, int alpha, int beta, int depth, int player)
{
	vector<pair<int,int> > cells = valid_moves(grid, player);
    if(cells.size()==0 and player==PLAYER1) return -1000;
    if(cells.size()==0 and player==3-PLAYER1) return 1000;

	if(depth <= 0)return heuristic(grid);

    int tgrid[100];
    for(int i=0;i<100;i++) tgrid[i]=grid[i];
	if(player == PLAYER1)
	{
		int max_value = -inf;
        for(auto x:cells)
        {
        	if(time(NULL) - start_time >= MAX_TIME){broken=true; return -inf;}
        	grid[x.first*10+x.second] = player;
            flip(grid, x, player);

        	int value = minimax(grid, alpha, beta, depth - 1, 3-player);
            for(int i=0;i<100;i++) grid[i]=tgrid[i];
        	if(time(NULL) - start_time >= MAX_TIME){broken=true; return -inf;}

        	grid[x.first*10+x.second] = 0;
        	value = max(value, max_value);
        	alpha = max(alpha, max_value);
 			if(alpha >= beta)return max_value;
        }
        return max_value;
	}
	if(player == 3-PLAYER1)
	{
		int min_value = inf;
        for(auto x:cells)
        {
        	if(time(NULL) - start_time >= MAX_TIME){broken=true; return inf;}
        	grid[x.first*10+x.second] = player;
            flip(grid, x, player);

        	int value = minimax(grid, alpha, beta, depth - 1, 3-player);
            for(int i=0;i<100;i++) grid[i]=tgrid[i];
        	
            if(time(NULL) - start_time >= MAX_TIME){broken=true; return inf;}

        	grid[x.first*10+x.second] = 0;
        	value = min(value, min_value);
        	beta = min(beta, min_value);
 			if(alpha >= beta)return min_value;
        }
        return min_value;
	}
}
pair<int, int> id(int* grid){
    vector<pair<int, int> > v = valid_moves(grid, PLAYER1);
    if(v.size()==0) {return make_pair(-1,-1);}

    int d=0;
    pair<int, int> bm;
    while(time(NULL)-start_time <=MAX_TIME){
        pair<int, int> mov;
        long long int mi = inf*inf;
        for(auto it:v) {
            grid[it.first*10 + it.second] = PLAYER1;
            long long int val = minimax(grid, -inf, inf, d, 3-PLAYER1);
            if(val<mi) mov = it, mi=val;
            grid[it.first*10 + it.second] = 0;
        }

        d++;
        if(!broken) bm = mov;
    }

    return bm;
}

int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w+", stdout);
    start_time = time(NULL);
    int ar[100];
    for(int i=0;i<100;i++){
        cin >> ar[i];
    } 

    cin >> PLAYER1;

    // vector<pair<int,int> > val_moves = valid_moves(ar, player);

    // for(auto it:val_moves) cout << it;

    pair<int, int> cell = id(ar);
    cout << cell.first << endl;
    cout << cell.second << endl;
    return 0;
}