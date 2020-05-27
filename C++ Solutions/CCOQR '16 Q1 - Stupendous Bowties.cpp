//Problem description found at https://wcipeg.com/problem/ccoqr16p1

#include <bits/stdc++.h>
using namespace std;

int N;
int coords[100010][2];
map<int, vector<int>> xcoords, ycoords;
long long counter = 0;
map<int, int> XP,YP;
vector<int> xcheck;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d%d",&coords[i][0],&coords[i][1]);
        //cout << coords[i][0] << " " << coords[i][1] << endl;
        ycoords[coords[i][0]].push_back(coords[i][1]);
        xcoords[coords[i][1]].push_back(coords[i][0]);
    }

    for(int i = 0; i < N; i++){
        if(XP[coords[i][0]] != 1){
            sort(ycoords[coords[i][0]].begin(), ycoords[coords[i][0]].end());
            XP[coords[i][0]] = 1;
            xcheck.push_back(coords[i][0]);
        }
        if(YP[coords[i][1]] != 1){
            sort(xcoords[coords[i][1]].begin(), xcoords[coords[i][1]].end());
            YP[coords[i][1]] = 1;
        }
    }

    for(int i = 0; i < xcheck.size(); i++){
        for(int q = 1; q < ycoords[xcheck[i]].size() - 1; q++){
            vector<int> xc = xcoords[ycoords[xcheck[i]][q]];
            vector<int> yc = ycoords[xcheck[i]];
            long long y = lower_bound(xc.begin(), xc.end(), xcheck[i]) - xc.begin();
            counter += 2*q*y*(xc.size() - y - 1)*(yc.size() - q - 1);
        }
    }
    cout << counter;
}
