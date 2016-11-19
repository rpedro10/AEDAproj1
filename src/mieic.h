#ifndef __mieic_h__
#define __mieic_h__
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>

#include "aluno.h"
#include "uc.h"
#include "docente.h"

#define MAX_CREDITOS 75

using namespace std;


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
	int consultarAluno();
	int consultarCadeira();
	int getAluno_byNumero(int n);
	int getAluno_byNome(const string &s);
	int getUc_bySigla(string s);
	Docente* assignTutor();
	string getCurrentDate();
	void ConsultarAllUcs();
	void ConsultarAllAlunos();
	void ConsultarAllDocentes();
	void SaveFiles();
	void handler();

	//void test_uc(Aluno* aluno);


};

#endif
