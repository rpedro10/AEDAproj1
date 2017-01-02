#include "aluno.h"

Aluno::Aluno(int num, string nome, int ano, string email, string estatuto, Docente* tutor,
		vector< pair<string, Uc *> > cadeiras_inscrito, vector< pair<string, Uc *> > cadeiras_completadas){
	this->numero = num;  				// coloca o n�
	this->nome = nome;					// nome colocado
	this->ano = ano;
	this->email = email;
	this->estatuto = estatuto;
	this->tutor = tutor;
	this->cadeiras_inscrito = cadeiras_inscrito;
	this->cadeiras_completadas = cadeiras_completadas;
}

Aluno::Aluno(){
}

bool Aluno::operator == (const Aluno* & p2) const
{	cout<<"1";
	cout<<p2->getNome();
	return nome == p2->getNome(); }


vector< pair<string, Uc *> > Aluno::getCadeirasCompletadas() const{
	return this->cadeiras_completadas;
}

void Aluno::setCadeirasCompletadas(vector< pair<string, Uc *> > cadeirasCompletadas){
	this->cadeiras_completadas = cadeirasCompletadas;
}


int Aluno::getAno() const {
	return ano;
}

void Aluno::setAno(int ano) {
	this->ano = ano;
}

vector< pair<string, Uc *> > Aluno::getCadeirasInscrito() const {
	return cadeiras_inscrito;
}

void Aluno::setCadeirasInscrito(vector< pair<string, Uc *> > cadeirasInscrito) {
	cadeiras_inscrito = cadeirasInscrito;
}



const string& Aluno::getEmail() const {
	return email;
}

void Aluno::setEmail(const string& email) {
	this->email = email;
}

const string& Aluno::getEstatuto() const {
	return estatuto;
}

void Aluno::setEstatuto(const string& estatuto) {
	this->estatuto = estatuto;
}

const string& Aluno::getNome() const {
	return nome;
}

void Aluno::setNome(const string& nome) {
	this->nome = nome;
}

int Aluno::getNumero() const {
	return numero;
}

void Aluno::setNumero(int numero) {
	this->numero = numero;
}

const Docente* Aluno::getTutor() const{
	return this->tutor;
}

void Aluno::displayAlunoInfo(){
	cout << "Nome : " << nome << endl;
	cout << "Numero de Estudante: " << numero << endl;
	cout << "Ano Curricular: " << ano << endl;
	cout << "Email: " <<email << endl;
	cout << "Estado: " << estado << endl;
	//cout << "Data de inscricao: " << this->data << endl;
	cout << "Estatuto: " << estatuto << endl;
	cout << "Tutor: " << (*tutor).getNome() << endl;
	cout << "Cadeiras que frequenta: " << "(" <<cadeiras_inscrito.size() << ")" << endl;

	for(unsigned int i = 0; i<this->cadeiras_inscrito.size(); i++){
		cout << "	" << cadeiras_inscrito[i].second->getSigla();
		cout << "	" << cadeiras_inscrito[i].second->getNome();
		cout << "	" << cadeiras_inscrito[i].first << endl;
		//cout << "	" << (*cadeiras_inscrito[i]).getSigla() << "	" << (*cadeiras_inscrito[i]).getNome() << endl;
	}

	cout << "Cadeiras que concluiu: " << "(" << cadeiras_completadas.size() << ")" << endl;

	for(unsigned int i = 0; i < cadeiras_completadas.size(); i++){
		cout << "	" << cadeiras_completadas[i].second->getSigla();
		cout << "	" << cadeiras_completadas[i].second->getNome();
		cout << "	" << cadeiras_completadas[i].first << endl;
		//cout << "	" << (*cadeiras_inscrito[i]).getSigla() << "	" << (*cadeiras_inscrito[i]).getNome() << endl;
	}

	cout << "==============================" << endl;

}



void Aluno::displayAluno(){
	cout << numero << "	" << nome << "	" << endl;
}

