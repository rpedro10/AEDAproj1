#ifndef __docente_h__
#define __docente_h__
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include "reuniao.h"

using namespace std;

class Aluno;

class Docente {
	int codigo;
	string nome;
	int qtt;
	set<Reuniao> reunioes;
	vector<Aluno*> alunos;

public:
	Docente(int cod, string nome, int qtt);
	int getCodigo() const;
	const string& getNome() const;
	void setNome(const string& nome);
	void displayDocente();
	int getQtt() const;
	void setQtt();
	vector<Aluno*> getAlunos();
	void addAluno(Aluno* aluno);
	void save(ofstream* output);

	void newReuniao();
	vector<Reuniao*> findReuniaoData(vector<int> data);
	vector<Reuniao*> findReuniaoID(int id);
	void cancelReuniao();
	void changeTerms(Reuniao* reuniao, string agenda, string descricao);
	vector<Reuniao*> getReunioes(vector<int> fromDate, vector<int> toDate);

	void menu();
};

vector<Docente*> initDocentes();

#endif
