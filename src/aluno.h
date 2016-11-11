#ifndef __aluno_h__
#define __aluno_h__
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "uc.h"

using namespace std;

class Aluno {
	int numero;
	int ano;
	string nome;
	string data;
	string estatuto;
	string email;
	string tutor;
	//const Docente* tutor;
	//vector<Uc *> cadeiras_inscrito;
	vector<string> idCadeiras;
public:
	Aluno(int num, string nome, int ano, string data, string email, string estatuto, string tutor, vector<string> idCadeiras); // falta o vetor de disciplinas e o tutor
	//~Aluno();
	int getAno() const;
	void setAno(int ano);
	const string& getData() const;
	void setData(const string& data);
	const string& getEmail() const;
	void setEmail(const string& email);
	const string& getEstatuto() const;
	void setEstatuto(const string& estatuto);
	const string& getNome() const;
	void setNome(const string& nome);
	int getNumero() const;
	void setNumero(int numero);
	//const Docente* getTutor() const;

	//const vector<Uc*>& getCadeirasInscrito() const;
	//void setCadeirasInscrito(const vector<Uc*>& cadeinewrasInscrito);

	void displayAluno();

	vector<string> getIDcadeiras();
	void setIDcadeiras(vector<string> idCadeiras);
	void inscreverCadeira(string cadeira);
};

#endif
