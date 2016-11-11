#include "aluno.h"

Aluno::Aluno(int num, string nome, int ano, string data, string email, string estatuto, string tutor, vector<string> idCadeiras){
	this->numero = num;  				// coloca o n�
	this->nome = nome;					// nome colocado
	this->ano = ano;
	this->data = data;
	this->email = email;
	this->estatuto = estatuto;
	this->tutor = tutor;
	this->idCadeiras = idCadeiras;
}

int Aluno::getAno() const {
	return ano;
}

void Aluno::setAno(int ano) {
	this->ano = ano;
}

/*
const vector<Uc*>& Aluno::getCadeirasInscrito() const {
	return cadeiras_inscrito;
}

void Aluno::setCadeirasInscrito(const vector<Uc*>& cadeirasInscrito) {
	cadeiras_inscrito = cadeirasInscrito;
}
*/

const string& Aluno::getData() const {
	return data;
}

void Aluno::setData(const string& data) {
	this->data = data;
}

const string& Aluno::getEmail() const {
	return email;
}

void Aluno::setEmail(const string& email) {
	this->email = email;
}

const string& Aluno::getEstatuto() const {
	return estatuto;
}

void Aluno::setEstatuto(const string& estatuto) {
	this->estatuto = estatuto;
}

const string& Aluno::getNome() const {
	return nome;
}

void Aluno::setNome(const string& nome) {
	this->nome = nome;
}

int Aluno::getNumero() const {
	return numero;
}

void Aluno::setNumero(int numero) {
	this->numero = numero;
}

vector<string> Aluno::getIDcadeiras(){
	return this->idCadeiras;
}

void Aluno::setIDcadeiras(vector<string> idCadeiras){
	this->idCadeiras = idCadeiras;
}

void Aluno::inscreverCadeira(string cadeira){
	this->idCadeiras.push_back(cadeira);
}

void Aluno::displayAluno(){
	cout << "Nome : " << this->nome << endl;
	cout << "Numero de Estudante: " << this->numero << endl;
	cout << "Ano Curricular: " << this->ano << endl;
	cout << "Email: " << this->email << endl;
	cout << "Data de inscricao: " << this->data << endl;
	cout << "Estatuto: " << this->estatuto;
	cout << "Tutor: " << this->tutor << endl;
	cout << "Cadeiras que frequenta: " << endl;

	for(unsigned int i = 0; i<this->idCadeiras.size(); i++){
		cout << "	" << this->idCadeiras[i] << endl;
	}

	cout << "==============================" << endl;

}

	
