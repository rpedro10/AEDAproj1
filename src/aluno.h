#ifndef __aluno_h__
#define __aluno_h__
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "uc.h"
#include "docente.h"



class Aluno {
	int numero;
	int ano;
	string nome;
	//string data;
	string estatuto;
	string email;
	const Docente* tutor;
	vector< pair<string, Uc *> > cadeiras_inscrito;
	//temporary variables
public:
	Aluno(int num, string nome, int ano, string email, string estatuto, Docente* tutor, vector< pair<string, Uc *> > cadeiras_inscrito); // falta o vetor de disciplinas e o tutor
	Aluno(int num, string nome, int ano, string email, string estatuto);
	//~Aluno();
	int getAno() const;
	void setAno(int ano);
	//const string& getData() const;
	//void setData(const string& data);
	const string& getEmail() const;
	void setEmail(const string& email);
	const string& getEstatuto() const;
	void setEstatuto(const string& estatuto);
	const string& getNome() const;
	void setNome(const string& nome);
	int getNumero() const;
	void setNumero(int numero);
	//const Docente* getTutor() const;

	vector< pair<string, Uc *> > getCadeirasInscrito() const;
	void setCadeirasInscrito(vector< pair<string, Uc *> > cadeirasInscrito);

	void displayAlunoInfo();
	void displayAluno();

	void inscreverCadeira(Uc *uc);

};
vector<Aluno*> initAlunos(vector <Docente*> docentes, vector<Uc*> ucs);

#endif
