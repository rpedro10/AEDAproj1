//============================================================================
// Name        : trabalho1.cpp
// Author      : Rui Oliveira e Rui Araujo
// Version     : 0.3
// Copyright   : This is a University project, use at your own risk.
// Description :
//============================================================================
#include "mieic.h"
#include <iostream>

using namespace std;

/**
 * atribui dependencias entre alunos e datas a que se inscreveu em ucs
 * e entre docentes e alunos
 */
int loadDependencies(vector<Aluno*> alunos, vector<Docente*> docentes){
	for(unsigned int i = 0; i<alunos.size(); i++){
		vector< pair<string, Uc *> > ucsAluno = (*alunos[i]).getCadeirasInscrito();

		for(unsigned int j = 0; j<ucsAluno.size(); j++){
			ucsAluno[j].second->addAluno(alunos[i]);
		}

		for(unsigned int k=0; k<docentes.size(); k++){
			if(docentes[k]->getCodigo() == alunos[i]->getTutor()->getCodigo()){
				docentes[k]->addAluno(alunos[i]);
			}
		}
	}

	return 0;
}



int main() {
	cout << "Bem Vindo ao curso de Mestrado Integrado em Engenharia Informatica" << endl
		 <<"-------------------------------"<< endl;

	vector<Docente*> docentes = initDocentes();
	vector<Uc*> ucs = initUCs();
	vector<Aluno*> alunos = initAlunos(docentes, ucs);

	if(loadDependencies(alunos, docentes)<0){
		printf("Erro a carregar dependencias. Saindo...");
		return -1;
	}

	Mieic mieic = Mieic(ucs, docentes, alunos);

	int running = 1;
	while(running){
		running = mieic.runProgram();
	}
	return 0;

}
