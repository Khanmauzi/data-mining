/*
	Name :Mojnammil
	class : Btech III year
	roll : 157238
	Binning problem
*/

//bin size is 3
#include <bits/stdc++.h>
using namespace std;



int bin=3;			//each bin will contain 3 elements

void getdata(ifstream &fin,vector<int>&v){
	while(!fin.eof()){
		string s;
		getline(fin,s);
		int i=0;
		while(s[i]){
			if(s[i]>='0'&&s[i]<='9'){
				int k=0;
				while(s[i]>='0'&&s[i]<='9'){
					k=k*10+s[i]-'0';
					i++;
				}
				v.push_back(k);
			}
			else i++;
		}
	}
	sort(v.begin(),v.end());				//sorting the vector
/*	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	cout<<*it<<" ";*/
}
void display(vector<int>v){
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void display_bin(vector<vector <int> >b){
	vector<vector<int> >::iterator it;
	for(it=b.begin();it!=b.end();it++){
		vector<int>temp=*it;
		display(temp);
	}
}
void getbin(vector<vector <int> >&b,vector <int>v){
	vector<int>::iterator it;
	it=v.begin();
	while(it!=v.end()){
		vector<int>temp;
		for(int i=0;i<bin;i++){
			temp.push_back(*it);
			it++;
			if(it==v.end())
			break;
		}
		b.push_back(temp);
	}
	
}
vector<vector <int> > mean(vector <vector <int> >&b){
	vector<vector <int> >::iterator it;
	vector<vector <int> >b1;
	for(it=b.begin();it!=b.end();it++){
		int sum=0;
		vector <int>temp=*it;
		for(vector<int>::iterator it1=temp.begin();it1!=temp.end();it1++){
			sum=sum+*it1;
		}
		sum=sum/bin;
		vector<int> temp1;
		for(int i=0;i<bin;i++){
			temp1.push_back(sum);
		}
		b1.push_back(temp1);
	}
	return b1;
}
void boundary(vector <vector <int> >&b,vector <vector <int > >&b1){
	vector<vector <int> >::iterator it;
	for(it=b.begin();it!=b.end();it++){
		int first=0;
		int last=0;
		vector <int>temp=*it;
		vector<int>::iterator it1,it2=temp.begin();
		it1=temp.begin();
		first=*it1;
		it1=temp.end();
		it1--;
		last=*it1;
		vector<int> temp1;
		temp1.push_back(first);
		it2++;
		if((*it2-first)<(last-*it2))
		temp1.push_back(first);
		else 
		temp1.push_back(last);
		temp1.push_back(last);
		b1.push_back(temp1);
	}
}
int main(){
	ifstream fin;
	fin.open("bininput.txt");
	vector<int>v;
	getdata(fin,v);
	vector<vector<int> >b,b1,b2;
	getbin(b,v);
	cout<<"Partition into (equal -frequency ) bins: "<<endl;
	display_bin(b);
	
	cout<<"*******************************************************"<<endl;
	
	b1=mean(b);
	cout<<"Smoothin by bin means:"<<endl;
	display_bin(b1);
	
	cout<<"***********************************************************"<<endl;
	
	boundary(b,b2);
	cout<<"smoothin by bin boundaries : "<<endl;
	display_bin(b2);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
