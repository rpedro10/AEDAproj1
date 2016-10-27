#include "aluno.h"

Aluno::Aluno(int num, string nome, int ano, string data, string email, string estatuto){

	// 1 ; Rui Pereira ; 1/3/2008 ; 10.2

	this->numero = num;  // coloca o nº
	this->nome = nome;                               // nome colocado
	this->ano = ano;
	this->data = data;
	this->email = email;
	this->estatuto = estatuto;

}

vector<Aluno>GetAllAlunos(){
	ifstream in;
	string filename;
	vector<Aluno>alunos;

	cout << "nome do ficheiro de clientes? ";			//ficheiro de clientes
	cin >> filename;
	filename += ".txt";

	in.open(filename);

	while (in.fail()){							// testa se abriu o ficheiro
		cerr << "Input file opening failed.\n";
		cout << "nome do ficheiro de clientes? ";
		cin >> filename;
		filename += ".txt";
		in.open(filename);
	}

	string line;
	//getline(in, line);
	while (getline(in, line)){
		
		cout << line << endl;

		string str1 = line.substr(0, line.find(";") - 1); // numero
		int id = atoi(str1.c_str());
		line = line.substr(line.find(";") + 2, string::npos);

		cout << id << endl;
		
		string str2 = line.substr(0, line.find(";") - 1);  // nome

		line = line.substr(line.find(";") + 2, string::npos);

		cout << str2 << endl;

		
		string str3 = line.substr(0, line.find(";") - 1);  
		int year = atoi(str3.c_str());//ano  int

		line = line.substr(line.find(";") + 2, string::npos);
		
		string str4 = line.substr(0, line.find(";") - 1);          //data

		cout << year << endl << str4 << endl << "-----------------------------" << endl;

		//////////////////////////////////////////

		//string email
		//string estatuto
		//tutor
		//cadeiras

		if (!in.eof()){
		//	Aluno novo_aluno();
		//	alunos.push_back(novo_aluno);
		}
	}
	in.close();

	return alunos;

}