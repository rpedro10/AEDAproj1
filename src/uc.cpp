#include "uc.h"

#include <iostream>

Uc::Uc(string nome, string sigla, int semestre, int ano, float creditos){
	this->nome = nome;
	this->sigla = sigla;
	this->semestre = semestre;
	this->ano = ano;
	this->creditos = creditos;
}

Optativa::Optativa(string nome, string sigla, int semestre, int ano, float cred,
		int vagas, string curso, string fac, string area) {
}

N_Optativa::N_Optativa(string nome, string sigla, int semestre, int ano,
		float cred) {
}

// contrutor das subclasses


vector<Uc>GetAllCadeiras(){
	ifstream in;
	string filename;
	vector<Uc>cadeiras;

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

		string str1 = line.substr(0, line.find(";") - 1); // numero
		int id = atoi(str1.c_str());
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
		
		cout << nome << "...." << sigla << "...." << year << "...." << sem << "...." << credit << endl;
	
		// construtor de nao optativa
		// cadeiras.push_back();
	}
	}
	in.close();

	return cadeiras;

}

const string& Optativa::getArea() const {
	return area;
}

void Optativa::setArea(const string& area) {
	this->area = area;
}

const string& Optativa::getCurso() const {
	return curso;
}

void Optativa::setCurso(const string& curso) {
	this->curso = curso;
}

const string& Optativa::getFaculdade() const {
	return faculdade;
}

void Optativa::setFaculdade(const string& faculdade) {
	this->faculdade = faculdade;
}

int Optativa::getVagas() const {
	return vagas;
}

void Optativa::setVagas(int vagas) {
	this->vagas = vagas;
}



int Uc::getAno() const {
	return ano;
}

void Uc::setAno(int ano) {
	this->ano = ano;
}

float Uc::getCreditos() const {
	return creditos;
}

void Uc::setCreditos(float creditos) {
	this->creditos = creditos;
}

const string& Uc::getNome() const {
	return nome;
}

void Uc::setNome(const string& nome) {
	this->nome = nome;
}

int Uc::getSemestre() const {
	return semestre;
}

void Uc::setSemestre(int semestre) {
	this->semestre = semestre;
}

const string& Uc::getSigla() const {
	return sigla;
}

void Uc::setSigla(const string& sigla) {
	this->sigla = sigla;
}
