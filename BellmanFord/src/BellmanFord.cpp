# include <iostream>
# include <limits.h>
# include <fstream>
# include <time.h>
using namespace std;

int G_v[8] = {27, 27, 81, 81, 243, 243, 729, 729};
int d[800] = {0};
int pai[800] = {-1};
//info of edges
int e_num = 0;
int e_w[4000] = {0};
int e_u[4000] = {-1};
int e_v[4000] = {-1};

void INITIALIZE_SINGLE_SOURCE(int G, int s){
    for(int v = 0; v < G_v[G]; v ++){
        d[v] = INT_MAX / 2;
        pai[v] = -1;
    }
    d[s] = 0;
}

void RELAX(int u, int v, int w){
    if(d[v] > d[u] + w){
        d[v] = d[u] + w;
        pai[v] = u;
    }
}

bool BELLMAN_FORD(int G, int s){
    INITIALIZE_SINGLE_SOURCE(G, s);
    for(int i = 1; i < G_v[G]; i ++){
        for(int j = 0; j < e_num; j ++){
            int u = e_u[j];
            int v = e_v[j];
            int w = e_w[j];
            RELAX(u, v, w);
        }
    }
    for(int k = 0; k < e_num; k ++){
        int u = e_u[k];
        int v = e_v[k];
        int w = e_w[k];
        if(d[v] > d[u] + w){
            return false;
        }
    }
    return true;
}


int main(){
    ifstream input;
    ofstream time("..\\output\\time.txt", ios::app);
    string output = "..\\output\\result11.txt";
    for(int G = 0; G < 8; G ++){
        e_num = {0};
        switch(G){
            case 0:{
                input.open("..\\input\\input11.txt", ios::in);
                output = "..\\output\\result11.txt";
                e_num = 3 * 27;
                break;
            }
            case 1:{
                input.open("..\\input\\input12.txt", ios::in);
                output = "..\\output\\result12.txt";
                e_num = 2 * 27;
                break;
            }
            case 2:{
                input.open("..\\input\\input21.txt", ios::in);
                output = "..\\output\\result21.txt";
                e_num = 3 * 81;
                break;
            }
            case 3:{
                input.open("..\\input\\input22.txt", ios::in);
                output = "..\\output\\result22.txt";
                e_num = 3 * 81;
                break;
            }
            case 4:{
                input.open("..\\input\\input31.txt", ios::in);
                output = "..\\output\\result31.txt";
                e_num = 4 * 243;
                break;
            }
            case 5:{
                input.open("..\\input\\input32.txt", ios::in);
                output = "..\\output\\result32.txt";
                e_num = 3 * 243;
                break;
            }
            case 6:{
                input.open("..\\input\\input41.txt", ios::in);
                output = "..\\output\\result41.txt";
                e_num = 5 * 729;
                break;
            }
            case 7:{
                input.open("..\\input\\input42.txt", ios::in);
                output = "..\\output\\result42.txt";
                e_num = 4 * 729;
                break;
            }
        }
        int total = 0;
        for(int u = 0; u < G_v[G]; u ++){
            char a;
            for(int v = 0; v < G_v[G]; v ++){
                int tmp;
                input >> tmp;
                input >> a;
                if(tmp != 0){
                    e_w[total] = tmp;
                    e_u[total] = u;
                    e_v[total] = v;
                    total ++;
                }
            }
        }
        input.close();
    
        clock_t start, finish, totaltime;
        start = clock();
        //Main function
        int s = 0;
        bool flag = BELLMAN_FORD(G, s);
        if(flag == false){
            cout << "ERROR!" << endl;
        }
        ofstream result(output, ios::app);
        for(int i = 1; i < G_v[G]; i ++){
            if(d[i] != INT_MAX / 2){
                result << "0," << i << "," << d[i] << ";";
                int j[800];
                int tag = 0;
                int num = i;
                j[tag] = num;
                while(pai[num] != 0){
                    tag ++;
                    j[tag] = pai[num];
                    num = pai[num];
                }
                result << "0";
                while(tag >= 0){
                    result << "," << j[tag];
                    tag --;
                }
                result << "\n";
            }
        }
        //end
        finish = clock();
		totaltime = finish - start;
        time << totaltime << "clock(s)" << endl;
    }

    return 0;
}