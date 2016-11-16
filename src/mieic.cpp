#include "mieic.h"
#include <ctime>
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
			int i = 33;
					//inscreverNovoAluno();
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
	cout << "1. Procurar aluno a inscrever por nome" << endl;
	cout << "2. Procurar aluno a inscrever por numero" << endl;
	cout << "3. Ver todos os alunos" << endl;
	cout << "Introduza um numero para escolher a accao: ";
/**
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
*/
	return 0;

}


int Mieic::getAluno_byNome(string s ){
	for(unsigned int i=0;i<alunos.size();i++){
		if(alunos[i]->getNome()==s)
			return i;

	}
	return -1;
}

int Mieic::getAluno_byNumero(int n){
	for(unsigned int i=0;i<alunos.size();i++){
			if(alunos[i]->getNumero()==n)
				return i;

	}
	return -1;
}



void  Mieic::inscreverNovoAluno(){
	// TODO     -- testar ano
	//     -- colocar data automaticamente
	//     -- mostrar apenas as ucs em que se pode inscrever
	//     -- testar as vagas
	//     -- acrescentar o aluno nas cadeiras

	int numero,ano;
	string nome,email,estatuto,data;
	cout << "Inscrever novo aluno: "<<endl<<"Numero? ";
	cin>>numero;
	int index= getAluno_byNumero(numero);

	if(index==-1){

		cin.clear();
		cin.ignore(1000,'\n');

		cout<<"Nome? ";
		getline(cin,nome);
		cout<<"Ano? ";
		cin>>ano;

		/// colocar data automaticamente

		cout<<"email? ";
		 cin.clear();
			cin.ignore(1000,'\n');
		getline(cin,email);

		cout<<"estatuto? ";
		getline(cin,estatuto);

		data=getCurrentDate();

		Docente* tutor= assignTutor();

		// cout<<numero<<"---"<<nome<<"---"<<email<<"..."<<estatuto<<"---"<<ano<<endl;


		float cred=0;
		unsigned int number;

		for(unsigned int i=0;i<cadeiras.size();i++){
			cout<<i+1<<endl;cadeiras[i]->displayUC();
		}

			vector<string>datas;
			vector<Uc* > uc;
			vector< pair<string, Uc *> > cad;


			while(cred<75){
				cout<<"inserir numero da cadeira: (zero para terminar)";
				cin >> number;

				if(number==0)
					break;
				else
				{
				cout <<number<<endl;
				if (number <=cadeiras.size()){

					if(cadeiras[number-1]->getAno()<= ano){
						//if(1){
						//	cadeiras[number-1]->getVagas()>0
							cout<<cadeiras[number-1]->getSigla()<<endl;
							cred+=cadeiras[number-1]->getCreditos();
							datas.push_back(data);
							uc.push_back(cadeiras[number-1]);
						//}
					}
				}
			}

			}
			for(unsigned int j=0;j<uc.size();j++){
				cad.push_back({datas[j],uc[j]});
			}


			Aluno* aluno = new Aluno(numero, nome, ano, email, estatuto, tutor, cad);
			aluno->displayAlunoInfo();
			alunos.push_back(aluno);
	}

	else
		cout<<"erro"<<endl;



	 // cout<<numero<<"---"<<nome<<"---"<<email<<"..."<<estatuto<<"---"<<ano<<endl;


}






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

Docente* Mieic::assignTutor(){

	int maior=99;
	Docente* tutor;
	for (unsigned int i=0;i<docentes.size();i++){
		if(docentes[i]->getQtt()<maior)
		{
			maior=docentes[i]->getQtt();
			tutor=docentes[i];
		}
	}

	return tutor;
}

string Mieic::getCurrentDate(){
	time_t rawtime;
		struct tm * timeinfo;
		char buffer[80];

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, 14, "%d/%m/%Y", timeinfo);
		string str(buffer);

		return str.c_str();
}
