/*
	Name :Mojnammil
	class : Btech III year
	roll : 157238
	CODE FOR FP GROWTH TREE
*/
#include <bits/stdc++.h>
using namespace std;
struct fpnode{
	map<int,int>node;
	vector<fpnode *>child;
	fpnode *next;
};
struct data{
	int id;
	int cnt;
	fpnode *nodelink;
};
void getfirst(ifstream &fin,map<int,int>&m){
	while(!fin.eof()){
		string s;
		getline(fin,s);
		int i=0;
		while(s[i]){
			int k=0;
			if(s[i]=='I'){
				i++;
				while(s[i]>='0'&&s[i]<='9'){
					k=k*10+s[i]-'0';
					i++;
				}
			if(m.find(k)==m.end()){
				m.insert(pair<int,int>(k,1));
			}
			else
			m[k]++;
			}
			else i++;
		}
	}
}
void print(map<int,int>m){
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
		cout<<it->first<<"   "<<it->second<<endl;
	}
}
void getdata(struct data d[],int n,map<int,int>m){
	int i=0;
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
		d[i].id=it->first;
		d[i].cnt=it->second;
		i++;
	}
	for(int i=1;i<n;i++){
		int j=i-1;
		data d1=d[i];
		while(j>=0&&d1.cnt>d[j].cnt){
				d[j+1]=d[j];
				j=j-1;
				}
				d[j+1]=d1;
			}
}
void showdata(struct data d[],int n){
	cout<<"ITEM          COUNT "<<endl;
	for(int i=0;i<n;i++){
		cout<<"I"<<d[i].id<<"               "<<d[i].cnt<<endl;
	}
}
void getv(vector<int>&v,ifstream &fin){
	string s;
	getline(fin,s);
	int i=0;
	while(s[i]){
		if(s[i]=='I'){
			i++;
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
fpnode* create(fpnode *t,vector<int>::iterator &it,vector<int>::iterator it1){
	if(it==it1)
	return t;
	else{
	if(t==NULL){
		t=new(fpnode);
		cout<<" in t== null "<<endl;
		t->node.insert(pair<int,int>(*it,1));
		it++;
		fpnode *t1=NULL;
		t->child.push_back(create(t1,it,it1));
		return t;
	}else{
		if(t->node.find(*it)!=t->node.end()){
			cout<<"root already exist "<<endl;
			t->node[*it]++;
			it++;
			fpnode *t1=NULL;
			vector<fpnode *>::iterator it3;
			vector<fpnode *>v1=t->child;
			it3=v1.begin();
			while(it3!=v1.end()&&it!=it1){
				fpnode *t2=*it3;
				if(t2->node.find(*it)!=t2->node.end()){
					t1=t2;
					break;
				}
				it3++;
			}
		   	t->child.push_back(create(t1,it,it1));
			return t;
		}
	}
  }
	return t;
}
void check(fpnode *t){
	if(t==NULL)return;
	map<int,int>::iterator it1=t->node.begin();
	cout<<it1->first<<" "<<it1->second<<"  "<<endl;
	vector<fpnode *>::iterator it;
	for(it=t->child.begin();it!=t->child.end();it++){
		check(*it);
	}
	
}
int main(){
	map<int,int>m;
	
	ifstream fin;
	fin.open("bill2.txt");
	getfirst(fin,m);							//get the item and frequency of each item
	int n=m.size();
	struct data d[n];
	getdata(d,n,m);								//store the item in the data structure based on the decreasing count
	print(m);									//print the map
	showdata(d,n);								//print the data structure
	fin.close();	
	fpnode *root;
	root=new(fpnode);
	root->node.insert(pair<int,int>(0,0));
//	if(root->node.find(0)!=root->node.end()){
//		root->node[0]++;
//	}
//	map<int,int>::iterator it=root->node.begin();
//	cout<<it->first<<" "<<it->second;
	fin.open("bill2.txt");
	while(!fin.eof()){
		vector<int>v;
		getv(v,fin);
		if(fin.eof())
		break;
		vector<int>::iterator it=v.begin();
		vector<int>::iterator ite=v.end();					//iterator for vector
		vector<fpnode*>::iterator it1;						//iteratro for child
		fpnode *t=NULL;
		vector<fpnode*>v1=root->child;						//child of all root
		it1=v1.begin();
		while(it1!=v1.end()){
			fpnode *t1=*it1;
			if(t1->node.find(*it)!=t1->node.end()){
				t=t1;
				break;
			}
			it1++;
		}
		t=create(t,it,ite);
		check(t);
		root->child.push_back(t);
		//cout<<endl;
		cout<<"hello"<<endl;
	}
	 //show(root);
}
