// to count the frequency of each item

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <iterator>

using namespace std;
int main(){
	fstream fin;
	fin.open("bill.txt");
	ofstream fout;
	fout.open("item frequency.txt");
	map<int,int>m;
	map<int ,int>::iterator it;
    it=m.begin();
  //  int cnt=0;
/*	while(!fin.eof()){
		char ch;
		fin>>ch;
		if(fin.eof())
		if(ch=='\n')
		cnt++;
		break;
		if(ch=='I'){
			fin>>ch;
			int n=ch-'0';
			it=m.find(n);
			if(it==m.end()){
				m.insert(pair<int,int>(n,1));
			}
			else 
			it->second++;
		}
	}*/
	while(!fin.eof()){
		string s;
		getline(fin,s);
		if(fin.eof())
		break;
		int i=0;
		while(s[i]){
			if(s[i]=='I'){
				i++;
			int n=s[i]-'0';
			it=m.find(n);
			if(it==m.end()){
				m.insert(pair<int,int>(n,1));
			}
			else 
			it->second++;
		}
		else i++;
		}
//		cnt++;
	}
//	cout<<cnt<<endl;
	for(it=m.begin();it!=m.end();it++){
		cout<<"I"<<it->first<<" : "<<it->second<<endl;
		fout<<"I"<<it->first<<" : "<<it->second<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
