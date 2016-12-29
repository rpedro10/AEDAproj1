#include "docente.h"
#include "aluno.h"

int Docente::getCodigo() const {
	return codigo;
}

const string& Docente::getNome() const {
	return nome;
}

void Docente::setNome(const string& nome) {
	this->nome = nome;
}
/**
 * construtor de docente
 */
Docente::Docente(int cod, string nome, int qtt){
	this->codigo = cod;
	this->nome = nome;
	this->qtt = qtt;
}
/**
 * display de info do docente
 */
void Docente::displayDocente(){
	cout << "Nome : " << this->nome << endl;
	cout << "Codigo: " << this->codigo << endl;
	cout << "Quantidade de alunos a tutorar: " << this->qtt << endl;
	cout << "==============================" << endl;
}
/**
 * devolve a quantidade de alunos a tutorar
 */
int Docente::getQtt() const {
	return qtt;
}
/**
 * adiciona uma unidade a quantidade de alunos a tutorar
 */
void Docente::setQtt() {
	this->qtt = ++qtt;
}
/**
 * Adiciona aluno ao vector de alunos ao cargo do docente
 */
void Docente::addAluno(Aluno* aluno){
	this->alunos.push_back(aluno);
}
/**
 * retorna o vector de alunos ao cargo do docente
 */
vector<Aluno*> Docente::getAlunos(){
	return this->alunos;
}
/**
 * output para ficheiros
 */
void Docente::save(ofstream* output){
	(*output) << this->codigo << " ; " << this->nome << " ; " << this->qtt;
}

/**
 *	Marca uma reuniao nova na BST do docente
 */
void Docente::newReuniao(){
	vector<int> data(3);
	int id, in;
	string agenda, descricao;
	char r;

	cout << "Introduzir data" << endl;
	while(true){
		cout << "dia: ";
		cin >> data[0];
		cout << "mes: ";
		cin >> data[1];
		cout << "ano: ";
		cin >> data[2];
		cout << "No dia " << data[0] << "/" << data[1] << "/" << data[2] << " (y/n)?";
		cin >> r;
		if(r == 'y')
			break;
	}

	cout << "Escolha o aluno:" << endl;
	for(unsigned int i=0; i<alunos.size();i++){
		cout << i+1 << ".	";
		alunos[i]->displayAluno();
	}
	cout << "Introduza um numero: ";
	cin >> in;

	id = alunos[in-1]->getNumero();

	cout << "Agenda: ";
	cin >> agenda;

	cout << "Descricao: ";
	cin >> descricao;

	Reuniao reuniao = Reuniao(data, id, agenda, descricao);
	reunioes.insert(reuniao);

	/*testar reunioes
	set<Reuniao>::iterator it;
	for(it=reunioes.begin(); it!=reunioes.end();++it){
		it->printReuniao();
	}*/

	cout << "Introduza qualquer coisa para voltar ao menu anterior: ";
	cin >> r;
}

/**
 * Procura uma reuniao com a data fornecida.
 */
vector<Reuniao*> Docente::findReuniaoData(vector<int> d){
	vector<Reuniao*> rns;
	set<Reuniao>::iterator it;

	for(it=reunioes.begin(); it!=reunioes.end();++it){
		if(it->compareDate(d)){
			Reuniao r = Reuniao(it->getData(), it->getID(), it->getAgenda(), it->getDescricao());
			rns.push_back(&r);
		}
	}
	return rns;
}

/**
 * Procura uma reuniao com o estudante do ID fornecido.
 */
vector<Reuniao*> Docente::findReuniaoID(int id){
	vector<Reuniao*> rns;
	set<Reuniao>::iterator it;

	for(it=reunioes.begin(); it!=reunioes.end();++it){
		if(it->getID() == id){
			Reuniao r = Reuniao(it->getData(), it->getID(), it->getAgenda(), it->getDescricao());
			rns.push_back(&r);
		}
	}
	return rns;
}

