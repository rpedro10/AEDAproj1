#ifndef TURMA_H_
#define TURMA_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "uc.h"
#include "aluno.h"

using namespace std;

/**
 * Class turma que, como o nome indica, faz uma turma
 * de varios alunos e varias cadeiras.
 * @param turmaID - id da turma no formato [ano]MIEIC[numero da turma]
 * @param vagasCadeiras - vector que guarda as vagas na turma da cadeira correspondente
 */
class Turma {
	string turmaID;
	vector< pair<int,Uc*> > vagasCadeiras;
public:
	/**
	 * Simples construtor da Class Turma
	 */
	Turma(string turmaID, vector< pair<int,Uc*> > vagasCadeiras);

	/**
	 * getter simples
	 * @return turmaID
	 */
	string getTurmaID() const;

	/**
	 * getter simples
	 * @return vagasCadeiras
	 */
	vector< pair<int,Uc*> > getVagasCadeiras();

	/**
	 * Operator < overloading
	 * O termo de comparacao e' o numero de vagas
	 */
    bool operator < (const Turma &t1) const;

    /**
	 * Operator == overloading
	 * Compara os parametros turmaID e ucID
	 */
    bool operator == (const Turma &t1) const;

    /**
     * Introduz um aluno numa turma
     */
	void alocarAluno(int alunoID);

	/**
	 * Guarda os dados da turma numa ofstream
	 */
	void saveTurmas(ofstream *output);

	/**
	 * Imprime toda a informacao das ucs e das
	 * vagas de uma maneira curta
	 */
	void printInfo();

	/**
	 * Retorna verdadeiro se tem vagas nas cadeiras ucs
	 */
	bool cadeirasTemVagas(vector<Uc*> ucs);

	/**
	 * Inscreve aluno nas ucs introduzidas
	 */
	void inscreverAluno(vector<Uc*> ucs, Aluno* aluno);

	/**
	 * manda tirar os alunos desta turma nas respectivas UCs
	 */
	vector<Aluno*> disbandTurma();

	int vagasCadeira(Uc*);
	bool todasCvagas();
	vector<Uc*> cadeirasCvagas(vector<Uc*> ucs);
};

#endif
