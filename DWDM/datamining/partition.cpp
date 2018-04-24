// partitioning

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <iterator>
using namespace std;
struct partition{
	vector<vector <int> >v;
};
void getp(partition &p,int n,ifstream &fin){
	string s;
	//cout<<"in partiton "<<endl;
	for(int i=0;i<n;i++){
		getline(fin,s);
		if(fin.eof()){
		cout<<"file end "<<endl;
		return ;}
		cout<<s<<endl;
		int j=0;
	//	vector<vector<int> >v;
		vector <int>v1;
		while(s[j]){
			if(s[j]=='I'){
				j++;
				int k=s[j]-'0';
			//	cout<<k<<endl;
				v1.push_back(k);
			//	cout<<k<<end l;
			}
			else
			j++;
		}
		//v.push_back(v1);
		p.v.push_back(v1);
	}
}
void print(partition p,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<p.v[i].size();j++)
		cout<<"I"<<p.v[i][j]<<"  ";
		cout<<endl;
	}
}
void show(partition part[],int n){
	for(int i=0;i<n;i++){
		cout<<i+1<<" parition is : "<<endl;
		print(part[i],n);
		cout<<"*********************************"<<endl;
	}
}
void getfirst(map<vector<int>,int>&m,partition p){
	for(int i=0;i<p.v.size();i++){
		vector<int>v1;
		v1=p.v[i];
		for(int j=0;j<v1.size();j++){
			vector<int>v2;
			v2.push_back(v1[j]);
			if(m.find(v2)==m.end()){
				m.insert(pair<vector<int>,int>(v2,1));
			}
			else{
				m[v2]++;
			}
		}
	}
}
void getfirstl(map<vector<int>,int>&l,map<vector<int>,int>m,double k){
	l.clear();
//	cout<<"*(*)"<<k<<endl;
	map<vector<int>,int>::iterator it;
	for(it=m.begin();it!=m.end();++it){
	//	double d=(double)it->second;
	//	d=d/3;
	//	cout<<d<<" D  ";
		if(it->second>=1){															//if itemset count is greater than threshold value
			l.insert(pair<vector<int>,int>(it->first,it->second));
		}
	}
}
void printf(map<vector<int>,int>m){
	map<vector<int>,int>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		vector<int>v=it->first;
		vector<int>::iterator it1;
		for(it1=v.begin();it1!=v.end();it1++){
			cout<<"I"<<*it1<<"  ";
		}
		cout<<" : "<<it->second<<endl;
	}
}
bool check(vector<int>v1,vector<int>v2){												//check if first n-1 elements of two vector are same
	if(v1.size()==1)
	return true;
	int i=0;
	while(i<v1.size()-1){
		if(v1[i]!=v2[i])
		return false;
		i++;
	}
	return true;
}
bool check2(vector<int>v1,vector<int>v2){
	int i=0;
	int j=0;
//	sort(v1.begin(),v1.end());
//	sort(v2.begin(),v2.end());
	while(i<v1.size()){
		j=0;
		int flag=0;
		while(j<v2.size()){
			if(v1[i]==v2[j]){
				flag=1;
				break;
			}
			j++;
		}
		i++;
		if(flag==0)
		return false;
	}
	return true;
}
void joining(map<vector<int>,int> &m,map<vector<int>,int>&l,partition p){
	vector<vector<int> >v;
	m.clear();
	map<vector<int>,int>::iterator it,it1;
	for(it=l.begin();it!=l.end();++it){
		vector<int>temp1=it->first;
		for(it1=++it;it1!=l.end();++it1){
			vector<int>temp2=it1->first;
			if(check(temp1,temp2)){
				vector<int>temp3=temp1;
				temp3.push_back(temp2[temp2.size()-1]);
				v.push_back(temp3);												//storing items in vector of vector
			}
		}
		it--;
	}
//	cout<<"hello"<<endl; ;
	vector<vector<int> >::iterator it3;
	int cnt=0;
	for(it3=v.begin();it3!=v.end();it3++){			
		//cout<<"hi ";
		vector<int>temp=*it3;
	/*	vector<int>::iterator it;
		vector<int>t1;
		for(it=temp.begin();it!=temp.end();it++){
			t1.push_back(*it);
			//cout<<*it<<"  ";
		}*/
	//	cout<<endl;
		for(int i=0;i<p.v.size();i++){
		vector<int>t2=p.v[i];
		if(check2(temp,t2)){										//checking it itemset of temp is present in t2 or not
			if(m.find(temp)==m.end()){								//checking if itemset is already present in map or not
				m.insert(pair<vector<int>,int>(temp,1));			//not present making pair
			}
			else
			m[temp]++;												//present making its pair
		}
		}
	}
	//vector<vector<int> >::iterator it3;
	/*for(it3=v.begin();it3!=v.end();++it3){
		vector<int>temp=*it3;
		vector<int>::iterator it1;
		for(it1=temp.begin();it1!=temp.end();it1++)
		cout<<"I"<<*it1<<"  ";
		cout<<endl;
	}*/
	//cout<<"*******************************"<<cnt<<endl;
}
void getlocal(partition part,map<vector<int>,int>&l,float th1){
	map<vector<int>,int>m1,l1,c;
	getfirst(m1,part);
	cout<<" C1"<<endl;
	printf(m1);
	cout<<endl;
	getfirstl(l1,m1,th1);
	cout<<"L1 "<<endl;
	printf(l1);
	int cnt=2;
	cout<<"********************************"<<endl;
		while(1){
	//	ifstream fin;
	//	fin.open("bill.txt");
		c=l1;
		joining(m1,l1,part);										//it will join itemsset in l and put them in m
    	cout<<"Printing C"<<cnt<<"  : "<<endl;
		printf(m1);				
	
		getfirstl(l1,m1,th1);				             		//support itemset with count greater than or equal to threshhold
		if(l1.size()==0)	
		break;
		cout<<"Printing L"<<cnt<<"  : "<<endl;										
		printf(l1);
		cnt++;
	
	
	}
	//cout<<"###################################"<<endl;
	//printf(c);
	//cout<<"######################################"<<endl;
	map<vector<int>,int>::iterator it;
	for(it=c.begin();it!=c.end();it++){
		vector<int>temp=it->first;
		int k=it->second;
		//l.insert(pair<vector<int>,int>(temp,k));
		l.insert(pair<vector<int>,int>(it->first,it->second));
	}
}
int main(){
	ifstream fin;
	fin.open("bill2.txt");
	//cout<<"hi "<<endl;
	double th=2/9;			//global minimum support
	int n=3;				//number of partiton
	partition part[n];
	int i=0;
	while(!fin.eof()){
	//	cout<<i<<endl;
		if(fin.eof())
		break;
		else{
	//		cout<<"in else "<<endl;
		//	if(i==3)break;
			getp(part[i],n,fin);
		//	cout<<"hi "<<endl;
			i++;
		}
	}
//	cout<<"hello"<<endl;
	int size=i;
	show(part,n);
	double th1=2.0/3	;				//since the size of each partition is 3 ,so th1=(2/9)*3 which min supp for each partition
	map<vector<int>,int>l,g;
//	cout<<"th1 "<<th1<<endl;
	for(int i=0;i<n;i++){
		cout<<i+1<< " partition "<<endl;
		getlocal(part[i],l,th1);
	}
	cout<<"Local itemset are : "<<endl;
	printf(l);
	return 0;
}