/**
 * Imprime e deixa o utilizador cancelar uma das reunioes imprimidas.
 */
void Docente::cancelReuniao(){
	vector<Reuniao*> rns;
	cout << "Ind	Data	Estudante	Agenda" << endl;
	for(unsigned int i=0; i<rns.size(); i++){
		rns[i]->printReuniaoShort();
	}

	unsigned int number;
	cout<<"Inserir numero da Reuniao a cancelar: (zero para nao cancelar)";
	cin >> number;


	if(number != 0){
		set<Reuniao>::iterator it;
		it = reunioes.find((*rns[number-1]));
		reunioes.erase(it);
	}

}

/**
 * Muda a agenda e/ou a descricao da reuniao
 */
void Docente::changeTerms(Reuniao* reuniao, string agenda, string descricao){
	vector<Reuniao*> rns;
	set<Reuniao>::iterator it;
	it = reunioes.find((*reuniao));
	reunioes.erase(it);
	reuniao->setAgenda("agenda");
	reuniao->setAgenda("descricao");
	reunioes.insert((*reuniao));
}

/**
 * Procura todas as reunioes entre as datas fromDate e toDate
 */
vector<Reuniao*> Docente::getReunioes(vector<int> fromDate, vector<int> toDate){
	vector<Reuniao*> rns;
	const Reuniao ireuniao = Reuniao(fromDate, 0, "", "");
	const Reuniao freuniao = Reuniao(toDate, 0, "", "");
	set<Reuniao>::iterator it;

	for(it=reunioes.begin(); it!=reunioes.end();++it){
		Reuniao r = Reuniao(it->getData(), it->getID(), it->getAgenda(), it->getDescricao());
		if(r<ireuniao){
			rns.push_back(&r);
		}
	}
	return rns;
}

/**
 * Menu das accoes que o Docente pode fazer
 */
void Docente::menu(){
	while(true){
		cin.clear();
	    cin.ignore(10000,'\n');
		cout << "1. Nova Reuniao" << endl;
		cout << "2. Cancelar Reuniao" << endl;
		cout << "3. Procurar Reuniao por data" << endl;
		cout << "4. Procurar Reuniao por estudante" << endl;
		cout << "5. Mostrar todas as Renioes" << endl;
		cout << "6. Procurar Reunioes entre duas datas" << endl;
		cout << "7. Mudar Agenda e Descritivo da Reuniao" << endl;
		cout << "0. Sair" << endl;
		cout << "Introduza um numero para escolher a accao: ";

		unsigned int a;
		cin >> a;

		switch(a){
		case 0:
			return;
			break;
		case 1:
			newReuniao();
			break;
		case 3:{
			vector<int> data(3);
			char r;
			cout << "Introduzir data" << endl;
			while(true){
				cout << "dia: ";
				cin >> data[0];
				cout << "mes: ";
				cin >> data[1];
				cout << "ano: ";
				cin >> data[2];
				cout << "No dia " << data[0] << "/" << data[1] << "/" << data[2] << " (y/n)?";
				cin >> r;
				if(r == 'y')
					break;
			}
			findReuniaoData(data);
			break;}
		default:
			cout << "Introduza um numero valido." << endl;
			break;
		}
	}
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

/**
 * funcao que le info de docentes do ficheiro e inicializa o vetor
 */
vector<Docente*> initDocentes() {

	ifstream in;
	string filename;
	vector<Docente*> docentes;

	filename = "docentes.txt";

	in.open(filename.c_str(),ifstream::in);

	//TODO por excepcao de nao conseguir abrir o ficheiro

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

		string qttstr = line.substr(0, line.find(";") - 1); 			// qtt
		qtt = atoi(qttstr.c_str());
		line = line.substr(line.find(";") + 2, string::npos);

		Docente *docente = new Docente(id, name, qtt);
		docentes.push_back(docente);
	}


	in.close();

	return docentes;
}

