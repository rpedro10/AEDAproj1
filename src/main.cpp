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
// todo  funcoes de visualizaçao de todos os alunos e todas as cadeiras
// TODO  TESTAR SE JA ESTA INSCRITO À CADEIRA, SE ESTIVER NAO DEIXA INSCREVER OUTRA VEZ
// TODO  CORRIGIR A FUNCAO DISPLAY_INCOMPLETE() ( NAO ESTA A MOSTRAR A FACULDADE NEM O CURSO)
// TODO  FUNCOES PARA ESCREVER PARA FICHEIRO (GUARDAR INFO)
// TODO  SEQUENTIAL SEARCH
// TODO  QUICK SORT
// TODO  OVERLOAD ??
// TODO  EXCEPÇOES


int loadDependencies(vector<Aluno*> alunos){
	for(unsigned int i = 0; i<alunos.size(); i++){
		vector< pair<string, Uc *> > ucsAluno = (*alunos[i]).getCadeirasInscrito();

		for(unsigned int j = 0; j<ucsAluno.size(); j++){
			ucsAluno[j].second->addAluno(alunos[i]);
		}
	}

	return 0;
}

int main() {
	cout << "Bem Vindo ao curso de Mestrado Integrado em Engenharia Informatica" << endl;


	vector<Docente*> docentes = initDocentes();
	vector<Uc*> ucs = initUCs();
	vector<Aluno*> alunos = initAlunos(docentes, ucs);
/**
	if(loadDependencies(alunos)<0){
		printf("Erro a carregar dependencias. Saindo...");
		return -1;
	}

*/
/**
	printf("-=-=-=-=-Alunos=-=-=-=-=-\n");
	for(unsigned int i = 0; i<alunos.size(); i++){
		(*alunos[i]).displayAlunoInfo();
	}

	printf("-=-=-=-=-Docentes=-=-=-=-\n");
	for(unsigned int i = 0; i<docentes.size(); i++){
		(*docentes[i]).displayDocente();
	}

	printf("-=-=-=-=-=-UCs-=-=-=-=-=-\n");
	for(unsigned int i = 0; i<ucs.size(); i++){
		(*ucs[i]).displayUC();
	}
*/

	Mieic mieic = Mieic(ucs, docentes, alunos);

	//mieic.inscreverNovoAluno();
	// mieic.inscreverAluno();
	//mieic.consultarAluno();
	mieic.consultarCadeira();
/**
	printf("-=-=-=-=-=-UCs-=-=-=-=-=-\n");
		for(unsigned int i = 0; i<ucs.size(); i++){
		(*ucs[i]).display_incomplete();
		}
*/




/*
	int running = 1;
	while(running){
		running = mieic.runProgram();
	}

	return 0;
*/

}
