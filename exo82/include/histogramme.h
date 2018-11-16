class histogramme{

	int debut,fin interval;
	vector <int> barre;
	void set_values(float,float,int);
	void fill(double);
	void print();
	void destroy();

}
void histogramme::set_values(float a ,float b,int x){

	for(int i = 0 ; i<x;i++){
		barre.push_back(0);
	}
	fin = b;
	debut=a;
	interval=xx;
}
void fill(double x){

	int k = (x-debut)* interval/(debut-fin)
	barre.at(k)++;

}
void print(){

	if(interval <50){
		int largeur = 50/interval;
		cout <<"Echelle de largeur : "<<largeur<<"x"<<endl;
		int tailleMax=0;
		for(int i = 0; i<interval; i++){
			if (barre.at(i)>tailleMax){
				tailleMax = barre.at(i);
			}		
		}
		cout<<"Echelle de hauteur : "<<tailleMax/50<<"x"<<endl;
		vector<int>barreCor;
		for (int i=0; i<barre.size();i++){
			barreCor.push_back(barre.at(i)*tailleMax/50);
		}	
	}
	
	else{

	}
	
}
