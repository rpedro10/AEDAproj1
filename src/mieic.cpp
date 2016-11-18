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
			int i =33;
					//inscreverAluno();
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


void Mieic::inscreverAluno(){

		string name;
		cout <<name<<endl;
		cout << "Nome? ";

		// Ricardo Astro
		getline(cin,name);
		cout <<name<<endl;
		//cin.clear();
		// cin.ignore(1000,'\n');

		int index= getAluno_byNome(name);
		//cout<<"Index:::"<<index<<endl;


		if(index!=-1){
		//	cout<<"entrou no if"<<endl;
			int creditos=0;
			vector< pair<string, Uc *> > disciplinas =alunos[index]->getCadeirasInscrito();
			int ano= alunos[index]->getAno();
			cout<<ano<<endl;
			string data= getCurrentDate();
			cout<<data<<endl;

				for(unsigned int i=0;i<disciplinas.size();i++ ){
					creditos+= disciplinas[i].second->getCreditos();

				}
				cout<<creditos<<endl;
				cout<<cadeiras.size()<<endl;
				for(unsigned int i=0;i<cadeiras.size();i++){
							cout<<i+1<<endl;cadeiras[i]->display_incomplete();
						}
							int number;
							while(creditos<75){
							//	cout<<"entrou no while"<<endl;

								int number;
								cout<<"inserir numero da cadeira: (zero para terminar)";
								cin >> number;

								if(number==0)
									break;
								else
								{
								//cout <<number<<endl;
								if (number <=cadeiras.size()){

									if(cadeiras[number-1]->getAno()<= ano){
										if(cadeiras [number-1]->getVagas()>0 || cadeiras [number-1]->getVagas()==-1){
											cout<<cadeiras[number-1]->getSigla()<<endl;
											creditos+=cadeiras[number-1]->getCreditos();
											int new_vagas=cadeiras[number-1]->getVagas();
											new_vagas--;
											cadeiras[number-1]->setVagas(new_vagas);


											disciplinas.push_back({data,cadeiras[number-1]});

											//		datas.push_back(data);
											//	uc.push_back(cadeiras[number-1]);

										}
										else if(cadeiras [number-1]->getVagas()==0)
										{

											cout<<"VAGAS INSUFICIENTES"<<endl;
											for(unsigned int j=0;j<cadeiras.size();j++){

												if( cadeiras[number-1]->getArea()==cadeiras[j]->getArea()&&
														cadeiras[number-1]->getSigla()!=cadeiras[j]->getSigla())
												{
													cout<<"Recomenda-se:"<<endl;
													cout<<cadeiras[j]->getFaculdade()<<endl;
													cadeiras[j]->displayUC();
												//	 cout<< "Faculdade:: "<<cadeiras[j]->getFaculdade()<<endl;
												}
											}
										}

									}
								}
							}
							}

							alunos[index]->setCadeirasInscrito(disciplinas);

							alunos[index]->displayAlunoInfo();

							for(unsigned int j = 0; j<disciplinas.size(); j++){
															disciplinas[j].second->addAluno(alunos[index]);
														}

		}
		else
			cout<<"Aluno nao existe";



/**
	cout << "Inscrever aluno: " << endl;
	cout << "1. Procurar aluno a inscrever por nome" << endl;
	cout << "2. Procurar aluno a inscrever por numero" << endl;
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

		while(ano<=0){
			cout<<"Ano? ";
			cin>>ano;
		}

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
			cout<<i+1<<endl;cadeiras[i]->display_incomplete();
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
				//cout <<number<<endl;
				if (number <=cadeiras.size()){

					//cout<<"number:"<<number<<"   size:"<<cadeiras.size()<<"....";
					//cout<<cadeiras[number-1]->getVagas()<<endl;
					if(cadeiras[number-1]->getAno()<= ano){
						//cout<<cadeiras[number-1]->getVagas()<<endl;
						if(cadeiras [number-1]->getVagas()>0||cadeiras [number-1]->getVagas()==-1){
							cout<<cadeiras[number-1]->getSigla()<<endl;
							//cout<<cadeiras[number-1]->getVagas()<<endl;
							cred+=cadeiras[number-1]->getCreditos();
							int new_vagas=cadeiras[number-1]->getVagas();
							new_vagas--;
							cadeiras[number-1]->setVagas(new_vagas);
							//cout<<cadeiras[number-1]->getVagas()<<endl;
							datas.push_back(data);
							uc.push_back(cadeiras[number-1]);

							/// acresc

						}
						else if(cadeiras [number-1]->getVagas()==0)
						{

							cout<<"VAGAS INSUFICIENTES"<<endl;
							for(unsigned int j=0;j<cadeiras.size();j++){

								if( cadeiras[number-1]->getArea()==cadeiras[j]->getArea()&&
										cadeiras[number-1]->getSigla()!=cadeiras[j]->getSigla())
								{
									cout<<"Recomenda-se:"<<endl;
									cout<<cadeiras[j]->getFaculdade()<<endl;
									cadeiras[j]->displayUC();
								//	 cout<< "Faculdade:: "<<cadeiras[j]->getFaculdade()<<endl;
								}
							}
						}
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

			vector< pair<string, Uc *> > ucsAluno = aluno->getCadeirasInscrito();

							for(unsigned int j = 0; j<ucsAluno.size(); j++){
								ucsAluno[j].second->addAluno(aluno);
							}
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

// funcao que imprime aluno. pode ser substituida por displayAluno()
int Mieic::consultarAluno(){
	cout<<"Nome? ";
	string name;
	getline(cin, name);

	int index=getAluno_byNome(name);

	if(index!=-1){
		alunos[index]->displayAlunoInfo();
	}
	else cout<<"Aluno Nao Existe!"<<endl;


	return 0;
}


int Mieic::getUc_bySigla(string s){
	for(unsigned int i=0;i<cadeiras.size();i++){
			if(cadeiras[i]->getSigla()==s)
				return i;

		}
		return -1;

}

// funcao que imprime cadeira. pode ser substituida por displayCadeira()
int Mieic::consultarCadeira(){
	cout<<"Sigla da Uc? ";
		string sigla;
		getline(cin, sigla);

		int index= getUc_bySigla(sigla);

		if (index!=-1){
			cadeiras[index]->displayUC();

		}
		else
			cout<<"Uc nao existe"<<endl;


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
