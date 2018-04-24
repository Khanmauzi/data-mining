/*
	Name :Mojnammil
	class : Btech III year
	roll : 157238
	CODE FOR MISSING VALUES DATA
*/
#include <bits/stdc++.h>
#include <string>
using namespace std;
string br="NIT";
string nm="NULL";
void getavg(ifstream &fin,float &x){
	int cnt=0;
	while(!fin.eof()){
		string s;
		getline(fin,s);
		int i=0;
		while(s[i]){
			if(s[i]>='0'&&s[i]<='9'){
				cnt++;
				float temp=0;
				while(s[i]>='0'&&s[i]<='9'){
					temp=temp*10+s[i]-'0';
					i++;
				}
				x=x+temp;
			}
			else i++;
		}
	}
	x=x/cnt;
}
int main(){
	ifstream fin;
	fin.open("college record.txt");
	float avg=0;
	getavg(fin,avg);						//get average of data
	char avg1[10];
	sprintf(avg1,"%f",avg);
	string average="";
	for(int i=0;i<5;i++)
	average=average+avg1[i];
	fin.close();
	fin.open("college record.txt");
	ofstream fout;
	fout.open("new record.txt");
	while(!fin.eof()){
		string s;
		getline(fin,s);				//read one tupple from the file
	//	cout<<s<<endl;
		if(fin.eof())
		break;
		string name="";
		string branch="";
		string percent="";
		int i=0;
		int flag1=0;			//to check if branch is missing 
		int flag2=0;			//to check is percentage is missing
		int flag3=0;			// to check if name is missing
		while(s[i]){
			
			if((s[i]>='a'&&s[i]<='z')||s[i]>='A'&&s[i]<='Z'){
				while(s[i]!=' '){
					name=name+s[i];
					i++;
				}
				flag3=1;
			}
			while(s[i]==' '){
				i++;
			}
			if((s[i]>='a'&&s[i]<='z')||s[i]>='A'&&s[i]<='Z'){
				while(s[i]!=' '){
					branch=branch+s[i];
					i++;
				}
				flag1=1;
			}
			while(s[i]==' '){
				i++;
			}
			if(s[i]>='0'&&s[i]<='9'){
				flag2=1;
				while(s[i]>='0'&&s[i]<='9'){
					percent=percent+s[i];
					i++;
				}
			}
		}
		if(flag1==0){					//branch is missing
			branch=br;
		}
		if(flag2==0){					//percentage is missing
			percent=average;
		}
		if(flag3==0){					//name is missing
			name=nm;
		}
		cout<<name<<"      "<<branch<<"    "<<percent<<endl;
		fout<<name<<"      "<<branch<<"    "<<percent<<endl;
	}

}
