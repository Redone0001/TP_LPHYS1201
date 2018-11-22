#include <iostream>
#include <string>
#include <vector>
#include "include/histogramme.h"

using namespace std;

int main(){

	histogramme test;
	
	test.set_values(0,10,10);
cout <<"values set"<<endl;
	for (int i=0; i<10;i++){
		
		for(int j=0; j<i;j++){
			
			test.fill(i);
		
		}
	}
	test.print();
	test.~histogramme();

return 0;
}
