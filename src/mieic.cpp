#include "mieic.h"

#include <stdio.h>
#include <stdlib.h>

Mieic::Mieic(vector<Uc*> cadeiras, vector<Docente*> docentes, vector<Aluno*> alunos){
	this->cadeiras = cadeiras;
	this->docentes = docentes;
	this->alunos = alunos;
}

int Mieic::runProgram(){
	cout << "1. Inscrever aluno" << endl;
	cout << "2. Inscrever novo aluno" << endl;
	cout << "3. Procurar aluno" << endl;
	cout << "4. Procurar Unidade Curricular" << endl;
	cout << "5. Sair" << endl;
	cout << "Introduza um numero para escolher a accao: ";

	unsigned int a;
	cin >> a;

	switch(a){
	case 1:
		if(inscreverAluno()<0){
			printf("Erro a inscrever aluno.\n");
			return -1;
		}

		break;
	case 2:
		if(inscreverNovoAluno()<0){
			printf("Erro a inscrever um novo aluno.\n");
			return -1;
		}

		break;
	case 3:
		if(buscarAluno()<0){
			printf("Erro a inscrever aluno.\n");
			return -1;
		}

		break;
	case 4:
		if(buscarCadeira()<0){
			printf("Erro a inscrever aluno.\n");
			return -1;
		}

		break;
	case 5:
		break;
	default:
		cout << "Introduza um numero valido." << endl;
		break;
	}
	return 0;
}


int Mieic::inscreverAluno(){
	cout << "Inscrever aluno: ";
	return 0;
}

int Mieic::inscreverNovoAluno(){
	cout << "Inscrever novo aluno: ";
	return 0;
}

int Mieic::buscarAluno(){
	cout << "Procurar aluno: " << endl;
	cout << "1. por nome" << endl;
	cout << "2. por numero" << endl;
	cout << "3. Ver todos os alunos" << endl;
	cout << "Introduza um numero para escolher a accao: ";

	unsigned int a;
	cin >> a;

	switch(a){
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	default:
		cout << "Introduza um numero valido." << endl;
		break;
	}
	return 0;
}

int Mieic::buscarCadeira(){
	cout << "Procurar Unidade Curricular: " << endl;
	cout << "1. por nome" << endl;
	cout << "2. por sigla" << endl;
	cout << "3. Ver todas as Unidades Curriculares" << endl;
	cout << "Introduza um numero para escolher a accao: ";

	unsigned int a;
	cin >> a;

	switch(a){
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	default:
		cout << "Introduza um numero valido." << endl;
		break;
	}
	return 0;
}

int Mieic::consultarAluno(int id){
	return 0;
}

int Mieic::consultarInscritosCadeira(string s){
	return 0;
}