bool Aluno::estaInscrito(Uc* uc){
	for(unsigned int i = 0; i < cadeiras_inscrito.size(); i++){
		if(uc->getSigla().compare(cadeiras_inscrito[i].second->getSigla()) == 0){
			return true;
		}
	}
	return false;
}

bool Aluno::completou(Uc* uc){
	for(unsigned int i = 0; i < cadeiras_completadas.size(); i++){
		if(uc->getSigla().compare(cadeiras_completadas[i].second->getSigla()) == 0){
			return true;
		}
	}
	return false;
}


void Aluno::save(ofstream* output){
	(*output) << this->numero << " ; " << this->nome << " ; " << this->ano << " ; " << this->email << " ; " << this->estatuto
	 	 	  << " ; " << this->tutor->getCodigo() << " ; ";

	/** cadeiras_completadas **/
	for(unsigned int i=0; i<this->cadeiras_completadas.size(); i++){
		(*output) << this->cadeiras_completadas[i].first;
		if(i != this->cadeiras_completadas.size()-1){
			(*output) << ", ";
		}
	}

	(*output) << " ; ";

	for(unsigned int i=0; i<this->cadeiras_completadas.size(); i++){
		(*output) << this->cadeiras_completadas[i].second->getSigla();
		if(i != this->cadeiras_completadas.size()-1){
			(*output) << ", ";
		}
	}

	(*output) << " ; ";

	/** cadeiras_inscrito **/
	for(unsigned int i=0; i<this->cadeiras_inscrito.size(); i++){
		(*output) << this->cadeiras_inscrito[i].first;
		if(i != this->cadeiras_inscrito.size()-1){
			(*output) << ", ";
		}
	}

	(*output) << " ; ";

	for(unsigned int i=0; i<this->cadeiras_inscrito.size(); i++){
		(*output) << this->cadeiras_inscrito[i].second->getSigla();
		if(i != this->cadeiras_inscrito.size()-1){
			(*output) << ", ";
		}
	}
}

void Aluno::terminarAno(){
	displayAluno();
	string yn;
	for(unsigned int i = 0; i < cadeiras_inscrito.size(); i++){
		cout << "	" << cadeiras_inscrito[i].second->getSigla();
		cout << "	" << cadeiras_inscrito[i].second->getNome() << endl;
		cout << "O aluno passou a esta cadeira (y/n)? ";
		cin >> yn;

		if(yn.compare("y") == 0){
			cadeiras_completadas.push_back(cadeiras_inscrito[i]);
		}
	}

	for(unsigned int i = 0; i < cadeiras_completadas.size(); i++){
		for(unsigned int j = 0; j < cadeiras_inscrito.size(); j++){
			if(cadeiras_completadas[i].second->getSigla().compare(cadeiras_inscrito[j].second->getSigla()) == 0){
				cadeiras_inscrito.erase(cadeiras_inscrito.begin()+j);
				j = cadeiras_inscrito.size();
			}
		}

		cadeiras_completadas[i].second->removeAluno(this->numero);
	}


	displayAlunoInfo();

}

Estado Aluno::getEstado() const {
	return estado;
}

const string& Aluno::getMorada() const {
	return morada;
}

void Aluno::setMorada(const string& morada) {
	this->morada = morada;
}

void Aluno::setEstado(Estado estado) {
	this->estado = estado;
}

vector<Uc*> Aluno::getUCsAnoBase(int semestre){
	vector<Uc*> ucs;
	for(unsigned int i=0; i<this->cadeiras_inscrito.size(); i++){
		if(this->cadeiras_inscrito[i].second->getAno() == this->ano
				&& this->cadeiras_inscrito[i].second->getSemestre() == semestre){
			ucs.push_back(this->cadeiras_inscrito[i].second);
		}
	}
	return ucs;
}

