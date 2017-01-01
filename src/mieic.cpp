#include "mieic.h"
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include "sequentialSearch.h"
#include <algorithm>
#include <iterator>
#include <exception>
#include <stdexcept>

/**
 * construtor do MIEIC
 */
Mieic::Mieic(vector<Uc*> cadeiras, vector<Docente*> docentes, vector<Aluno*> alunos){
	this->cadeiras = cadeiras;
	this->docentes = docentes;
	this->alunos = alunos;
	this->canTurmas = true;
}
/**
 * funcao de ciclo do programa, navegacao entre menus
 */
int Mieic::runProgram(){
	int running = 1;
	cout << "1. Inscrever aluno existente" << endl;
	cout << "2. Inscrever novo aluno" << endl;
	cout << "3. Procurar aluno" << endl;
	cout << "4. Procurar Unidade Curricular" << endl;
	cout << "5. Mostrar todos os Docentes" << endl;
	cout << "6. Terminar ano curricular" << endl;
	cout << "7. Entrar como Docente" << endl;
	cout << "8. Inscricao nas Turmas" << endl;
	cout << "9. ? Tabela de dispersao ?" << endl;
	cout << "0. Sair" << endl;
	cout << "Introduza um numero para escolher a accao: ";

	unsigned int a;
	cin >> a;

	switch(a){
	case 0:
		cout << "Gravando..." << endl;
		SaveFiles();
		cout << "Adeus!" << endl;
		return 0;
		break;
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
		ConsultarAllDocentes();
		break;
	case 6:
		for(unsigned int i = 0; i < alunos.size(); i++){
			alunos[i]->terminarAno();
		}
		break;
	case 7:{
		int id;
		bool have = false;
		while(!have){
			cout << "Introduza o seu ID de Docente: (0 para voltar)";
			cin >> id;
			if(id == 0) break;

			for(unsigned int i=0; i<docentes.size(); i++){
				if(id == docentes[i]->getCodigo()){
					id = i;
					have = true;
				}
			}
			if(have) break;
			cout << "Docente nao existe. Tente outra vez.";
		}
		if(have){
			cout << "Bem-vindo " << docentes[id]->getNome() << "!" << endl;
			docentes[id]->menu();
		} else return 1;}
	case 8:
		turmasMenu();
	default:
		cout << "Introduza um numero valido." << endl;
		break;
	}

	return 1;
}

/**
 * inscreve aluno que ja existe no Mieic, dado o seu nome
 */
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
	//cin.ignore(1000,'\n');

	try{
		int index= getAluno_byNome(name);
		if(index<0)
			throw name;
		else{
			//cout<<"entrou no if"<<endl;
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
				if(cadeiras[i]->getAno() <= ano && !alunos[index]->estaInscrito(cadeiras[i]) && !alunos[index]->completou(cadeiras[i])){
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
			return -1;

		}
	sort(alunos.begin(), alunos.end(), compAlunoAlf);

	char c;
	cout << "Insira qualquer coisa para continuar";
	cin >> c;

	return 1;



}


/**
 * devolve a posicao do aluno com o nome dado no vetor de apontadores para alunos, devolve -1 se nao existir
 */
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
/**
 * devolve a posicao do aluno com o numero dado no vetor de apontadores para alunos, devolve -1 se nao existir
 *
 */
int Mieic::getAluno_byNumero(int n){
	for(unsigned int i=0;i<alunos.size();i++){
			if(alunos[i]->getNumero()==n)
				return i;

	}
	return -1;
}


/**
 * Cria um novo aluno no MIEIC  e inscreve o �s cadeiras desejadas
 */
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

			vector< pair<string, Uc *> > cadComp;
			if(ano != 1){
				for(unsigned int i = 0; i<cadeiras.size(); i++){
					if(cadeiras[i]->getAno() < ano){
						cadComp.push_back({"indisponivel",cadeiras[i]});
					}
				}
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
				if(cadeiras[i]->getAno() == ano){
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

			Aluno* aluno = new Aluno(numero, nome, ano, email, estatuto, tutor, cad, cadComp);
			aluno->displayAlunoInfo();

			alunos.push_back(aluno);
			tutor->addAluno(aluno);

			vector< pair<string, Uc *> > ucsAluno = aluno->getCadeirasInscrito();

			for(unsigned int j = 0; j<ucsAluno.size(); j++){
				ucsAluno[j].second->addAluno(aluno);
			}
		}

	}catch(int x){
		cout<<"n� de aluno ja existe: "<<numero<<endl;
		return -1;

	}

	sort(alunos.begin(), alunos.end(), compAlunoAlf);

	char c;
	cout << "Insira qualquer coisa para continuar";
	cin >> c;

	return 1;

	// cout<<numero<<"---"<<nome<<"---"<<email<<"..."<<estatuto<<"---"<<ano<<endl;


}




