#include "mieic.h"
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include "sequentialSearch.h"
#include <algorithm>
#include <iterator>
#include <exception>
#include <stdexcept>

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
		cout << "Gravando..." << endl;
		SaveFiles();
		cout << "Adeus!" << endl;
		return 0;
		break;
	default:
		cout << "Introduza um numero valido." << endl;
		break;
	}

	return 1;
}


int Mieic::inscreverAluno(){
	string name;
	//cout <<name<<endl;
	cout << "Nome? ";
	cin.clear();
	cin.ignore(1000,'\n');

	// Ricardo Astro
	getline(cin,name);
	//cout <<name<<endl;
	//cin.clear();
	// cin.ignore(1000,'\n');

	try{
			int index= getAluno_byNome(name);
			if(index<0)
				throw name;
			else{
				//	cout<<"entrou no if"<<endl;
					int creditos=0;
					vector< pair<string, Uc *> > disciplinas =alunos[index]->getCadeirasInscrito();
					int ano= alunos[index]->getAno();
					//cout<<ano<<endl;
					string data= getCurrentDate();
					//cout<<data<<endl;

						for(unsigned int i=0;i<disciplinas.size();i++ ){
							creditos+= disciplinas[i].second->getCreditos();

						}
						//cout<<creditos<<endl;
						//cout<<cadeiras.size()<<endl;

						vector<Uc*> ucsPossiveis;
						for(unsigned int i=0;i<cadeiras.size();i++){
							if(cadeiras[i]->getAno() <= ano && !alunos[index]->estaInscrito(cadeiras[i])){
								ucsPossiveis.push_back(cadeiras[i]);
							}
						}

						for(unsigned int i=0; i<ucsPossiveis.size(); i++){
							cout << i+1 << endl;
							ucsPossiveis[i]->display_incomplete();
						}

						int aux = ucsPossiveis.size();

						while(creditos < MAX_CREDITOS && aux != 0){

							unsigned int number;
							cout<<"inserir numero da cadeira: (zero para terminar)";
							cin >> number;

							if(number==0)
								break;
							else {
								//cout <<number<<endl;
								if (number <= ucsPossiveis.size() && ucsPossiveis[number-1] != NULL){

									if(ucsPossiveis[number-1]->getAno() <= ano){
										if(ucsPossiveis [number-1]->getVagas()>0 || ucsPossiveis [number-1]->getVagas()==-1){
											cout<<ucsPossiveis[number-1]->getSigla()<<endl;
											creditos+=ucsPossiveis[number-1]->getCreditos();
											int new_vagas=ucsPossiveis[number-1]->getVagas();
											new_vagas--;
											ucsPossiveis[number-1]->setVagas(new_vagas);
											ucsPossiveis[number-1]->addAluno(alunos[index]);

											disciplinas.push_back({data,ucsPossiveis[number-1]});

											ucsPossiveis[number-1] = NULL;
											--aux;

											//		datas.push_back(data);
											//	uc.push_back(cadeiras[number-1]);

										} else if(ucsPossiveis[number-1]->getVagas()==0) {

											cout<<"VAGAS INSUFICIENTES"<<endl;
											for(unsigned int j=0;j<cadeiras.size();j++){

												if( ucsPossiveis[number-1]->getArea()==cadeiras[j]->getArea()&&
														ucsPossiveis[number-1]->getSigla()!=cadeiras[j]->getSigla())
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
					/*
					for(unsigned int j = 0; j<disciplinas.size(); j++){
						disciplinas[j].second->addAluno(alunos[index]);
					}*/

				}
	}
	catch(string & x){
			cout<<"nome de aluno nao existe: "<<name<<endl;
			return 0;

		}

	char c;
	cout << "Insira qualquer coisa para continuar";
	cin >> c;

	return 1;



}



int Mieic::getAluno_byNome(const string &s ){

		Aluno* aluno = new Aluno();
		aluno->setNome(s);
		//cout<<s<<endl;
		int p = sequentialSearch(alunos, aluno);
		//cout<<p;
		return p;

/**
	for(unsigned int i=0;i<alunos.size();i++){
		if(alunos[i]->getNome()==s)
			return i;

	}
	return -1;
	*/
}

int Mieic::getAluno_byNumero(int n){
	for(unsigned int i=0;i<alunos.size();i++){
			if(alunos[i]->getNumero()==n)
				return i;

	}
	return -1;
}



int Mieic::inscreverNovoAluno(){

	int numero,ano;
	string nome,email,estatuto,data;
	cout << "Inscrever novo aluno: "<<endl<<"Numero? ";
	cin >> numero;

	try{
		int index= getAluno_byNumero(numero);
		if(index>0)
			throw numero;
		else{

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


				Docente* tutor = assignTutor();

				// cout<<numero<<"---"<<nome<<"---"<<email<<"..."<<estatuto<<"---"<<ano<<endl;


				float cred=0;
				unsigned int number;

				vector<Uc*> ucsPossiveis;
				for(unsigned int i=0;i<cadeiras.size();i++){
					if(cadeiras[i]->getAno() <= ano){
						ucsPossiveis.push_back(cadeiras[i]);
					}
				}

				for(unsigned int i=0; i<ucsPossiveis.size(); i++){
					cout << i+1 << endl;
					ucsPossiveis[i]->display_incomplete();
				}

				int aux = ucsPossiveis.size();

				vector<Uc* > uc;
				vector< pair<string, Uc *> > cad;

				while(cred < MAX_CREDITOS && aux != 0){
					cout<<"inserir numero da cadeira: (zero para terminar)";
					cin >> number;

					if(number==0)
						break;
					else
					{
						//cout <<number<<endl;
						if (number <= ucsPossiveis.size()&& ucsPossiveis[number-1] != NULL){

							//cout<<"number:"<<number<<"   size:"<<cadeiras.size()<<"....";
							//cout<<cadeiras[number-1]->getVagas()<<endl;
							if(ucsPossiveis[number-1]->getAno()<= ano){
								//cout<<cadeiras[number-1]->getVagas()<<endl;
								if(ucsPossiveis [number-1]->getVagas()>0||ucsPossiveis [number-1]->getVagas()==-1){
									cout<<ucsPossiveis[number-1]->getSigla()<<endl;
									//cout<<cadeiras[number-1]->getVagas()<<endl;
									cred+=ucsPossiveis[number-1]->getCreditos();
									int new_vagas=ucsPossiveis[number-1]->getVagas();
									new_vagas--;
									ucsPossiveis[number-1]->setVagas(new_vagas);
									//cout<<cadeiras[number-1]->getVagas()<<endl;
									uc.push_back(ucsPossiveis[number-1]);
									ucsPossiveis[number-1] = NULL;
									--aux;
									/// acresc

								}
								else if(ucsPossiveis [number-1]->getVagas()==0)
								{

									cout<<"VAGAS INSUFICIENTES"<<endl;
									for(unsigned int j=0;j<cadeiras.size();j++){

										if( ucsPossiveis[number-1]->getArea()==cadeiras[j]->getArea()&&
												ucsPossiveis[number-1]->getSigla()!=cadeiras[j]->getSigla())
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

				data=getCurrentDate();
				for(unsigned int j=0;j<uc.size();j++){
					cad.push_back({data,uc[j]});
				}


				Aluno* aluno = new Aluno(numero, nome, ano, email, estatuto, tutor, cad);
				aluno->displayAlunoInfo();

				alunos.push_back(aluno);

				vector< pair<string, Uc *> > ucsAluno = aluno->getCadeirasInscrito();

				for(unsigned int j = 0; j<ucsAluno.size(); j++){
					ucsAluno[j].second->addAluno(aluno);
				}
			}



	}catch(int x){
		cout<<"nº de aluno ja existe: "<<numero<<endl;
		return 0;

	}

	char c;
	cout << "Insira qualquer coisa para continuar";
	cin >> c;

	return 1;


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
		consultarAluno();
		break;
	case 2:
		consultarAluno_byNumero();
		break;
	case 3:
		ConsultarAllAlunos();
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
	cout << "1. por sigla" << endl;
	cout << "2. Ver todas as Unidades Curriculares" << endl;
	cout << "3. Voltar ao menu anterior" << endl;
	cout << "Introduza um numero para escolher a accao: ";

	unsigned int a;
	cin >> a;

	switch(a){
	case 1:
		consultarCadeira();
		break;
	case 2:
		ConsultarAllUcs();
		break;
	case 3:
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
void Mieic::ConsultarAllUcs(){
	for(unsigned int i=0;i<cadeiras.size();i++){
		cadeiras[i]->displayUC();
	}
}

void Mieic::ConsultarAllAlunos(){
	for(unsigned int i=0;i<alunos.size();i++){
		alunos[i]->displayAluno();
	}
}

void Mieic::ConsultarAllDocentes(){
	for(unsigned int i=0;i<docentes.size();i++){
		docentes[i]->displayDocente();
	}
}

int Mieic::consultarAluno_byNumero(){

	cout<<"Nome? ";
	int numero;
	cin>>numero;

	try{
		int index=getAluno_byNumero(numero);
		if(index==-1)
			throw numero;
		else{
			alunos[index]->displayAlunoInfo();
		return 1;
		}


	}catch(int x){
		cout<<"Aluno Nao Existe! "<< numero<<endl;
		return 0;

	}


}

// funcao que imprime aluno. pode ser substituida por displayAluno()
int Mieic::consultarAluno(){
	cin.clear();
    cin.ignore(10000,'\n');
	cout<<"Nome? ";
	string name;
	getline(cin, name);

	try{
			int index=getAluno_byNome(name);
			if(index==-1)
				throw name;
			else{
				alunos[index]->displayAlunoInfo();
			return 1;
			}


		}catch(string & x){
			cout<<"Aluno Nao Existe! "<< name<<endl;
			return 0;

		}
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
	cin.clear();
    cin.ignore(10000,'\n');
	cout<<"Sigla da Uc? ";
	string sigla;
	getline(cin, sigla);

	try{
			int index=getUc_bySigla(sigla);
			if(index==-1)
				throw sigla;
			else{
				cadeiras[index]->displayUC();
			return 1;
			}


		}catch(int x){
			cout<<"Uc Nao Existe! "<< sigla<<endl;
			return 0;

		}
}

Docente* Mieic::assignTutor(){

	int maior=99;
	Docente* tutor;
	for (unsigned int i=0;i<docentes.size();i++){
		if(docentes[i]->getQtt()<maior)
		{
			maior=docentes[i]->getQtt();
			tutor=docentes[i];
			cout << "tutor" << tutor->getQtt() << endl;
			cout << "docente" << docentes[i]->getQtt() << endl;
		}
	}

	(*tutor).setQtt();

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

void Mieic::SaveFiles(){
	/** SAVING UC's **/
	ofstream output;
	output.open("ucs.txt", ios_base::trunc);
	for (unsigned int i = 0; i < cadeiras.size(); i++){
		cadeiras[i]->save(&output);
		if(i != cadeiras.size()-1){
			output << endl;
		}
	}
	output.close();

	/** SAVING DOCENTES **/
	output.clear();
	output.open("docentes.txt", ios_base::trunc);
	for (unsigned int i = 0; i < docentes.size(); i++){
		docentes[i]->save(&output);
		if(i != docentes.size()-1){
			output << endl;
		}
	}
	output.close();

	/** SAVING ALUNOS **/
	output.clear();
	output.open("aa.txt", ios_base::trunc);
	for (unsigned int i = 0; i < alunos.size(); i++){
		alunos[i]->save(&output);
		if(i != alunos.size()-1){
			output << endl;
		}
	}
	output.close();
}


