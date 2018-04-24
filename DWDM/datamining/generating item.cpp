//creating item set

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <ctime>
#include <fstream>
using namespace std;

struct data{
	int n;
	string tid;
	string arr[10];
	
};

int main(){
	ofstream fout;
	fout.open("bill.txt");
	static string tid;
	static string item;
	tid="T";
	item="I";
	int n;
	srand(time(NULL));
	n=rand()%10;
	struct data d[n];
	for(int i=0;i<n;i++){
		char ch[10];
		itoa(i,ch,10);
		d[i].tid=tid+ch;
		int cnt;
		cnt=rand()%10;
		d[i].n=cnt;
		for(int j=0;j<cnt;j++){
			char ch[10];
			itoa(j,ch,10);
			d[i].arr[j]=item+ch;
		}
	}
	for(int i=0;i<n;i++){
		fout<<d[i].tid<<"   :   ";
		for(int j=0;j<d[i].n;j++){
			fout<<d[i].arr[j]<<"  ";
		}
		fout<<endl;
	}
	fout.close();
	return 0;
}
