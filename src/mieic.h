#ifndef __mieic_h__
#define __mieic_h__
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_set>

#include "sequentialSearch.h"
#include <algorithm>
#include <iterator>
#include <exception>
#include <stdexcept>



#include "aluno.h"
#include "uc.h"
#include "docente.h"
#include "turma.h"

#define MAX_CREDITOS 75
#define ANO1 1
#define ANO5 5



struct eqalunos {
	bool operator() (const Aluno &c1, const Aluno &c2) const {
		return c1.getNumero() == c2.getNumero();
	}
};

struct halunos {
	int operator() (const Aluno &c1) const {
		int v = 0;
		for (unsigned int i = 0; i < c1.getNome().size(); i++)
			v = 37 * v + c1.getNome()[i];
		return v;
	}
};

typedef tr1::unordered_set<Aluno, halunos, eqalunos> tabHInativos;

using namespace std;

class Mieic{

	tabHInativos alunos_inativos;


	bool canTurmas;
	vector<Uc*> cadeiras;
	vector<Docente*> docentes;
	vector<Aluno*> alunos;


	vector<Turma*> turmas;
	priority_queue<Turma> turmasAno1;
	priority_queue<Turma> turmasAno2;
	priority_queue<Turma> turmasAno3;
	priority_queue<Turma> turmasAno4;
	priority_queue<Turma> turmasAno5;
	vector<Aluno*> alunosSemTurma; //alunos sem turmas a todas as cadeiras

public:
	Mieic(vector<Uc*> cadeiras, vector<Docente*> docentes, vector<Aluno*> alunos);
	int runProgram();

	////////////////////////////////////////////////

	void display_alunos_inativos();
	void addAluno_inativo();
	void deleteAluno_inativo(); // atualizar morada e contactos
	void deleteAluno(int num);

///////////////////////////////////////////
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


	void turmasMenu();
	void initTurmas(int semestre);
	vector<Turma> procurarTurmaPaluno(priority_queue<Turma> trms, vector<Uc*> ucs, Aluno* aluno);
	void novaTurma();
	int alunoTemTurma(Aluno* aluno);
	string getNameForTurma(int ano);
	void shuffleTurmas();

	vector<Turma> elaborateProcurarTurmas(priority_queue<Turma> trms, vector<Uc*> ucs, Aluno* aluno);
	void apagarTurma();
};

#endif
