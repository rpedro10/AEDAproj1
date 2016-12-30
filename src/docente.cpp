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
Docente::Docente(int cod, string nome, int qtt, set<Reuniao> rns){
	this->codigo = cod;
	this->nome = nome;
	this->qtt = qtt;
	this->reunioes = rns;
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
	(*output) << this->codigo << " ; " << this->nome << " ; " << this->qtt << " ; ";

	set<Reuniao>::iterator it;
	/* Datas */
	string data;
	unsigned int i = 0;
	for(it=reunioes.begin(); it!=reunioes.end();++it){
		if(it->getData()[0]<10)
			(*output) << 0 << it->getData()[0];
		else
			(*output) << it->getData()[0];

		(*output) << "/";

		if(it->getData()[1]<10)
			(*output) << 0 << it->getData()[1];
		else
			(*output) << it->getData()[1];

		(*output) << "/";

		if(it->getData()[2]<10)
			(*output) << 0 << it->getData()[2];
		else
			(*output) << it->getData()[2];

		if(++i != reunioes.size())
			(*output) << ", " ;
	}
	(*output) << " ; ";

	/* Codigo estudante */
	i = 0;
	for(it=reunioes.begin(); it!=reunioes.end();++it){
		(*output) << it->getID();
		if(++i != reunioes.size())
			(*output) << ", " ;
	}
	(*output) << " ; ";

	/* Agenda */
	i = 0;
	for(it=reunioes.begin(); it!=reunioes.end();++it){
		(*output) << it->getAgenda();
		if(++i != reunioes.size())
			(*output) << ", " ;
	}
	(*output) << " ; ";

	/* Descricao */
	i = 0;
	for(it=reunioes.begin(); it!=reunioes.end();++it){
		(*output) << it->getDescricao();
		if(++i != reunioes.size())
			(*output) << ", " ;
	}
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

	string s;
	cout << "Introduza qualquer coisa para voltar ao menu: ";
	cin >> s;
}

/**
 * Procura uma reuniao com a data fornecida.
 */
vector<Reuniao*> Docente::findReuniaoData(){
	vector<int> d(3);
	char r;
	cout << "Introduzir data" << endl;
	while(true){
		cout << "dia: ";
		cin >> d[0];
		cout << "mes: ";
		cin >> d[1];
		cout << "ano: ";
		cin >> d[2];
		cout << "No dia " << d[0] << "/" << d[1] << "/" << d[2] << " (y/n)?";
		cin >> r;
		if(r == 'y')
			break;
	}

	vector<Reuniao*> rns;
	set<Reuniao>::iterator it;
	for(it=reunioes.begin(); it!=reunioes.end();++it){
		if(it->compareDate(d)){
			Reuniao* r = new Reuniao(it->getData(), it->getID(), it->getAgenda(), it->getDescricao());
			rns.push_back(r);
		}
	}
	return rns;
}

/**
 * Procura uma reuniao com o estudante do ID fornecido.
 */
vector<Reuniao*> Docente::findReuniaoID(){
	unsigned int id, in;
	cout << "Escolha o aluno:" << endl;
	for(unsigned int i=0; i<alunos.size();i++){
		cout << i+1 << ".	";
		alunos[i]->displayAluno();
	}

	cout << "Introduza uma opcao: ";
	while(true){
		cin >> in;
		if(in>alunos.size())
			cout << "Introduza uma opcao valida.";
		else
			break;
	}

	id = alunos[in-1]->getNumero();

	vector<Reuniao*> rns;
	set<Reuniao>::iterator it;
	for(it=reunioes.begin(); it!=reunioes.end();++it){
		if(it->getID() == id){
			Reuniao* r = new Reuniao(it->getData(), it->getID(), it->getAgenda(), it->getDescricao());
			rns.push_back(r);
		}
	}
	return rns;
}

/**
 * Imprime e deixa o utilizador cancelar uma das reunioes imprimidas.
 */
void Docente::cancelReuniao(Reuniao* reuniao){
	set<Reuniao>::iterator it;
	it = reunioes.find((*reuniao));
	reunioes.erase(it);
	cout << "Reuniao cancelada. Introduza algo para continuar. ";
	string a;
	cin >> a;
}

/**
 * Muda a agenda e/ou a descricao da reuniao
 */
