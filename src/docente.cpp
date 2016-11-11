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