unsigned int Aluno::getUCsSemestre(int semestre){
	vector<Uc*> ucs;
	for(unsigned int i=0; i<this->cadeiras_inscrito.size(); i++){
		if(this->cadeiras_inscrito[i].second->getSemestre() == semestre){
			ucs.push_back(this->cadeiras_inscrito[i].second);
		}
	}
	return ucs.size();
}

//__________________________________________________________________

vector<Aluno*> initAlunos(vector <Docente*> docentes, vector<Uc*> ucs){
	ifstream in;
	string filename;
	vector<Aluno*> alunos;

	filename = "aa.txt";

	in.open(filename.c_str(),ifstream::in);

	//TODO por excepcao de nao conseguir abrir o ficheiro

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
		
		/** CADEIRAS COMPLETADAS **/
		line = line.substr(line.find(";") + 2, string::npos);
		string dataC;
		vector<string> dataUCsC;										// datas de inscricao
		dataC = line.substr(0, line.find(","));
		while(line.find(';') > line.find(',')){
			dataUCsC.push_back(dataC);
			line = line.substr(line.find(",") + 2, string::npos);
			dataC = line.substr(0, line.find(","));
		}

		dataC = line.substr(0, line.find(";") - 1);
		dataUCsC.push_back(dataC);
		
		line = line.substr(line.find(";") + 2, string::npos);
		string ucC;
		vector<Uc*> ucsAlunoC;											// cadeiras completadas
		ucC = line.substr(0, line.find(","));
		while(line.find(';') > line.find(',')){
			ucC = line.substr(0, line.find(","));
			for(unsigned int i = 0; i<ucs.size(); i++){
				if(ucC.compare((*ucs[i]).getSigla()) == 0){
					ucsAlunoC.push_back(ucs[i]);
				}
			}
			line = line.substr(line.find(",") + 2);
		}

		ucC = line.substr(0, line.find(";") - 1);
		if(ucC.compare(line) != 0){
			for(unsigned int i = 0; i<ucs.size(); i++){
				if(ucC.compare((*ucs[i]).getSigla()) == 0){
					ucsAlunoC.push_back(ucs[i]);
				}
			}
		}

		vector< pair<string, Uc *> > cadeirasC;
		for(unsigned int i = 0; i<ucsAlunoC.size(); i++){
			cadeirasC.push_back({dataUCsC[i],ucsAlunoC[i]});
		}
		
		/** CADEIRAS INSCRITO **/
		line = line.substr(line.find(";") + 2, string::npos);
		string dataI;
		vector<string> dataUCsI;										// datas de inscricao
		dataI = line.substr(0, line.find(","));
		while(line.find(';') > line.find(',')){
			dataUCsI.push_back(dataI);
			line = line.substr(line.find(",") + 2, string::npos);
			dataI = line.substr(0, line.find(","));
		}

		dataI = line.substr(0, line.find(";") - 1);
		dataUCsI.push_back(dataI);

		line = line.substr(line.find(";") + 2);
		string ucI;
		vector<Uc*> ucsAlunoI;
		while (line.find(",") != string::npos){							// cadeiras inscrito
			ucI = line.substr(0, line.find(","));
			for(unsigned int i = 0; i<ucs.size(); i++){
				if(ucI.compare((*ucs[i]).getSigla()) == 0){
					ucsAlunoI.push_back(ucs[i]);
				}
			}
			line = line.substr(line.find(",") + 2);
		}

		if(ucI.compare(line) != 0)
			for(unsigned int i = 0; i<ucs.size(); i++){
				if(line.compare((*ucs[i]).getSigla()) == 0){
					ucsAlunoI.push_back(ucs[i]);
				}
			}

		vector< pair<string, Uc *> > cadeiras;
		for(unsigned int i = 0; i<ucsAlunoI.size(); i++){
			cadeiras.push_back({dataUCsI[i],ucsAlunoI[i]});
		}


		Aluno* aluno = new Aluno(id, name, year, email, estatuto, tutor, cadeiras, cadeirasC);
		alunos.push_back(aluno);
	}
	in.close();

	return alunos;
}

	
