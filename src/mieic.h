#ifndef __mieic_h__
#define __mieic_h__
#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "uc.h"
#include "docente.h"

using namespace std;

#define MAX_CREDITOS 75

class Mieic{
	vector<Uc*> cadeiras;
	vector<Docente*> docentes;
	vector<Aluno*> alunos;

public:
	Mieic(vector<Uc*> cadeiras, vector<Docente*> docentes, vector<Aluno*> alunos);

	int runProgram();

	int inscreverAluno();
	int inscreverNovoAluno();
	int buscarAluno();
	int buscarCadeira();
	int consultarAluno(int id);
	int consultarInscritosCadeira(string s);
};

#endif