void Docente::changeTerms(Reuniao* reuniao){
	string agenda, descricao;

	cout << "Introduza novos dados: " << endl;
	cout << "Agenda: ";
	cin >> agenda;
	cout << "Descricao: ";
	cin >> descricao;

	set<Reuniao>::iterator it;
	it = reunioes.find((*reuniao));
	reunioes.erase(it);
	reuniao->setAgenda(agenda);
	reuniao->setDescricao(descricao);
	reunioes.insert((*reuniao));

	cout << "===========================" << endl;
	reuniao->printReuniao();

	cout << "Introduza algo para continuar. ";
	string a;
	cin >> a;
}

/**
 * Procura todas as reunioes entre as datas fromDate e toDate
 */
vector<Reuniao*> Docente::getReunioes(){
	vector<int> fromDate(3), toDate(3);

	char r;
	cout << "Data de inicio" << endl;
	while(true){
		cout << "dia: ";
		cin >> fromDate[0];
		cout << "mes: ";
		cin >> fromDate[1];
		cout << "ano: ";
		cin >> fromDate[2];
		cout << "Data correta, " << fromDate[0] << "/" << fromDate[1] << "/" << fromDate[2] << " (y/n)?";
		cin >> r;
		if(r == 'y')
			break;
	}
	cout << "Data de fim" << endl;
	while(true){
		cout << "dia: ";
		cin >> toDate[0];
		cout << "mes: ";
		cin >> toDate[1];
		cout << "ano: ";
		cin >> toDate[2];
		cout << "Data correta, " << toDate[0] << "/" << toDate[1] << "/" << toDate[2] << " (y/n)?";
		cin >> r;
		if(r == 'y')
			break;
	}

	vector<Reuniao*> rns;
	const Reuniao ireuniao = Reuniao(fromDate, 0, "", "");
	const Reuniao freuniao = Reuniao(toDate, 0, "", "");

	set<Reuniao>::iterator it;
	for(it=reunioes.begin(); it!=reunioes.end();++it){
		Reuniao* r = new Reuniao(it->getData(), it->getID(), it->getAgenda(), it->getDescricao());
		if((*r)<freuniao && ireuniao<(*r)){
			rns.push_back(r);
		}
	}
	return rns;
}

/**
 * Imprime todas as reunioes
 */
void Docente::printAllReunioes(){
	set<Reuniao>::iterator it;
	for(it=reunioes.begin(); it!=reunioes.end();++it){
		it->printReuniaoShort();
	}

	string s;
	cout << "Introduza qualquer coisa para voltar ao menu: ";
	cin >> s;
}

Reuniao* Docente::chooseReuniao(vector<Reuniao*> rns){
	if(rns.size() == 0){
		cout << "Nenhuma Reuniao encontrada." << endl;
		return NULL;
	}
	unsigned int r;
	for(unsigned int i=0; i<rns.size(); i++){
		cout << i+1 << ".	";
		rns[i]->printReuniaoShort();
	}

	cout << "Escolha a reuniao (pelo numero): ";
	while(true){
		cin >> r;
		if(r>0 && r<=rns.size()) break;
		else cout << "Introduza um numero valido.";
	}

	return rns[r-1];
}

/**
 * Submenu para alteracao dos dados de uma reuniao
 */
void Docente::subMenu(Reuniao* reuniao){
	reuniao->printReuniao();

	cin.clear();
	cin.ignore(10000,'\n');
	cout << "Pretende: " << endl;
	cout << "1. Cancelar a Reuniao" << endl;
	cout << "2. Mudar Agenda e Descritivo da Reuniao" << endl;
	cout << "0. Voltar" << endl;
	cout << "Introduza um numero para escolher a accao: ";

	while(true){
		unsigned int a;
		cin >> a;
		switch(a){
		case 0:
			return;
			break;
		case 1:
			cancelReuniao(reuniao);
			return;
			break;
		case 2:
			changeTerms(reuniao);
			return;
			break;
		default:
			cout << "Introduza uma opcao valida." << endl;
			break;
		}
	}

}

/**
 * Menu das accoes que o Docente pode fazer
 */
