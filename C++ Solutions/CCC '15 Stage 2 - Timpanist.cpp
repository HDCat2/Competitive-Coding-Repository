//Problem description found at https://wcipeg.com/problem/ccc15s2p5

#include <bits/stdc++.h>
using namespace std;

int N,D,V1,V2;
double dp[110][15][15][15][15];
double da[110][2];

double match(int d1, int d2, int d3, int d4, int v1, int v2, int v3, int v4){
    double tot = 0;
    if(d1 != v1) tot += 1;
    if(d2 != v2) tot += 1;
    if(d3 != v3) tot += 1;
    if(d4 != v4) tot += 1;
    return tot;
}

double rec1(int pos, int d1){
    //cout << pos << " " << d1 << " " << best << endl;
    if(dp[pos][d1][0][0][0] != -1){
        //cout << "L " << dp[pos][d1][0][0][0] << endl;
        return dp[pos][d1][0][0][0];
    }
    if(pos >= N-1){
        return 1e+9;
    }
    double tot = 0;
    for(int i = 1; i <= 12; i++){
        if(i != da[pos+1][1]) continue;
        int ope = match(d1,0,0,0,i,0,0,0);
        tot = max(tot,min((ope==0)?1e+9:(double)(da[pos+1][0])/ope,rec1(pos+1,i)));
    }
    dp[pos][d1][0][0][0] = tot;
    return tot;
}

double rec2(int pos, int d1, int d2){
    if(dp[pos][d1][d2][0][0] != -1){
        return dp[pos][d1][d2][0][0];
    }
    if(pos >= N-1){
        return 1e+9;
    }
    double tot = 0;
    for(int i = 1; i <= 12; i++){
        for(int q = i+1; q <= 12; q++){
            if(i != da[pos+1][1] && q != da[pos+1][1]) continue;
            int ope = match(d1,d2,0,0,i,q,0,0);
            tot = max(tot,min((ope==0)?1e+9:(double)(da[pos+1][0])/ope,rec2(pos+1,i,q)));
        }
    }
    return dp[pos][d1][d2][0][0] = tot;
}

double rec3(int pos, int d1, int d2, int d3){
    if(dp[pos][d1][d2][d3][0] != -1) return dp[pos][d1][d2][d3][0];
    if(pos >= N-1) return 1e+9;
    double tot = 0;
    for(int i = 1; i <= 12; i++){
        for(int q = i+1; q <= 12; q++){
            for(int e = q+1; e <= 12; e++){
                if(i != da[pos+1][1] && q != da[pos+1][1] && e != da[pos+1][1]) continue;
                int ope = match(d1,d2,d3,0,i,q,e,0);
                tot = max(tot,min((ope==0)?1e+9:(double)(da[pos+1][0])/ope,rec3(pos+1,i,q,e)));
            }
        }
    }
    return dp[pos][d1][d2][d3][0] = tot;
}

double rec4(int pos, int d1, int d2, int d3, int d4){
    //if(d1 == 1 && d2 == 3 && d3 == 5 && d4 == 8) cout << best << " " << pos << " " << dp[pos][d1][d2][d3][d4] << endl;
    if(dp[pos][d1][d2][d3][d4] != -1) return dp[pos][d1][d2][d3][d4];
    if(pos >= N-1) return 1e+9;
    double tot = 0;
    for(int i = 1; i <= 12; i++){
        for(int q = i+1; q <= 12; q++){
            for(int e = q+1; e <= 12; e++){
                for(int r = e+1; r <= 12; r++){
                    if(e != da[pos+1][1] && r != da[pos+1][1] && q != da[pos+1][1] && i != da[pos+1][1]) continue;
                    int ope = 0;
                    if (i != d1) ope ++;
                    if (D > 1 && q != d2) ope ++;
                    if (D > 2 && e != d3) ope ++;
                    if (D > 3 && r != d4) ope ++;
                    tot = max(tot,min((ope==0)?1e+9:(double)(da[pos+1][0])/ope,rec4(pos+1,i,q,e,r)));
                }
            }
        }
    }
    return dp[pos][d1][d2][d3][d4] = tot;
}

int main(){
    //freopen("input.txt","r",stdin);
    for(int i = 0; i < 110; i++) for(int q = 0; q < 14; q++) for(int w = 0; w < 14; w++) for(int e = 0; e < 14; e++) for(int r = 0; r < 14; r++) dp[i][q][w][e][r] = -1.0;
    cin >> N >> D;
    int m;
    for(int i = 0; i < N; i++){
        cin >> V1 >> V2;
        if(i == 0) m = V1;
        da[i][0] = V1 - m;
        m = V1;
        da[i][1] = V2;
    }
    da[N][0] = 1e+10;
    da[N][1] = 1;
    double t = 0;

    if(D == 1){
        for(int i = 1; i <= 12; i++){
            if(i != da[0][1]) continue;
            t = max(t, rec1(0,i));
        }
    }

    if(D == 2){
        for(int i = 1; i <= 12; i++){
            for(int q = i+1; q <= 12; q++){
                if(i != da[0][1] && q != da[0][1]) continue;
                t = max(t, rec2(0,i,q));
            }
        }
    }

    if(D == 3){
        for(int i = 1; i <= 12; i++){
            for(int q = i+1; q <= 12; q++){
                for(int w = q+1; w <= 12; w++){
                    if(i != da[0][1] && q != da[0][1] && w != da[0][1]) continue;
                    t = max(t, rec3(0,i,q,w));
                }
            }
        }
    }

    if(D == 4){
        for(int i = 1; i <= 12; i++){
            for(int q = i+1; q <= 12; q++){
                for(int w = q+1; w <= 12; w++){
                    for(int e = w+1; e <= 12; e++){
                        if(i != da[0][1] && q != da[0][1] && w != da[0][1] && e != da[0][1]) continue;
                        t = max(t, rec4(0,i,q,w,e));
                    }
                }
            }
        }
    }
    if(t >= 1e+9) t = 0;
    cout << fixed << setprecision(2) << t << endl;
    return 0;
}
