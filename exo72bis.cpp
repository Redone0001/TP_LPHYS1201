#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool saveCSV(string fName, vector <string> & date, vector <float> & amount, vector <string> & comment){
	ofstream fs (fName);
	if (! fs.is_open()) return 0;

	fs<<"\"Date\",\"Montant\",\"Commentaire\""<<endl;
	for (unsigned int i = 0; i<date.size(); i++)
		fs<<"\""<<date[i]<<"\","<<amount[i]<<",\""<<comment[i]<<"\""<<endl;
	fs.close();
return 1;
}
bool splitLine(string line, string & date, float & amount, string & comment){
	int firstCommaPos = line.find(",");
	if (firstCommaPos < 0) return 0;
	date = line.substr(1,firstCommaPos-2);
	int secondCommaPos = line.find(",",firstCommaPos+1);
	amount = stof(line.substr(firstCommaPos+1,secondCommaPos - firstCommaPos - 1));
	comment = line.substr(secondCommaPos+2,line.size()-secondCommaPos-3);

return 1;
}

bool readCSV(string fileName, vector <string> & date, vector <float> & amount, vector <string> & comment){
	ifstream fs (fileName);
	bool firstLine = false;
	while(!fs.eof()){
		string line = "";
		getline(fs,line);
    		if (!firstLine){
      			firstLine = true;
      			continue;
    		}
    
		string d;
		float a=0;
		string c;
		if (splitLine(line,d,a,c)){
			date.push_back(d);
			amount.push_back(a);
			comment.push_back(c);
		}
	}
	fs.close();
return 1;
}



int main(){
	vector <float> amount;
	vector <string> comment;
 	vector <string> date;
	cout <<"test";
	string fName = "../MyBudget.csv";
	readCSV(fName,date,amount,comment);
	saveCSV(fName+"_bak",date,amount,comment);  

	float MyPrecious = 0;
	for(auto x:amount){
		MyPrecious+=x;
	}

	cout<<"Nous avons : "<<MyPrecious<<". Ils essayent de nous le voler"<<endl;

	int nombreDelignesAMontrer = 3;

	if (nombreDelignesAMontrer<amount.size()){
		nombreDelignesAMontrer=amount.size();
	}
	for (int i = nombreDelignesAMontrer-amount.size();i<amount.size();i++){
		cout<<i<<": "<<date[i]<<" : "<<amount[i]<<" ( "<<comment[i]<<" )" <<endl;
	}
	cout<<"Entrez nouvelle transaction"<<endl;
	string input;
	cout<<"Format : \"Date\",montant,\"commentaire\""<<endl;
	getline(cin,input);
	string d,c;
	float a;
	if(splitLine(input,d,a,c)){
		amount.push_back(a);
		date.push_back(d);
		comment.push_back(c);
		cout<<"Merci"<<endl;
    		saveCSV(fName,date,amount,comment);
	}
	else{
		cout<<"Vous êtes un con ! Ecrivez correctement"<<endl;
	}
	return 0;
}






