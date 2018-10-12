#include <iostream>
#include <vector>
#include "../include/fonction.h"

void affichage(int* u, int* v,int dim){
	for (int i=0; i<dim;i++){
		cout <<u[i] <<" ";
	}
	cout <<endl;
	for (int i=0; i<dim;i++){
		cout <<v[i] <<" ";
	}

}
vector <int> addition(int* u, int* v,int dim){
	vector <int> add;
	for (int i=0; i<dim;i++){
		add.push_back(u[i]+v[i]);
	}
	return add;

}
vector <int> produitVectoriel(int*u, int*v){
	vector <int> produit;
	produit.push_back(u[2]*v[3]);
	produit.push_back((-1)*u[1]*v[3]);
	produit.push_back(u[1]*v[2]);
	return produit ;

}
