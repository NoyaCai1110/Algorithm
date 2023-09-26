#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int pre[30];
int rk[30];

void MAKE_SET(int i){
	pre[i] = i;
	rk[i] = 0;
}

int Find_pre(int i){
    int p, tmp, root;
    root = i;
    while(root != pre[root])
        root = pre[root];
    p = i;        
    while(p != root) 
    {
        tmp = pre[p]; 
        pre[p] = root; 
        p = tmp; 
    }
    return root;    
}

void UNION(int i,int j){
    i = Find_pre(i);
    j = Find_pre(j);
    if(i == j) 
        return ;
    if(rk[i] > rk[j]) 
        pre[j] = i;
    else{
        pre[i] = j;
        if(rk[i] == rk[j]) 
            rk[j] ++;  
    }
}

int main(){
    ifstream inputfile;
	inputfile.open("..\\input\\2_2_input.txt", ios::in);
    ofstream result("..\\output\\result.txt", ios::app);
    ofstream time("..\\output\\time.txt", ios::app);
	if (!inputfile.is_open())
		cout << "read file failed" << endl;
    int N[5] = {10, 15, 20, 25, 30};
    int M[30][30] = {0};
    int F = 0;
    clock_t start, finish, totaltime;
    for(int j = 0; j < 5; j ++){
		start = clock();
        F = 0;
        for(int i = 0; i < N[j]; i ++){
            MAKE_SET(i);
            for(int k = 0; k < N[j]; k ++){
                inputfile>>M[i][k];
            }
        }
        for(int i = 0; i < N[j]; i ++){
            for(int k = 0; k < N[j]; k ++){
                if(M[i][k] == 1 && i != k)
                    UNION(i, k);
            }
        }
        for(int i = 0; i < N[j]; i ++){
            if(pre[i] == i)
                F ++;
            //cout << pre[i] << endl;
        }
        finish = clock();
		totaltime = finish - start;
        result << "n="<< N[j] << " Family number: " << F << endl;
        time << "n="<< N[j] << " Runtime:" << totaltime << " clock(s)" << endl;
    }
    return 0;
}