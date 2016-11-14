#include "mieic.h"

#include <stdio.h>
#include <stdlib.h>

Mieic::Mieic(vector<Uc*> cadeiras, vector<Docente*> docentes, vector<Aluno*> alunos){
	this->cadeiras = cadeiras;
	this->docentes = docentes;
	this->alunos = alunos;
}

int Mieic::runProgram(){
	int running = 1;
	cout << "1. Inscrever aluno existente" << endl;
	cout << "2. Inscrever novo aluno" << endl;
	cout << "3. Procurar aluno" << endl;
	cout << "4. Procurar Unidade Curricular" << endl;
	cout << "5. Sair" << endl;
	cout << "Introduza um numero para escolher a accao: ";

	unsigned int a;
	cin >> a;

	switch(a){
	case 1:
		while(running) {
			int i = inscreverAluno();
			if(i<0){
				printf("Erro a inscrever aluno.\n");
				return -1;
			} else if(i == 1){
				break;
			}
		}
		break;
	case 2:
		while(running) {
			int i = inscreverNovoAluno();
			if(i<0){
				printf("Erro a inscrever novo aluno.\n");
				return -1;
			} else if(i == 1){
				break;
			}
		}

		break;
	case 3:
		while(running) {
			int i = buscarAluno();
			if(i<0){
				printf("Erro a procurar aluno.\n");
				return -1;
			} else if(i == 1){
				break;
			}
		}

		break;
	case 4:
		while(running) {
			int i = buscarCadeira();
			if(i<0){
				printf("Erro a procurar Unidade Curricular.\n");
				return -1;
			} else if(i == 1){
				break;
			}
		}

		break;
	case 5:
		return 0;
		break;
	default:
		cout << "Introduza um numero valido." << endl;
		break;
	}

	return 1;
}

//TODO funcao que inscreve aluno existente
int Mieic::inscreverAluno(){
	cout << "Inscrever aluno: " << endl;
	return 0;
}

//TODO funcao que cria um novo aluno e o inscreve
int Mieic::inscreverNovoAluno(){
	cout << "Inscrever novo aluno: ";
	return 0;
}

//TODO funçao que procura alunos
int Mieic::buscarAluno(){
	cout << "Procurar aluno: " << endl;
	cout << "1. por nome" << endl;
	cout << "2. por numero" << endl;
	cout << "3. Ver todos os alunos" << endl;
	cout << "4. Voltar ao menu anterior" << endl;
	cout << "Introduza um numero para escolher a accao: ";

	unsigned int a;
	cin >> a;

	switch(a){
	case 1:

		break;
	case 2:

		break;
	case 3:
		for(unsigned int i = 0; i<alunos.size(); i++){
			(*alunos[i]).displayAluno();
		}

		break;
	case 4:
		return 1;
		break;
	default:
		cout << "Introduza um numero valido." << endl;
		break;
	}

	char c;
	cout << "Insira qualquer coisa para continuar";
	cin >> c;

	return 0;
}

//TODO funcao que procura cadeiras
int Mieic::buscarCadeira(){
	cout << "Procurar Unidade Curricular: " << endl;
	cout << "1. por nome" << endl;
	cout << "2. por sigla" << endl;
	cout << "3. Ver todas as Unidades Curriculares" << endl;
	cout << "4. Voltar ao menu anterior" << endl;
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
	case 4:
		return 1;
		break;
	default:
		cout << "Introduza um numero valido." << endl;
		break;
	}

	char c;
	cout << "Insira qualquer coisa para continuar";
	cin >> c;

	return 0;
}

//TODO funcao que imprime aluno. pode ser substituida por displayAluno()
int Mieic::consultarAluno(int id){
	return 0;
}

//TODO funcao que imprime cadeira. pode ser substituida por displayCadeira()
int Mieic::consultarInscritosCadeira(string s){
	return 0;
}