/**
 * Menu Pesquisa de alunos
 */
int Mieic::buscarAluno(){
	cout << "Procurar aluno: " << endl;
	cout << "1. por nome" << endl;
	cout << "2. por numero" << endl;
	cout << "3. Ver todos os alunos por ordem alfabetica" << endl;
	cout << "4. Ver todos os alunos por ordem numerica" << endl;
	cout << "5. Voltar ao menu anterior" << endl;
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
		sort(alunos.begin(), alunos.end(), compAlunoAlf);
		ConsultarAllAlunos();
		break;
	case 4:
		sort(alunos.begin(), alunos.end(), compAlunoNum);
		ConsultarAllAlunos();
		break;
	case 5:
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
/**
 * Menu de pesquisa de Ucs
 */
int Mieic::buscarCadeira(){
	cout << "Procurar Unidade Curricular: " << endl;
	cout << "1. por sigla" << endl;
	cout << "2. Ver todas as Unidades Curriculares por ordem alfabetica" << endl;
	cout << "3. Ver todas as Unidades Curriculares por ordem anual" << endl;
	cout << "4. Voltar ao menu anterior" << endl;
	cout << "Introduza um numero para escolher a accao: ";
	unsigned int a;
	cin >> a;

	switch(a){
	case 1:
		consultarCadeira();
		break;
	case 2:
		sort(cadeiras.begin(), cadeiras.end(), compUCalf);
		 ConsultarAllUcs();
		 break;
	case 3:
		sort(cadeiras.begin(), cadeiras.end(), compUCano);
		ConsultarAllUcs();
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

/**
 * display de todas as ucs do mieic
 */
void Mieic::ConsultarAllUcs(){
	for(unsigned int i=0;i<cadeiras.size();i++){
		cadeiras[i]->displayUC();
	}
}
/**
 * display de todos os alunos do mieic
 */
void Mieic::ConsultarAllAlunos(){
	for(unsigned int i=0;i<alunos.size();i++){
		alunos[i]->displayAluno();
	}
}
/**
 * dispay de todos os docentes do mieic
 */
void Mieic::ConsultarAllDocentes(){
	for(unsigned int i=0;i<docentes.size();i++){
		docentes[i]->displayDocente();
	}
}
/**
 * Mostra aluno dado o seu numero de aluno
 */
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

/**
 * Display de info de um aluno do mieic dado o seu nome
 */
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

/**
 * devolve a posicao no vetor de apontadores de ucs da uc com a sigla desejada, -1 se nao existir
 */
int Mieic::getUc_bySigla(string s){
	for(unsigned int i=0;i<cadeiras.size();i++){
		if(cadeiras[i]->getSigla()==s)
			return i;
	}
	return -1;

}



/**
 * funcao que imprime cadeira dada a sua sigla
 *
 */
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
/**
 * Atribui um tutor ao aluno
 */
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
/**
 * devolve a data atual em string para inscri�ao em uc
 */
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

/**
 * Funcao que apresenta o menu de accoes das turmas
 */
void Mieic::turmasMenu(){
	//TODO testar
	cout << "MENU TURMAS" << endl;
	while(true){
		cin.clear();
		cin.ignore(1000,'\n');
		if(turmas.empty() && this->canTurmas){
			cout << "A inscricao nas turmas ainda nao comecou." << endl;
			cout << "Dar inicio ao processo de inscricao(y/n)? ";
			char r;
			cin >> r;
			if(r == 'y'){
				cout << "Iniciar semestre 1 ou 2? ";
				int semestre;
				cin >> semestre;
				if(semestre == 1 || semestre == 2){
					try{
						initTurmas(semestre);
					} catch(const exception& ex){
						ex.what();
					}
				} else {
					cout << "Processo cancelado." << endl;
					return;
				}
			}
		} else if(this->canTurmas) {
			cout << "MENU TURMAS:" << endl;
			cout << "1. Alocar aluno numa turma" << endl;
			cout << "2. Criar nova turma" << endl;
			cout << "3. Eliminar turma existente" << endl;
			cout << "4. Visualizar turma" << endl;
			cout << "5. Terminar processo de inscricao" << endl;
			cout << "0. Voltar" << endl;
			cout << "Introduza um numero para escolher a accao: ";

			unsigned int a;
			cin >> a;

			switch(a){
			case 0:
				return;
				break;
			case 2:
				novaTurma();
				break;
			case 5:{
				char r;
				cout << "Terminar processo de inscricao (y/n)? ";
				cin >> r;
				if(r == 'y'){
					this->canTurmas = false;
					cout << "Processo de inscricao terminado." << endl;
					return;
				}
				break;}
			default:
				cout << "Introduza um numero valido." << endl;
				break;
			}

		} else {
			cout << "Processo de incricao ja' terminou." << endl;
			cout << "Apagar turmas para comecar novo semestre (y/n)?" << endl;
			char r;
			cin >> r;
			if(r == 'y'){
				this->canTurmas = true;
				while(!turmas.empty()){
					turmas.pop_back();
				}
				cout << "Turmas apagadas com sucesso." << endl;
				return;
				/*
				for(unsigned int i=0; i<cadeiras.size(); i++){
					while(!cadeiras[i]->getTurmas().empty()){
						cadeiras[i]->getTurmas().pop();
					}
				}*/
			}
		}
	}
}

/**
 * Cria uma nova turma com todas as cadeiras que pertencem ao mesmo ano
 * e semestre
 */
void Mieic::novaTurma(){/*
	cout << "Em que ano e semestre deseja criar uma turma nova?" << endl;
	cout << "Ano: ";
	int a;
	cin >> a;
	while(a<1 || a>5){
		cout << "Introduza um ano valido." << endl;
		cout << "Ano: ";
		cin >> a;
	}
	cout << "Semestre: ";
	int s;
	cin >> s;
	while(s!=1 && s!=2){
		cout << "Introduza um semestre valido." << endl;
		cout << "Semestre: ";
		cin >> s;
	}
	cout << "Quantas vagas deseja por na turma?" << endl;
	int v;
	cin >> v;

	for(unsigned int i=0; i<cadeiras.size(); i++){
		if(cadeiras[i]->getAno() == a && cadeiras[i]->getSemestre() == s)
			turmas.push_back(cadeiras[i]->novaTurma(v));
	}*/
}

/**
 * Struct auxiliar para criacao de turmas de cadeiras optativas
 * @param vPt - vagas por turma
 * @param nT - numero de turmas
 * @param uc - identificador da UC
 */
struct TurmasOpt{
	int vPt;
	int nT;
	string uc;
};

/**
 * Funcao que introduz o numero minimo de turmas para a quantidade de
 * alunos e vagas que existem, no sistema e inscreve-os automaticamente
 * numa turma do seu ano base.
 */
void Mieic::initTurmas(int semestre){
	for(int l=ANO1; l<=ANO5; l++){
		cout << "Ano " << l << endl;

		vector<Uc*> ucsOpt;
		vector<Uc*> ucsNopt;


		for(unsigned int i=0; i<cadeiras.size(); i++){
			//cout << "size " << cadeiras.size() <<  " cadeira " << cadeiras[i]->getSigla() << " i " << i << endl;
			if(cadeiras[i]->getCurso().compare("MIEIC") == 0 &&
					cadeiras[i]->getAno() == l &&
					cadeiras[i]->getSemestre() == semestre &&
					(cadeiras[i]->getAlunos().size()>0 || cadeiras[i]->getVagas()>0 || cadeiras[i]->getVagas() == -1) ){

				if(cadeiras[i]->getVagas() == -1)
					ucsNopt.push_back(cadeiras[i]);
				else if(cadeiras[i]->getVagas() > 0)
					ucsOpt.push_back(cadeiras[i]);

			}
		}

		cout << "ucsNopt " << ucsNopt.size() << " ucsOpt " << ucsOpt.size() << endl;

		/* Vagas e numero de turmas para as Nao Optativas */
		unsigned int nAlunos = 0, ind = 0;
		for(unsigned int i=0; i<ucsNopt.size(); i++){
			if(nAlunos < ucsNopt[i]->getAlunos().size()){
				nAlunos = ucsNopt[i]->getAlunos().size();
				ind = i;
			}
		}

		int maxVagas, nTurmasNopt;
		if(ucsNopt.size() != 0 && nAlunos !=0){
			while(true){
				int a;
				cout << "Das UC's nao optativas, a UC " << ucsNopt[ind]->getSigla() << " tem mais alunos ("
					<< ucsNopt[ind]->getAlunos().size() << ")." << endl;
				cout << "Quantos alunos deseja por turma? ";
				cin >> a;

				if(a > 0){
					nTurmasNopt = nAlunos/a;
					if(nAlunos%a != 0)
						nTurmasNopt += 1;

					cout << "Numero de turmas necessario: " << nTurmasNopt << endl;;
					cout << "Criar " << nTurmasNopt << " turmas (y/n)? ";
					char r;
					cin >> r;
					if(r == 'y'){
						maxVagas = a;
						break;
					}
				} else cout << "Introduza um numero valido." << endl;
			}
		} else if(ucsNopt.size() != 0 && nAlunos == 0){
			while(true){
				int a,b;
				cout << "Nenhuma UC nao optativa tem alunos, quantas vagas deseja por turma? ";
				cin >> a;
				cout << "Quantas turmas deseja? ";
				cin >> b;

				if(b > 0 && a > 0){
					cout << "Criar " << b << " turmas de " << a << " alunos (y/n)? ";
					char r;
					cin >> r;
					if(r == 'y'){
						maxVagas = a;
						nTurmasNopt = b;
						break;
					}
				} else {
					cout << "Introduza um numero valido." << endl;
				}
			}
		}

		vector< pair<int,Uc*> > vagasCadeiras;
		for(unsigned int i = 0; i<ucsNopt.size(); i++){
			vagasCadeiras.push_back({maxVagas,ucsNopt[i]});
		}

		/* Vagas e numero de turmas para as Optativas */
		vector<TurmasOpt> tOpts;
		for(unsigned int i = 0; i<ucsOpt.size(); i++){
			int nTurmas;
			while(true){
				int a;
				cout << "Das UC's optativas, a UC " << ucsOpt[i]->getSigla() << " tem "
						<< ucsOpt[i]->getVagas() << " vagas.";
				cout << "Quantos alunos deseja por turma? ";
				cin >> a;

				nTurmas = ucsOpt[i]->getVagas()/a;
				if(ucsOpt[i]->getVagas()%a != 0)
					nTurmas += 1;

				cout << "Numero de turmas necessario: " << nTurmas << endl;;
				cout << "Criar " << nTurmas << " turmas (y/n)? ";
				char r;
				cin >> r;
				if(r == 'y'){
					maxVagas = a;
					break;
				}
			}

			TurmasOpt tOpt;
			tOpt.vPt = maxVagas;
			tOpt.nT = nTurmas;
			tOpt.uc = ucsOpt[i]->getSigla();


			tOpts.push_back(tOpt);

			vagasCadeiras.push_back({maxVagas,ucsOpt[i]});
		}

		/* Criacao de turmas */
		int aux = nTurmasNopt;
		for(unsigned int i=0; i<tOpts.size(); i++){
			if(aux<tOpts[i].nT)
				aux = tOpts[i].nT;
		}

		Turma* turma;
		for(int i=0; i<aux; i++){
			stringstream ss;
			ss << l << "MIEIC" << i+1;
			string turmaID = ss.str();

			if(vagasCadeiras.size() > 0){
				turma = new Turma(turmaID,vagasCadeiras);
				this->turmas.push_back(turma);
				switch(l){
				case 1:
					this->turmasAno1.push(turma);
					break;
				case 2:
					this->turmasAno2.push(turma);
					break;
				case 3:
					this->turmasAno3.push(turma);
					break;
				case 4:
					this->turmasAno4.push(turma);
					break;
				case 5:
					this->turmasAno5.push(turma);
					break;
				default:
					cout << "Erro: Estado impossivel." << endl;
				    exit (EXIT_FAILURE);
					break;
				}
			}

			/* apagar do vector vagasCadeiras as cadeiras
			 * Nao Optativas que ja tem turmas suficientes*/
			if(nTurmasNopt > 0){
				nTurmasNopt--;
			} else if(nTurmasNopt == 0){
				int delta = 1;
				int in,fin;
				while(delta != 0){
					in = vagasCadeiras.size();
					for(unsigned int j=0; j<vagasCadeiras.size(); j++){
						if(vagasCadeiras[j].second->getVagas() == -1){
							vagasCadeiras.erase(vagasCadeiras.begin()+j);
							fin = vagasCadeiras.size();
							break;
						}
					}
					delta = in - fin;
				}
				nTurmasNopt = -1;
			}

			/* apagar do vector vagasCadeiras as cadeiras
			 * Optativas que ja tem turmas suficientes*/
			for(unsigned int j=0; j<tOpts.size(); j++){
				if(tOpts[j].nT > 0){
					tOpts[j].nT--;
				} else if(tOpts[j].nT == 0){
					for(unsigned int k=0; k<vagasCadeiras.size(); k++){
						if(vagasCadeiras[k].second->getSigla().compare(tOpts[j].uc) == 0){
							vagasCadeiras.erase(vagasCadeiras.begin()+k);
						}
					}
				}
			}
		}
		cout << "Criadas turmas para o Ano " << l << endl;
	}
/*
	//TODO assign alunos to turmas
	for(unsigned int i=0; i<alunos.size(); i++){
		vector<Uc*> ucs = alunos[i]->getUCsAnoBase();

		vector<Turma*> aux;
		switch(alunos[i]->getAno()){
		case 1:
			while(!this->turmasAno1.empty()){
				if(this->turmasAno1.top()->cadeirasTemVagas(ucs)){
					//inscrever aluno
				} else {
					//tentar outra turma
				}
			}
			break;
		case 2:
			while(!this->turmasAno1.empty()){
				if(this->turmasAno1.top()->cadeirasTemVagas(ucs)){
					//inscrever aluno
				} else {
					//tentar outra turma
				}
			}
			break;
		case 3:
			while(!this->turmasAno1.empty()){
				if(this->turmasAno1.top()->cadeirasTemVagas(ucs)){
					//inscrever aluno
				} else {
					//tentar outra turma
				}
			}
			break;
		case 4:
			while(!this->turmasAno1.empty()){
				if(this->turmasAno1.top()->cadeirasTemVagas(ucs)){
					//inscrever aluno
				} else {
					//tentar outra turma
				}
			}
			break;
		case 5:
			while(!this->turmasAno1.empty()){
				if(this->turmasAno1.top()->cadeirasTemVagas(ucs)){
					//inscrever aluno
				} else {
					//tentar outra turma
				}
			}
			break;
		default:
			cout << "Erro: Estado impossivel." << endl;
			exit (EXIT_FAILURE);
			break;
		}
	}
*/
	/*
	for(unsigned int i=0; i<turmas.size(); i++){
		turmas[i]->printInfo();
	}
	turmasAno1.top()->printInfo();
	turmasAno2.top()->printInfo();
	turmasAno3.top()->printInfo();
	turmasAno4.top()->printInfo();
	turmasAno5.top()->printInfo();
	 */

}

/**
 * output para ficheiro de toda a info do mieic
 */
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


