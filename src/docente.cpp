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


