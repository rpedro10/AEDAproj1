#include "uc.h"

Uc::Uc(string nome, string sigla, int semestre, int ano, float creditos){
	this->nome = nome;
	this->sigla = sigla;
	this->semestre = semestre;
	this->ano = ano;
	this->creditos = creditos;
}
/**
Optativa::Optativa(string nome, string sigla, int semestre, int ano, float cred,
		int vagas, string curso, string fac, string area) {
	this->area = area;

}
*/
/**
N_Optativa::N_Optativa(string nome, string sigla, int semestre, int ano,
		float cred) {
}
*/
// contrutor das subclasses

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
