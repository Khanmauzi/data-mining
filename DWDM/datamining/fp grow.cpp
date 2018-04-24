/*	THRESHOLD VALUE FOR THIS PROGRAM IS 2 BY DEFAULT
	name :MOJAMMIL
	BTECH 3 YEAR
	157238
	15-19 BATCH
	FP-GROWTH TREE
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#defin null NULL
using namespace std;
typedef struct node{
	int data;
	int cnt;
	vector <node *>child;
	node *next;
}*fptr;

struct table{
	int item;
	int cnt;
	node *point;
};







int main(){
	int th=2;
	ifstraem fin;
	fin.open("bill2.txt");
	map<vector<int>,int>m,l;
	getdata(m,fin);						//get the count of each item in map
	getl(m,l,th);						//get all the itmes which satisfy the threshold condition
	int n=l.size();						//get the size of the table
	table data[n];						
	gettable(data,n,l);					//get the value in data table in decreasing order
	
}




