//test code
#include <iostream>
using namespace std;
struct node {
	int data;
	node *left;
	node *right;
};
node *create(node *t,int x){
	if(t==NULL){
		t=new(node);
		t->data=x;
		t->left=NULL;
		t->right=NULL;
		return t;
	}
	else if(x>t->data)
	t->right=create(t->right,x);
	else
	t->left=create(t->left,x);
	return t;
}

void print(node *t){
	if(t==NULL)
	return;
	print(t->left);
	cout<<t->data<<" ";
	print(t->right);
}

int main(){
	node *t;
	t=NULL;
	int x;
	while(1){
		cin>>x;
		if(x==-1)
		break;
		t=create(t,x);
	
	}
	print(t);
	return 0;
}
