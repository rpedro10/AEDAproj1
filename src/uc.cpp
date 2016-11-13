#include "uc.h"
#include "aluno.h"

Uc::Uc(string nome, string sigla, int semestre, int ano, float creditos){
	this->nome = nome;
	this->sigla = sigla;
	this->semestre = semestre;
	this->ano = ano;
	this->creditos = creditos;
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

vector<Aluno*> Uc::getAlunos() const{
	return this->alunos;
}

void Uc::setAlunos(vector<Aluno*> alunos){
	this->alunos = alunos;
}

/**
 * UC Optativa
 */
Optativa::Optativa(string nome, string sigla, int semestre, int ano, float cred, int vagas, string curso, string fac, string area) :
	Uc(nome, sigla, semestre, ano, creditos){
	this->area = area;
	this->vagas = vagas;
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

void Optativa::displayUC(){
	cout << "Unidade Curricular : " << this->nome << endl;
	cout << "Sigla: " << this->sigla << endl;
	cout << "Ano Curricular: " << this->ano << endl;
	cout << "Semestre : " << this->semestre << endl;
	cout << "Creditos: " << this->creditos << endl;
	cout << "Alunos a frequentar: " << endl;

	for(unsigned int i = 0; i<this->alunos.size(); i++){
		cout << "	" << this->alunos[i]->getNumero() << "	" << this->alunos[i]->getNome() << endl;
	}

	cout << "Vagas: " << this->vagas << endl;

	cout << "==============================" << endl;
}

int Optativa::addAluno(Aluno* aluno){
	if(this->getVagas() < 1){
		this->alunos.push_back(aluno);
		return 1;
	} else {
		printf("Nao existem vagas suficientes\n");

		//TODO codigo que procura cadeiras da mesma area e sugere ao aluno

		return 0;
	}

	return -1;
}

/**
 * UC Nao Optativa
 */
N_Optativa::N_Optativa(string nome, string sigla, int semestre, int ano, float cred) :
	Uc(nome, sigla, semestre, ano, creditos){
}

void N_Optativa::displayUC(){
	cout << "Unidade Curricular : " << this->nome << endl;
	cout << "Sigla: " << this->sigla << endl;
	cout << "Ano Curricular: " << this->ano << endl;
	cout << "Semestre : " << this->semestre << endl;
	cout << "Creditos: " << this->creditos << endl;
	cout << "Alunos a frequentar: " << endl;

	for(unsigned int i = 0; i<this->alunos.size(); i++){
		cout << "	" << this->alunos[i]->getNumero() << "	" << this->alunos[i]->getNome() << endl;
	}

	cout << "==============================" << endl;
}

int N_Optativa::addAluno(Aluno* aluno){
	this->alunos.push_back(aluno);
	return 0;
}

