//============================================================================
// Name        : trabalho1.cpp
// Author      : Rui Oliveira e Rui
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================
#include "mieic.h"
#include <iostream>

using namespace std;


vector<Aluno> initAlunos(vector <Docente> docentes){
	ifstream in;
	string filename;
	vector<Aluno> alunos;

	filename = "aa.txt";

	in.open(filename.c_str(),ifstream::in);

	/**
	while (in.fail()){									// testa se abriu o ficheiro
		cerr << "Input file opening failed.\n";
		cout << "nome do ficheiro de alunos? ";
		cin >> filename;
		filename += ".txt";
		//in.open("aa.txt");
	}
	*/

	string line;

	while (getline(in, line)){
		int id;
		string name;
		int year;
		string data;
		string email;
		string tutor;

		string IDstr = line.substr(0, line.find(";") - 1); 				// numero
		id = atoi(IDstr.c_str());
		line = line.substr(line.find(";") + 2, string::npos);

		name = line.substr(0, line.find(";") - 1); 						// nome
		line = line.substr(line.find(";") + 2, string::npos);

		string YEARstr = line.substr(0, line.find(";") - 1);			// ano
		year = atoi(YEARstr.c_str());
		line = line.substr(line.find(";") + 2, string::npos);

		data = line.substr(0, line.find(";") - 1);						// data
		line = line.substr(line.find(";") + 2, string::npos);

		email = line.substr(0, line.find(";") - 1); 					// email
		line = line.substr(line.find(";") + 2, string::npos);

		string estatuto = line.substr(0, line.find(";") - 1); 			// estatuto
		line = line.substr(line.find(";") + 2, string::npos);

		int tutorID;
		string tutorIDstr = line.substr(0, line.find(";") - 1); 		// tutor
		tutorID = atoi(YEARstr.c_str());
		for(unsigned int i = 0; i<docentes.size(); i++){
			if(docentes[i].getCodigo() == tutorID){
				tutor = docentes[i].getNome();
			}
		}
		line = line.substr(line.find(";") + 2, string::npos);

		vector<string> cadeiras;										// cadeiras
		//cout << line << endl;

		while (line.find(",") != string::npos){
			string uc = line.substr(0, line.find(","));

			cadeiras.push_back(uc);
			//cout << uc << endl;

			line = line.substr(line.find(",") + 2);
			//cout << line << endl;
		}

		cadeiras.push_back(line);

		Aluno aluno = Aluno(id, name, year, data, email, estatuto, tutor, cadeiras);
		alunos.push_back(aluno);

		/*
		cout << id << endl;
		cout << name << endl;
		cout << year << endl << data << endl;
		cout << email << endl << estatuto << endl;
		cout << tutor << endl;
		for (unsigned int i = 0; i < cadeiras.size(); i++){
			cout << cadeiras[i] << endl;
		}
		cout << "==============================" << endl;
		*/
	}
	in.close();

	return alunos;

}


vector<Uc> initUCs(){
	ifstream in;
	string filename;
	vector<Uc>cadeiras;

	/*
	cout << "nome do ficheiro ? ";			//ficheiro de alunos
	cin >> filename;
	filename += ".txt";
	*/

	in.open("ucs.txt");

	while (in.fail()){							// testa se abriu o ficheiro
		cerr << "Input file opening failed.\n";
		cout << "nome do ficheiro de alunos? ";
		cin >> filename;
		filename += ".txt";
		in.open("ucs.txt");
	}

	string line;

	while (getline(in, line)){

		string str1 = line.substr(0, line.find(";") - 1); // numero
		int id ;
		//id= atoi(str1.c_str());
		line = line.substr(line.find(";") + 2, string::npos);

		//cout << id << endl;

		if (id == 1){

			//no caso de ser optativa



		}
		else{

			string nome = line.substr(0, line.find(";") - 1);  // nome

			line = line.substr(line.find(";") + 2, string::npos);

			//cout << nome << endl;

			string sigla = line.substr(0, line.find(";") - 1);  // sigla



			line = line.substr(line.find(";") + 2, string::npos);

			string str4 = line.substr(0, line.find(";") - 1);
			 int year = atoi(str4.c_str());//ano  int



			line = line.substr(line.find(";") + 2, string::npos);

			string str5 = line.substr(0, line.find(";") - 1);
			int sem = atoi(str5.c_str());//semestre

			line = line.substr(line.find(";") + 2, string::npos);

			string str6 = line.substr(0, line.find(";") - 1);
			int credit = atoi(str6.c_str());//creditos

			//cout << nome << "...." << sigla << "...." << year << "...." << sem << "...." << credit << endl;

			// construtor de nao optativa
			// cadeiras.push_back();
		}
	}
	in.close();

	return cadeiras;

}

vector<Docente> initDocentes() {

	ifstream in;
	string filename;
	vector<Docente> docentes;

	filename = "docentes.txt";

	in.open(filename.c_str(),ifstream::in);

	/**
	while (in.fail()){							// testa se abriu o ficheiro
		cerr << "Input file opening failed.\n";
		cout << "nome do ficheiro de alunos? ";
		cin >> filename;
		filename += ".txt";
		//in.open("aa.txt");
	}
	 */

	string line;

	while (getline(in, line)){
		int id;
		string name;
		int qtt;

		string IDstr = line.substr(0, line.find(";") - 1); 				// numero
		id = atoi(IDstr.c_str());
		line = line.substr(line.find(";") + 2, string::npos);

		name = line.substr(0, line.find(";") - 1); 						// nome
		line = line.substr(line.find(";") + 2, string::npos);

		string qttstr = line.substr(0, line.find(";") - 1); 				// qtt
		qtt = atoi(qttstr.c_str());
		line = line.substr(line.find(";") + 2, string::npos);

		/*
		cout << id << endl;
		cout << name << endl;
		cout << qtt << endl;
		cout << "==============================" << endl;
		*/

		Docente docente = Docente(id, name, qtt);
		docentes.push_back(docente);
	}


	in.close();

	return docentes;
}

int main() {
	cout << "Bem Vindo ao curso de Mestrado Integrado em Engenharia Informatica" << endl;

	vector<Docente> docentes = initDocentes();
	vector<Aluno> alunos = initAlunos(docentes);
	vector<Uc> ucs = initUCs();

	for(unsigned int i = 0; i<alunos.size(); i++){
		alunos[i].displayAluno();
	}
	//Mieic mieic = Mieic(ucs, alunos, docentes);


	
	return 0;
}
