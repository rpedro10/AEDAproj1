#ifndef __mieic_h__
#define __mieic_h__
#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "uc.h"
#include "docente.h"

using namespace std;


class Mieic{
	vector<Uc*> cadeiras;
	vector<Docente*> docentes;
	vector<Aluno*> alunos;

public:
	Mieic(vector<Uc*> cadeiras, vector<Docente*> docentes, vector<Aluno*> alunos);

	int runProgram();

	void inscreverAluno();
	void inscreverNovoAluno();
	int buscarAluno();
	int buscarCadeira();
	int consultarAluno(int id);
	int consultarInscritosCadeira(string s);
	int getAluno_byNumero(int n);
	int getAluno_byNome(string s);
	Docente* assignTutor();
	string getCurrentDate();


};

#endif
