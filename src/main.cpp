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


vector<Aluno*> initAlunos(vector <Docente*> docentes, vector<Uc*> ucs){
	ifstream in;
	string filename;
	vector<Aluno*> alunos;

	filename = "aa.txt";

	in.open(filename.c_str(),ifstream::in);

	/**
	while (in.fail()){									// testa se abriu o ficheiro
		cerr << "Input file opening failed.\n";
		cout << "nome do ficheiro de alunos? ";
		cin >> filename;
		filename += ".txt";
		//in.open("aa.txt");
	}
	*/

	string line;

	int id;
	string name;
	int year;
	string data;
	string email;
	Docente* tutor;

	while (getline(in, line)){

		string IDstr = line.substr(0, line.find(";") - 1); 				// numero
		id = atoi(IDstr.c_str());

		line = line.substr(line.find(";") + 2, string::npos);
		name = line.substr(0, line.find(";") - 1); 						// nome

		line = line.substr(line.find(";") + 2, string::npos);
		string YEARstr = line.substr(0, line.find(";") - 1);			// ano
		year = atoi(YEARstr.c_str());

		line = line.substr(line.find(";") + 2, string::npos);
		data = line.substr(0, line.find(";") - 1);						// data

		line = line.substr(line.find(";") + 2, string::npos);
		email = line.substr(0, line.find(";") - 1); 					// email

		line = line.substr(line.find(";") + 2, string::npos);
		string estatuto = line.substr(0, line.find(";") - 1); 			// estatuto

		line = line.substr(line.find(";") + 2, string::npos);
		int tutorID;
		string tutorIDstr = line.substr(0, line.find(";") - 1); 		// tutor
		tutorID = atoi(YEARstr.c_str());
		for(unsigned int i = 0; i<docentes.size(); i++){
			if((*docentes[i]).getCodigo() == tutorID){
				tutor = docentes[i];
			}
		}

		line = line.substr(line.find(";") + 2, string::npos);
		string uc;

		vector<Uc*> ucsAluno;

		while (line.find(",") != string::npos){							// cadeiras
			uc = line.substr(0, line.find(","));

			for(unsigned int i = 0; i<ucs.size(); i++){
				if(uc.compare((*ucs[i]).getSigla()) == 0){
					ucsAluno.push_back(ucs[i]);
				}
			}

			line = line.substr(line.find(",") + 2);
		}

		if(uc.compare(line) != 0)
			for(unsigned int i = 0; i<ucs.size(); i++){
				if(line.compare((*ucs[i]).getSigla()) == 0){
					ucsAluno.push_back(ucs[i]);
				}
			}


		Aluno* aluno = new Aluno(id, name, year, data, email, estatuto, tutor, ucsAluno);
		alunos.push_back(aluno);

		/*
		cout << id << endl;
		cout << name << endl;
		cout << year << endl << data << endl;
		cout << email << endl << estatuto << endl;
		cout << (*tutor).getNome() << endl;
		for (unsigned int i = 0; i < ucsAluno.size(); i++){
			cout << (*ucsAluno[i]).getSigla() << endl;
		}
		cout << "==============================" << endl;
		*/
	}
	in.close();

	return alunos;

}


