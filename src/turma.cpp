#include "turma.h"

Turma::Turma(string turmaID, vector< pair<int,Uc*> > vagasCadeiras):
	turmaID(turmaID), vagasCadeiras(vagasCadeiras){}

string Turma::getTurmaID() const{
	return this->turmaID;
}

vector< pair<int,Uc*> > Turma::getVagasCadeiras(){
	return this->vagasCadeiras;
}

bool Turma::operator <(const Turma &t1) const {/*
	if(this->vagasCadeiras.size() < t1.vagasCadeiras.size())
		return true;
*/
	int thisTotalVagasT;
	for(unsigned int i = 0; i < this->vagasCadeiras.size(); i++){
		thisTotalVagasT += this->vagasCadeiras[i].first;
	}

	int t1totalVagas;
	for(unsigned int i = 0; i < t1.vagasCadeiras.size(); i++){
		t1totalVagas += t1.vagasCadeiras[i].first;
	}

	if(thisTotalVagasT < t1totalVagas)
		return true;
	return false;
}

bool Turma::operator ==(const Turma &t1) const {
	if(this->turmaID.compare(t1.turmaID) == 0)
		return true;
	else return false;
}

void Turma::printInfo(){
	cout << this->turmaID << "	" << this->vagasCadeiras.size() << "	";
	for(unsigned int i=0; i<this->vagasCadeiras.size(); i++){
		cout << "|" << this->vagasCadeiras[i].first << " "
				<< this->vagasCadeiras[i].second->getSigla();
	}
	cout << endl;
}

bool Turma::cadeirasTemVagas(vector<Uc*> ucs){
	unsigned int aux = 0;
	for(unsigned int i=0; i<ucs.size(); i++){
		for(unsigned int j=0; j<this->vagasCadeiras.size(); j++){
			if(ucs[i]->getSigla().compare(this->vagasCadeiras[j].second->getSigla()) == 0
					&& this->vagasCadeiras[j].first > 0){
				aux++;
			}
		}
	}
	if(aux == ucs.size()) return true;
	else return false;
}

void Turma::inscreverAluno(vector<Uc*> ucs, Aluno* aluno){
	for(unsigned int i=0; i<this->vagasCadeiras.size(); i++){
		for(unsigned int j=0; j<ucs.size(); j++){
			if(vagasCadeiras[i].second->getSigla().compare(ucs[j]->getSigla()) == 0){
				vagasCadeiras[i].first--;
				ucs[j]->assignAlunoTurma(this->turmaID, aluno);
			}
		}
	}
}

vector<Aluno*> Turma::disbandTurma(){
	vector<Aluno*> alunos;
	vector<Aluno*> aux;
	for(unsigned int i=0; i<this->vagasCadeiras.size(); i++){
		aux = this->vagasCadeiras[i].second->apagarTurma(this->turmaID);
		for(unsigned int j=0; j<aux.size(); j++){
			alunos.push_back(aux[j]);
		}
	}
	return alunos;
}

void Turma::saveTurmas(ofstream *output){

}
