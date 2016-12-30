#ifndef TURMA_H_
#define TURMA_H_
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/**
 * Class turma que, como o nome indica, faz uma turma
 * de varios alunos e varias cadeiras.
 * @param turmaID - id da turma no formato [ano]MIEIC[numero da turma]
 * @param vagas - vagas da turma, valor por defeito e' 20
 * @param alunosID - ID de todos os alunos nesta turma
 */
class Turma {
	string turmaID;
	string ucID;
	int vagas;
	vector<int> alunosID;
public:
	Turma(string turmaID, string ucID, int v);

	const vector<int>& getAlunosId() const;
	int getVagas() const;
	void setVagas(int vagas);

    bool operator < (const Turma &t1) const;
    bool operator == (const Turma &t1) const;

	void alocarAluno(int alunoID);

	void saveTurma(ofstream *output);
};

#endif
