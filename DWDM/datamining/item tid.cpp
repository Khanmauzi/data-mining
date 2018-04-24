//transacction of item 

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#include <iterator>
using namespace std;

int main(){
	ifstream fin;
	fin.open("bill.txt");
	ofstream fout;
	fout.open("items tr.txt");
	map <int,vector<int> >m;
	map <int,vector<int> >::iterator it;
	int cnt=0;
	//cout<<"hei ";
	while(!fin.eof()){
		string s;
		//cout<<"hello";
		getline(fin,s);
	//	cout<<s<<endl;
		if(fin.eof())
		break;
		int i=0;
		while(s[i]){
			if(s[i]=='I'){
				i++;
				int n;
				n=s[i]-'0';
			//	cout<<s<<"  :  "<<n<<endl;
				it=m.find(n);
				if(it==m.end()){
					vector<int>v;
					v.push_back(cnt);
					m.insert(pair<int,vector<int> >(n,v));					//putting it first time
				}
				else
				it->second.push_back(cnt);
			}
			else
			i++;
		}
	//	cout<<"*************************************"<<endl;
		cnt++;
	}
	cout<<"Item number :   Transactions number "<<endl;
	fout<<"Item number :   Transactions number "<<endl;
	for(it=m.begin();it!=m.end();it++){
		cout<<it->first<<"           : \t";
		fout<<it->first<<"           : \t";
		vector<int>v=it->second;
		vector<int>::iterator it1;
		it1=v.begin();
		while(it1!=v.end()){
		     cout<<*it1<<"  ";
		     fout<<*it1<<"  ";
		    it1++;
			}
			fout<<endl;
			cout<<endl;
	}
	
}
