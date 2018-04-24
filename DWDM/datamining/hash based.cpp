//hash based-techinque
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <map>
using namespace std;
struct data{
	int x;				//to store itemset
	int y;
};
struct hash{
	int cnt;				//count of bucket
    vector<data> v;
};

void gethash(hash h[],int n,ifstream &fin){					//hash function used is h(x,y)=((order of x)x10+(order of y))mod 7
	string s;
	while(!fin.eof()){
		getline(fin,s);				//reading each line of input file
		if(fin.eof())				//if end of file is reached
		break;
		//cout<<s<<endl;
		vector<int>v;
		int i=0;
		while(s[i]){
			if(s[i]=='I'){
				i++;
				int k;
				k=s[i]-'0';
				v.push_back(k);
				//cout<<k<<"  ";
			}
			else 
			i++;
		}
		vector<int>::iterator it,it1;
		data d;
		for(it=v.begin();it!=v.end();it++){
			int x=*it;
			for(it1=++it;it1!=v.end();++it1){
				int y=*it1;
				d.x=x;
				d.y=y;
				//cout<<d.x<<" && "<<d.y<<endl;
				h[((x*10)+y)%n].v.push_back(d);				//storing item in bucket address
				h[((x*10)+y)%n].cnt++;
			}
			it--;
		}
		
	}
}
void display(hash h[],int n){
	cout<<"Bucket address     Bucket count            bucket contents  "<<endl;
	for(int i=0;i<n;i++){
		cout<<i<<"\t\t\t"<<h[i].cnt<<"\t\t  ";
		vector <data>v=h[i].v;
		vector<data>::iterator it;
		for(it=v.begin();it!=v.end();it++){
			data d=*it;
			cout<<"{ I"<<d.x<<", I"<<d.y<<" } ";
		}
		cout<<endl;
	}
}
void getl(hash h[],map<vector <int>,int>&l,int n,int th){
	l.clear();
	for(int i=0;i<n;i++){
		if(h[i].cnt>=th){								//check if particlar bucket has count greater than or equl to threshold
			vector<data>v=h[i].v;
			vector<data>::iterator it,it1;
			for(it=v.begin();it!=v.end();it++){
				data d=*it;
				int cnt=1;
				 vector<int>v1;
				for(it1=++it;it1!=v.end();it1++){
					data d1=*it1;
					if(d.x==d1.x&&d.y==d1.y&&d.x!=-1){						//check the count of each pair.
						cnt++;
						d1.x=-1;	
					}
				}
				v1.push_back(d.x);
				v1.push_back(d.y);
				if(cnt>=th)
				l.insert(pair<vector<int>,int>(v1,cnt));
				it--;
			}
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
void joining(map<vector<int>,int> &m,map<vector<int>,int>&l,ifstream &fin){
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
		fin.open("bill2.txt");
	//	cnt++;
	//	cout<<"*************** "<<endl;
		while(!fin.eof()){
		string s;
		
		vector<int>t2;
		getline(fin,s);
	//	cout<<s<<endl;
		if(fin.eof())
		break;
		int i=0;
		while(s[i]){
			if(s[i]=='I'){
				i++;
				int n=s[i]-'0';
			//	cout<<n<<"$#$#  ";
				t2.push_back(n);
			}
			else i++;
		}
		if(check2(temp,t2)){										//checking it itemset of temp is present in t2 or not
			if(m.find(temp)==m.end()){								//checking if itemset is already present in map or not
				m.insert(pair<vector<int>,int>(temp,1));			//not present making pair
			}
			else
			m[temp]++;												//present making its pair
		}
		}
		fin.close();
	}
	//vector<vector<int> >::iterator it3;
	for(it3=v.begin();it3!=v.end();++it3){
		vector<int>temp=*it3;
		vector<int>::iterator it1;
		for(it1=temp.begin();it1!=temp.end();it1++)
		cout<<"I"<<*it1<<"  ";
		cout<<endl;
	}
	//cout<<"*******************************"<<cnt<<endl;
} 
void getfirstl(map<vector<int>,int>&m,map <vector<int>,int> &l,int k){				//getting itemset set with minimum cutoff 
	l.clear();
	map<vector<int>,int>::iterator it;
	for(it=m.begin();it!=m.end();++it){
		if(it->second>=k){															//if itemset count is greater than threshold value
			l.insert(pair<vector<int>,int>(it->first,it->second));
		}
	}
}
int main(){
	
	int n=7;
	hash h[7];
	for(int i=0;i<7;i++){
		h[i].cnt=0;
	}
	ifstream fin;
//	cout<<"hi ";
	fin.open("bill2.txt");
	gethash(h,n,fin);					//stored 2 itemsubset in hash table;
	display(h,n);						//display hash table
	int th;
	cout<<"enter the threshhold value : ";
	cin>>th;
	// now form l2 from hash and then follow the apriory algorithm
	map<vector<int>,int>m,l,c;
	getl(h,l,n,th);
	int cnt=2;
	cout<<"printing L"<<cnt<<" : "<<endl;
	printf(l);
	cnt++;
	fin.close();
	while(1){
	//	ifstream fin; 
	//	fin.open("bill.txt");
		c=l;
		joining(m,l,fin);										//it will join itemsset in l and put them in m
    	cout<<"Printing C"<<cnt<<"  : "<<endl;
		printf(m);				
	
		getfirstl(m,l,th);				             		//support itemset with count greater than or equal to threshhold
		if(l.size()==0)	
		break;
		cout<<"Printing L"<<cnt<<"  : "<<endl;										
		printf(l);
		cnt++;
	
	
	}
	cout<<"finale frequent item set is : "<<endl;
	printf(c);
	return 0;
//	return 0;
}
