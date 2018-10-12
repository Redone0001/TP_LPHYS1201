#include <iostream>
#include <vector>
#include "include/fonction.h"

using namespace std;
void affichage(int* u, int* v);

int main(){
	//l'utilisateur rentre ses données
	
	int dim;
	cout << "quelle est la dimension de vos deux vecteurs ?" <<endl;
	cin >> dim;
	int u[dim];
	int v[dim];
	cout <<"vecteur 1" <<endl;
	for (int i=0; i<dim; i++){
		cout << "composante" << i;
		cin >> u[i];
	}
	cout <<"vecteur 2" <<endl;
	for (int i=0; i<dim; i++){
		cout << "composante" << i;
		cin >> v[i];
	}
	//on va afficher les oppérations
	affichage(u,v,dim);
	vector <int> add = addition(u,v,dim);
	cout <<"addition : ";
	for (auto x  : add){
		cout<<x<<",";
	}
	cout<<endl;
	if (dim==3){
		vector <int> produit = produitVectoriel(u,v);
		cout <<"Produit vectoriel : ";
		for (auto x  : produit){
			cout<<x<<",";
		}
		cout <<endl;
	}

return 0;
}
