#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "docente.h"

#define MAX_CREDITOS 75

class Mieic{
	vector<Uc> cadeiras;
	vector<Docente> docentes;
	vector<Aluno> alunos;

public:
	Mieic(vector<Uc> cadeiras, vector<Docente> docentes, vector<Aluno> alunos);
	~Mieic();
	int inscreverAluno();
	int novoAluno();
	int buscarAluno(int i, unsigned int type);
	int buscarAluno(string s, unsigned int type);
	int buscarCadeira(string s, unsigned int type);
	int consultarAluno(int id);
	int consultarInscritosCadeira(string s);
};
/*
	vector<Aluno> GetAllAlunos();
	vector<Uc>GetAllCadeiras();
*/
