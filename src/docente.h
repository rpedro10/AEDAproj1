#ifndef __docente_h__
#define __docente_h__
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


class Docente {
	int codigo;
	string nome;
	int qtt;
	//	vector<Aluno> inscritos;
	
public:
	Docente(int cod, string nome, int qtt);
	int getCodigo() const;
	const string& getNome() const;
	void setNome(const string& nome);
	void displayDocente();
	int getQtt() const;
	void setQtt();
};


vector<Docente*> initDocentes();

#endif
