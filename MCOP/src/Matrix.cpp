#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;
const long long MAX = 9223372036854775807;
ofstream result("..\\output\\result.txt", ios::app);

void MATRIX_CHAIN_ORDER(long long *p, long long m[][30], int s[][30], int N){
	int n = N;
    long long q;
	for(int i = 1; i <= n; i ++) 
        m[i][i] = 0;
	for(int l = 2; l <= n; l ++){
		for(int i = 1; i <= n-l+1; i ++){
			int j = i + l - 1;         
			m[i][j] = MAX;
			for(int k = i; k <= j-1; k ++){
				q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}
void PRINT_OPTIMAL_PARENS(int s[][30], int i, int j){
	if(i == j) 
        result<<"A"<<i;
	else{
		result<<"(";
		PRINT_OPTIMAL_PARENS(s, i, s[i][j]);
		PRINT_OPTIMAL_PARENS(s, s[i][j]+1, j);
		result<<")";
	}
}
int main(){
	//input N & set p[30] & set timer
	int N;
	long long p[30];
	ifstream inputfile("..\\input\\1_1_input.txt", ios::in);
	ofstream time("..\\output\\time.txt", ios::app);
	while(inputfile>>N){
		for(int i = 0; i <= N; i ++){
			inputfile>>p[i];
		}
		clock_t start, finish, totaltime;
		//start timing
		start = clock();
		//start program
		long long m[30][30]; 
		int s[30][30];
		MATRIX_CHAIN_ORDER(p, m, s, N);
		//end timing
		finish = clock();
		totaltime = finish - start;
		time<<"Runtime:"<<totaltime<<" clock(s)"<<endl;
		result<<"Least multiply times: "<<m[1][N]<<"\n";
		result<<"Best solution: "; 
		PRINT_OPTIMAL_PARENS(s, 1, N);
		result<<"\n";
	}
	result<<"\n";
	time<<"\n";
	return 0;
}
