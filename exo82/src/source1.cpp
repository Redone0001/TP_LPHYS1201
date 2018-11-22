#include <iostream>
#include <string>
#include <vector>
#include "../include/histogramme.h"

using namespace std;
void histogramme::set_values(float a ,float b,int x){

	for(int i = 0 ; i<x;i++){
		barre.push_back(0);
	}
	fin = b;
	debut=a;
	interval=x;

};
void histogramme::fill(double x){

	int k = (x-debut)* interval/(fin-debut);
	barre.at(k)++;

}
void histogramme::print(){

	if(interval <50){
		int largeur = 50/interval;
		cout <<"Echelle de largeur : "<<largeur<<"x"<<endl;
		int tailleMax=0;
		for(int i = 0; i<interval; i++){
			if (barre.at(i)>tailleMax){
				tailleMax = barre.at(i);
				cout <<tailleMax<<endl;
			}		
		}
		cout<<"Echelle de hauteur : "<<"1x"<<endl;
		vector<int>barreCor;
		for (int i=0; i<barre.size();i++){
			barreCor.push_back(barre.at(i));
		}	
		//partie où nous allons tout afficher
		for(auto x:barreCor){
			cout<<x<<"/";
		}
		cout <<endl;
		for (int ligne= tailleMax ; ligne>0; ligne--){
			
			for (int index=0; index < barreCor.size(); index++){
				for (int k=0;k<1;k++){
					
					if (barreCor.at(index)>=ligne){
						cout<<"*";
					}
					else{
						cout<<" ";
					}
				}
			}
			cout<<endl;
		}
	}
	
	else{
		cout<<"pas encore disponible"<<endl;
	}
	
}

