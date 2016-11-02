#include "docente.h"


int Docente::getCodigo() const {
	return codigo;
}

void Docente::setCodigo(int codigo) {
	this->codigo = codigo;
}

const string& Docente::getNome() const {
	return nome;
}

void Docente::setNome(const string& nome) {
	this->nome = nome;
}

Docente::Docente(int cod, string nome){

	this->codigo = cod;
	this->nome = nome;
}


vector<Uc>GetAllDocentes(){
	ifstream in;
	string filename;
	vector<Uc>docentes;

	cout << "nome do ficheiro ? ";			//ficheiro de alunos
	cin >> filename;
	filename += ".txt";

	in.open(filename);

	while (in.fail()){							// testa se abriu o ficheiro
		cerr << "Input file opening failed.\n";
		cout << "nome do ficheiro de alunos? ";
		cin >> filename;
		filename += ".txt";
		in.open(filename);
	}

	string line;

	while (getline(in, line)){

		string str1 = line.substr(0, line.find(";") - 1); // codigo
		int cod = atoi(str1.c_str());
		line = line.substr(line.find(";") + 2, string::npos);


		Docente novo_docente= Docente(cod,line);
		docentes.push_back(novo_docente);


	}
	in.close();

	return docentes;

}


