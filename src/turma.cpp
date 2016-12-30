#include "turma.h"

Turma::Turma(string turmaID, string ucID, int v): turmaID(turmaID), ucID(ucID), vagas(v){}

const vector<int>& Turma::getAlunosId() const {
	return alunosID;
}

int Turma::getVagas() const {
	return vagas;
}

void Turma::setVagas(int vagas) {
	this->vagas = vagas;
}

bool Turma::operator <(const Turma &t1) const {
	if(this->vagas < t1.vagas)
		return true;
	else return false;
}

bool Turma::operator ==(const Turma &t1) const {
	if(this->turmaID.compare(t1.turmaID))
		return true;
	else return false;
}

void Turma::saveTurma(ofstream *output){

}