vector<Uc*> initUCs(){
	ifstream in;
	string filename;
	vector<Uc*> cadeiras;

	in.open("ucs.txt");

	/*
	while (in.fail()){							// testa se abriu o ficheiro
		cerr << "Input file opening failed.\n";
		cout << "nome do ficheiro de alunos? ";
		cin >> filename;
		filename += ".txt";
		in.open("ucs.txt");
	}
	*/

	string nome;
	string sigla;
	int ano;
	int semestre;
	float creditos;

	string line;

	while(getline(in, line)) {

		string optStr = line.substr(0, line.find(";") - 1);				// optatividade
		int opt = atoi(optStr.c_str());

		line = line.substr(line.find(";") + 2, string::npos);
		nome = line.substr(0, line.find(";") - 1);						// nome

		line = line.substr(line.find(";") + 2, string::npos);
		sigla = line.substr(0, line.find(";") - 1);						// sigla

		line = line.substr(line.find(";") + 2, string::npos);
		string anoStr = line.substr(0, line.find(";") - 1);				// ano
		ano = atoi(anoStr.c_str());

		line = line.substr(line.find(";") + 2, string::npos);
		string semestreStr = line.substr(0, line.find(";") - 1);		// semestre
		semestre = atoi(semestreStr.c_str());//semestre

		line = line.substr(line.find(";") + 2, string::npos);
		string creditosStr = line.substr(0, line.find(";") - 1);		// creditos
		creditos = atoi(creditosStr.c_str());

		if(opt == 1) {
			line = line.substr(line.find(";") + 2, string::npos);
			string area = line.substr(0, line.find(";") - 1);			// area

			line = line.substr(line.find(";") + 2, string::npos);
			string curso = line.substr(0, line.find(";") - 1);			// curso

			line = line.substr(line.find(";") + 2, string::npos);
			string faculdade = line.substr(0, line.find(";") - 1);		// faculdade

			line = line.substr(line.find(";") + 2, string::npos);
			string vagasStr = line.substr(0, line.find(";") - 1);		// vagas
			int vagas = atoi(vagasStr.c_str());

			Optativa* uc = new Optativa(nome, sigla, semestre, ano, creditos, vagas, curso, faculdade, area);
			cadeiras.push_back(uc);

		} else {

			N_Optativa* uc = new N_Optativa(nome, sigla, semestre, ano, creditos);
			cadeiras.push_back(uc);
		}
	}
	in.close();

	return cadeiras;

}

vector<Docente*> initDocentes() {

	ifstream in;
	string filename;
	vector<Docente*> docentes;

	filename = "docentes.txt";

	in.open(filename.c_str(),ifstream::in);

	/**
	while (in.fail()){							// testa se abriu o ficheiro
		cerr << "Input file opening failed.\n";
		cout << "nome do ficheiro de alunos? ";
		cin >> filename;
		filename += ".txt";
		//in.open("aa.txt");
	}
	 */

	string line;

	while (getline(in, line)){
		int id;
		string name;
		int qtt;

		string IDstr = line.substr(0, line.find(";") - 1); 				// numero
		id = atoi(IDstr.c_str());
		line = line.substr(line.find(";") + 2, string::npos);

		name = line.substr(0, line.find(";") - 1); 						// nome
		line = line.substr(line.find(";") + 2, string::npos);

		string qttstr = line.substr(0, line.find(";") - 1); 				// qtt
		qtt = atoi(qttstr.c_str());
		line = line.substr(line.find(";") + 2, string::npos);

		Docente *docente = new Docente(id, name, qtt);
		docentes.push_back(docente);
	}


	in.close();

	return docentes;
}

int loadDependencies(vector<Aluno*> alunos){
	for(unsigned int i = 0; i<alunos.size(); i++){
		vector<Uc*> ucsAluno = (*alunos[i]).getCadeirasInscrito();

		for(unsigned int j = 0; j<ucsAluno.size(); j++){
			(*ucsAluno[j]).addAluno(alunos[i]);
		}
	}

	return 0;
}

int main() {
	cout << "Bem Vindo ao curso de Mestrado Integrado em Engenharia Informatica" << endl;

	//file loading

	vector<Docente*> docentes = initDocentes();
	vector<Uc*> ucs = initUCs();
	vector<Aluno*> alunos = initAlunos(docentes, ucs);

	if(loadDependencies(alunos)<0){
		printf("Erro a carregar dependencias. Saindo...");
		return -1;
	}



	printf("-=-=-=-=-Alunos=-=-=-=-=-\n");
	for(unsigned int i = 0; i<alunos.size(); i++){
		(*alunos[i]).displayAluno();
	}
	printf("-=-=-=-=-Docentes=-=-=-=-\n");
	for(unsigned int i = 0; i<docentes.size(); i++){
		(*docentes[i]).displayDocente();
	}
	printf("-=-=-=-=-=-UCs-=-=-=-=-=-\n");
	for(unsigned int i = 0; i<ucs.size(); i++){
		(*ucs[i]).displayUC();
	}



	Mieic mieic = Mieic(ucs, docentes, alunos);
	


	return 0;
}
