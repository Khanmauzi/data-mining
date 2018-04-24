//generating association rule
//apriory algorithm

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
void getfirst(map<vector<int>,int>&m,ifstream &fin){
	
	while(!fin.eof()){
		string s;
		getline(fin,s);				//read each line of file
		if(fin.eof())
		break;
	//	cout<<s<<endl;
		int i=0;
		while(s[i]){
			if(s[i]=='I'){
				i++;
				int n=s[i]-'0';
				//cout<<n<<" ";
					vector<int>v;		//insert value in vector
					v.push_back(n);
				if(m.find(v)==m.end()){
				//	cout<<"found "<<endl;
				
					m.insert(pair<vector<int>,int>(v,1));				//vector is not present in map so make pair and initilize count to 1
				}
				else{
				//	cout<<"not found "<<endl;
					m[v]++;												//else increment the count
				}
			}
			else 
			i++;
		}
	}
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
vector<vector<int> >getsubset(vector<int>v){
	vector <vector <int> >subset;
	vector <int>empty;
	subset.push_back(empty);
	for(int i=0;i<v.size();i++){
		vector <vector<int> > temp=subset;
		for(int j=0;j<temp.size();j++){
			temp[j].push_back(v[i]);
		}
		for(int j=0;j<temp.size();j++){
			subset.push_back(temp[j]);
		}
	} 
	return subset;
}

void show(vector<int>t){
	vector<int>::iterator it;
	for(it=t.begin();it!=t.end();it++){
		cout<<*it<<" ";
	}//cout<<" / ";
	//for(it=v.begin();it!=v.end();it++){
	//	cout<<*it<<" ";
	//}
}
int get(vector<int>t,map<vector<int>,int>fq){
	
	map<vector<int>,int>::iterator it;
	it=fq.find(t);
	return it->second;
	
	
}
double result(vector<int>t,int cnt,map<vector<int>,int> fq){
	
	int x=get(t,fq);
	if(x==0)
	return 0;
///	cout<<"X "<<x;
	double d;
	d=double(cnt)/double(x);
	return d;
	
}
void getassociation(vector<int>v,int cnt,map<vector<int>,int> fq){
	vector<vector<int> >s;
	s=getsubset(v);
	vector<vector<int > >::iterator it;
	for(it=s.begin();it!=s.end();it++){
		vector<int>temp=*it;
		cout<<"************ ";show(v);
		cout<<"percentage of association of ";show(temp);cout<<" is : "<<result(temp,cnt,fq)<<endl;
	}
	
	
}
int main(){
	ifstream fin;
	fin.open("bill2.txt");
	cout<<"enter the threshold value : ";
	int th;
	cin>>th;
	cout<<"Threshhod value of this program is : "<<th<<endl;
	map<vector<int>,int>m,l,c;									//this will store set of items and its count
	map<vector<int>,int>fq;								//this will store the freqency of each item set and will be used in generating association rule
	getfirst(m,fin);											//this function will get itemset having only one item and its count
	fq=m;
	cout<<"printing c1 : "<<endl;	
	printf(m);
	c=m;													//this function will simply print map
	getfirstl(m,l,th);											// this function will get itemset in l having count greater than or equal to threshhold value;
	cout<<"printint L1 : "<<endl;
	printf(l);
	cout<<endl;
	int cnt=2;
	fin.close();
	while(1){
	//	ifstream fin;
	//	fin.open("bill.txt");
		c=l;
		joining(m,l,fin);										//it will join itemsset in l and put them in m
    	cout<<"Printing C"<<cnt<<"  : "<<endl;
		printf(m);				
		map<vector<int>,int>::iterator it;
		for(it=m.begin();it!=m.end();it++){
			fq.insert(pair<vector<int>,int>(it->first,it->second));
		}
		getfirstl(m,l,th);				             		//support itemset with count greater than or equal to threshhold
		if(l.size()==0)	
		break;
		cout<<"Printing L"<<cnt<<"  : "<<endl;										
		printf(l);
		cnt++;
	
	
	}
	cout<<"finale frequent item set is : "<<endl;
	printf(c);
	cout<<endl;
	map<vector<int>,int>::iterator it;
	for(it=c.begin();it!=c.end();it++){
		getassociation(it->first,it->second,fq);
	}
	
	//printf(fq);
	return 0;
	
}
