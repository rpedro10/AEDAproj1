#ifndef __mieic_h__
#define __mieic_h__
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <functional>
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
	int consultarAluno_byNumero();
	//void test_uc(Aluno* aluno);

	static bool compAlunoAlf(const Aluno * aluno1, const Aluno * aluno2){
	 		if((*aluno1).getNome().compare((*aluno2).getNome()) < 0)
	 			return true;
	 		else return false;
	 	};

	 	static bool compAlunoNum(const Aluno * aluno1, const Aluno * aluno2){
	 		if((*aluno1).getNumero() < (*aluno2).getNumero())
	 			return true;
	 		else return false;
	 	};

	 	static bool compUCalf(const Uc * uc1, const Uc * uc2){
	 		if((*uc1).getNome().compare((*uc2).getNome()) < 0)
	 			return true;
	 		else return false;
	 	};

	 	static bool compUCano(const Uc * uc1, const Uc * uc2){
	 		if((*uc1).getAno() < (*uc2).getAno())
	 			return true;
	 		else if((*uc1).getAno() == (*uc2).getAno() && (*uc1).getSemestre() < (*uc2).getSemestre())
	 			return true;
	 		else
	 			return false;
	 	};


};

#endif
