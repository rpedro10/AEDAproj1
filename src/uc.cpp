#include "uc.h"
#include "aluno.h"

Uc::Uc(string nome, string sigla, int semestre, int ano, float creditos){
	this->nome = nome;
	this->sigla = sigla;
	this->semestre = semestre;
	this->ano = ano;
	this->creditos = creditos;
}
/**
int Uc::getVagas(){
	return 100;
}
*/
int Uc::getAno() const {
	return ano;
}

void Uc::setAno(int ano) {
	this->ano = ano;
}

float Uc::getCreditos() const {
	return creditos;
}

void Uc::setCreditos(float creditos) {
	this->creditos = creditos;
}

const string& Uc::getNome() const {
	return nome;
}

void Uc::setNome(const string& nome) {
	this->nome = nome;
}

int Uc::getSemestre() const {
	return semestre;
}

void Uc::setSemestre(int semestre) {
	this->semestre = semestre;
}

const string& Uc::getSigla() const {
	return sigla;
}

void Uc::setSigla(const string& sigla) {
	this->sigla = sigla;
}

vector<Aluno*> Uc::getAlunos() const{
	return this->alunos;
}

void Uc::setAlunos(vector<Aluno*> alunos){
	this->alunos = alunos;
}

//void Uc::display_incomplete(int year){
//}

/**
 * UC Optativa
 */
Optativa::Optativa(string nome, string sigla, int semestre, int ano, float cred, int vagas, string curso, string fac, string area) :
	Uc(nome, sigla, semestre, ano, cred){
	this->area = area;
	this->vagas = vagas;
}

const string& Optativa::getArea() const {
	return area;
}

void Optativa::setArea(const string& area) {
	this->area = area;
}

const string& Optativa::getCurso() const {
	return curso;
}

void Optativa::setCurso(const string& curso) {
	this->curso = curso;
}

const string& Optativa::getFaculdade() const {
	return faculdade;
}

void Optativa::setFaculdade(const string& faculdade) {
	this->faculdade = faculdade;
}

int Optativa::getVagas() const {
	return vagas;
}

void Optativa::setVagas(int vagas) {
	this->vagas = vagas;
}

void Optativa::displayUC(){
	cout << "Unidade Curricular : " <<nome << endl;
	cout << "Sigla: " << sigla << endl;
	cout << "Ano Curricular: " << ano << endl;
	cout << "Semestre : " << semestre << endl;
	cout << "Creditos: " << creditos << endl;
	cout << "Alunos a frequentar: (" << alunos.size() << ")" << endl;

	for(unsigned int i = 0; i<this->alunos.size(); i++){
		cout << "	" << alunos[i]->getNumero() << "	" << alunos[i]->getNome() << endl;
	}

	cout << "Vagas: " << vagas << endl;

	cout << "==============================" << endl;
}
/**
void Optativa::display_incomplete(int year){
	if(year <=ano){
		cout << "Unidade Curricular : " <<nome << endl;
		cout << "Sigla: " << sigla << endl;
		cout << "Ano Curricular: " << ano << endl;
		cout << "Semestre : " << semestre << endl;
		cout << "Creditos: " << creditos << endl;
		cout << "Vagas: " << vagas << endl;
	}

}
*/
int Optativa::addAluno(Aluno* aluno){
	if(this->getVagas() < 1){
		this->alunos.push_back(aluno);
		return 1;
	} else {
		printf("Nao existem vagas suficientes\n");

		//TODO codigo que procura cadeiras da mesma area e sugere ao aluno

		return 0;
	}

	return -1;
}

/**
 * UC Nao Optativa
 */
N_Optativa::N_Optativa(string nome, string sigla, int semestre, int ano, float cred) :
	Uc(nome, sigla, semestre, ano, cred){
}




void N_Optativa::displayUC(){
	cout << "Unidade Curricular : " << this->nome << endl;
	cout << "Sigla: " << this->sigla << endl;
	cout << "Ano Curricular: " << this->ano << endl;
	cout << "Semestre : " << this->semestre << endl;
	cout << "Creditos: " << this->creditos << endl;
	cout << "Alunos a frequentar: " << endl;

	for(unsigned int i = 0; i<this->alunos.size(); i++){
		cout << "	" << this->alunos[i]->getNumero() << "	" << this->alunos[i]->getNome() << endl;
	}

	cout << "==============================" << endl;
}
/**
void N_Optativa::display_incomplete(int year){
	cout << "Unidade Curricular : " <<nome << endl;
		cout << "Sigla: " << sigla << endl;
		cout << "Ano Curricular: " << ano << endl;
		cout << "Semestre : " << semestre << endl;
		cout << "Creditos: " << creditos << endl;

}

*/
int N_Optativa::addAluno(Aluno* aluno){
	this->alunos.push_back(aluno);
	return 0;
}

vector<Uc*> initUCs(){
	ifstream in;
	string filename;
	vector<Uc*> cadeiras;

	in.open("ucs.txt");

	//TODO por excepcao de nao conseguir abrir o ficheiro

	string nome;
	string sigla;
	int ano;
	int semestre;
	double creditos;

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
		creditos = strtod(creditosStr.c_str(),NULL);

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

