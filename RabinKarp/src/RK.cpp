# include <iostream>
# include <limits.h>
# include <fstream>
# include <time.h>
using namespace std;

int m;
int n;
char T[4100]; 
char P[150];
int hitlist[10];
int hitcount;
ofstream result("..\\output\\result.txt", ios::app);

void RABIN_KARP_MATCHER(char T[4100], char P[150], int d, int q){
    int h = 1;
    for(int i = 1; i < m; i ++){
        h = (h*d) % q;
    }
    int p = 0;
    int t = 0;
    for(int i = 1; i <= m; i ++){
        p = (d*p + P[i]) % q;
        t = (d*t + T[i]) % q;
    }
    int falsehit = 0;
    for(int s = 0; s <= n-m; s ++){
        if(p == t){
            bool hit = true;
            for(int j = 1; j <= m; j ++){
                if(P[j] != T[s+j]){
                    hit = false;
                    break;
                }
            }
            if(hit){
                if(d == 10 && q == 1009){
                    hitlist[hitcount] = s + 1;
                }
                hitcount ++;
            }
            else{
                falsehit ++;
            }
        }
        if(s < n-m){
            t = (d*(t - T[s+1]*h) + T[s+m+1]) % q;
            if(t < 0){
                t += q;
            }
        }
    }
    if(d == 2 && q == 13){
        result << hitcount << endl;
    }
    result << falsehit << " ";
}

int main(){
    ifstream input;
    input.open("..\\input\\4_2_input.txt", ios::in);
    ofstream time("..\\output\\time.txt", ios::app);
    n = 256;
    m = 8;
    int D[4] = {2, 2, 10, 10};
    int Q[4] = {13, 1009, 13, 1009}; 
    int findtime[4][5];
    for(int i = 0; i < 5; i ++){
        for(int k = 1; k <= m; k ++){
            input >> P[k];
        }
        for(int j = 1; j <= n; j ++){
            input >> T[j];
        }
        for(int k = 0; k < 4; k ++){
            int d = D[k];
            int q = Q[k];
            hitcount = 0;
            clock_t start, finish, totaltime;
            start = clock();
            RABIN_KARP_MATCHER(T, P, d, q);
            finish = clock();
            findtime[k][i] = finish - start;
        }
        result << "\n";
        for(int j = 0; j < hitcount; j ++){
            result << hitlist[j] << " ";
        }
        result << "\n" << endl;
        n = n * 2;
        m = m * 2;
    }
    for(int i = 0; i < 4; i ++){
        time << "(" << D[i] << "," << Q[i] << ")" << endl;
        for(int j = 0; j < 5; j ++){
            time << findtime[i][j] << "clock(s) ";
        }
        time << "\n";
    }
        
    return 0;
}