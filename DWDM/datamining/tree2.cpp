#include <iostream>
#define null NULL
using namespace std;
typedef struct node{
	node *lchild;
	node *rchild;
	int data;
}*bptr;
void create(bptr &t,int x){
	if(t==null){
		t=new(node);
		t->data=x;
		t->lchild=null;
		t->rchild=null;
	}
	else{
		if(t->data<x)
		create(t->rchild,x);
		else
		create(t->lchild,x);
	}
}

void print(bptr t){
	if(t==null)
	return;
	print(t->lchild);
	cout<<t->data<<" ";
	print(t->rchild);
}
int main(){
	bptr t;
	t=null;
	int x;
	while(1){
		cout<<"enter data (-1 to exit) : ";
		cin>>x;
		if(x==-1)
		break;
		create(t,x);
	}
	print(t);
	return 0;
}
