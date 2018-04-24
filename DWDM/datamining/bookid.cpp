//generating normal item;
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main(){
	ofstream fout;
	fout.open("bill2.txt");
	fout<<"T1\t\t I1,I2,I5"<<endl;
	fout<<"T2\t\t I2,I4"<<endl;		
	fout<<"T3\t\t I2,I3"<<endl;
	fout<<"T4\t\t I1,I2,I4"<<endl;
	fout<<"T5\t\t I1,I3"<<endl;
	fout<<"T6\t\t I2,I3"<<endl;
	fout<<"T7\t\t I1,I3"<<endl;
	fout<<"T8\t\t I1,I2,I3,I5"<<endl;
	fout<<"T9\t\t I1,I2,I3"<<endl;
	return 0;
	
}