void Docente::menu(){
	Reuniao* reuniao;
	while(true){
		cin.clear();
		cin.ignore(10000,'\n');
		cout << "1. Nova Reuniao" << endl;
		cout << "2. Procurar Reuniao por data" << endl;
		cout << "3. Procurar Reuniao por estudante" << endl;
		cout << "4. Mostrar todas as Reunioes" << endl;
		cout << "5. Procurar Reuniao entre duas datas" << endl;
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
		case 2:
			if(reunioes.empty()){
				cout << "Nao existem reunioes para mostrar." << endl;
				break;
			}
			reuniao = chooseReuniao(findReuniaoData());
			if(reuniao != NULL)	subMenu(reuniao);
			break;
		case 3:
			if(reunioes.empty()){
				cout << "Nao existem reunioes para mostrar." << endl;
				break;
			}
			reuniao = chooseReuniao(findReuniaoID());
			if(reuniao != NULL)	subMenu(reuniao);
			break;
		case 4:
			if(reunioes.empty()){
				cout << "Nao existem reunioes para mostrar." << endl;
				break;
			}
			printAllReunioes();
			break;
		case 5:
			if(reunioes.empty()){
				cout << "Nao existem reunioes para mostrar." << endl;
				break;
			}
			reuniao = chooseReuniao(getReunioes());
			if(reuniao != NULL)	subMenu(reuniao);
			break;
		default:
			cout << "Introduza uma opcao valido." << endl;
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

		/* BST de Reunioes */
		string dataR;													//datas
		string d, m, a;
		int dia, mes, ano;
		vector<int> data(3);
		vector< vector<int> > datas;

		dataR = line.substr(0, line.find(","));
		d = dataR.substr(0,line.find('/'));
		dia = atoi(d.c_str());
		data[0]=dia;
		dataR = dataR.substr(line.find('/')+1,string::npos);
		m = dataR.substr(0,line.find('/'));
		mes = atoi(m.c_str());
		data[1]=mes;
		dataR = dataR.substr(line.find('/')+1,string::npos);
		ano = atoi(dataR.c_str());
		data[2]=ano;

		while(line.find(';') > line.find(',')){
			datas.push_back(data);
			line = line.substr(line.find(",") + 2, string::npos);

			dataR = line.substr(0, line.find(","));
			d = dataR.substr(0,line.find('/'));
			dia = atoi(d.c_str());
			data[0]=dia;
			dataR = dataR.substr(line.find('/')+1,string::npos);
			m = dataR.substr(0,line.find('/'));
			mes = atoi(m.c_str());
			data[1]=mes;
			dataR = dataR.substr(line.find('/')+1,string::npos);
			ano = atoi(dataR.c_str());
			data[2]=ano;
		}

		dataR = line.substr(0, line.find(";")-1);
		d = dataR.substr(0,line.find('/'));
		dia = atoi(d.c_str());
		data[0]=dia;
		dataR = dataR.substr(line.find('/')+1,string::npos);
		m = dataR.substr(0,line.find('/'));
		mes = atoi(m.c_str());
		data[1]=mes;
		dataR = dataR.substr(line.find('/')+1,string::npos);
		ano = atoi(dataR.c_str());
		data[2]=ano;
		datas.push_back(data);
		line = line.substr(line.find(";") + 2, string::npos);

		string idR;														// ids estudantes
		int sid;
		vector<int> ids;
		idR = line.substr(0, line.find(","));
		while(line.find(';') > line.find(',')){
			sid = atoi(idR.c_str());
			ids.push_back(sid);
			line = line.substr(line.find(",") + 2, string::npos);
			idR = line.substr(0, line.find(","));
		}

		idR = line.substr(0, line.find(";")-1);
		sid = atoi(idR.c_str());
		ids.push_back(sid);
		line = line.substr(line.find(";") + 2, string::npos);

		string agenda;													//agendas
		vector<string> agendas;
		agenda = line.substr(0, line.find(","));
		while(line.find(';') > line.find(',')){
			agendas.push_back(agenda);
			line = line.substr(line.find(",") + 2, string::npos);
			agenda = line.substr(0, line.find(","));
		}

		agenda = line.substr(0, line.find(";") - 1);
		agendas.push_back(agenda);
		line = line.substr(line.find(";") + 2, string::npos);

		string descricao;												//descricoes
		vector<string> descricoes;
		while(line.find(';') > line.find(',')){
			descricao = line.substr(0, line.find(","));
			descricoes.push_back(descricao);
			line = line.substr(line.find(",") + 2);
		}

		if(descricao.compare(line) !=0)
			descricoes.push_back(line);

		set<Reuniao> reunioes;
		for(unsigned int i=0; i<ids.size(); i++){
			Reuniao reuniao = Reuniao(datas[i], ids[i], agendas[i], descricoes[i]);
			reunioes.insert(reuniao);
		}

		Docente *docente = new Docente(id, name, qtt, reunioes);
		docentes.push_back(docente);
	}


	in.close();

	return docentes;
}

