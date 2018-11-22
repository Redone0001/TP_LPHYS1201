#include <iostream>
#include <string>
#include <vector>
#pragma once
class histogramme{

	float debut;
	float fin;
	int interval;
	std::vector <int> barre;
	public :
	void set_values(float,float,int);
	void fill(double);
	void print();
};

