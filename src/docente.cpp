#include "docente.h"

int Docente::getCodigo() const {
	return codigo;
}

const string& Docente::getNome() const {
	return nome;
}

void Docente::setNome(const string& nome) {
	this->nome = nome;
}

Docente::Docente(int cod, string nome, int qtt){
	this->codigo = cod;
	this->nome = nome;
	this->qtt = qtt;
}

void Docente::displayDocente(){
	cout << "Nome : " << this->nome << endl;
	cout << "Codigo: " << this->codigo << endl;
	cout << "Quantidade de alunos a tutorar: " << this->qtt << endl;
	cout << "==============================" << endl;
}

int Docente::getQtt() const {
	return qtt;
}

void Docente::setQtt() {
	this->qtt = qtt++;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

vector<Docente*> initDocentes() {

	ifstream in;
	string filename;
	vector<Docente*> docentes;

	filename = "docentes.txt";

	in.open(filename.c_str(),ifstream::in);

	//TODO por excepcao de nao conseguir abrir o ficheiro

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

		Docente *docente = new Docente(id, name, qtt);
		docentes.push_back(docente);
	}


	in.close();

	return docentes;
}

