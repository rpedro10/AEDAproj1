#include "reuniao.h"

Reuniao::Reuniao(vector<int> data, int id, string agenda, string desc){
	this->data = data;
	this->estudanteID = id;
	this->agenda = agenda;
	this->descricao = desc;
}

vector<int> Reuniao::getData() const{
	return this->data;
}

void Reuniao::setData(const vector<int> data){
	this->data = data;
}

int Reuniao::getID() const{
	return this->estudanteID;
}

const string& Reuniao::getAgenda() const{
	return this->agenda;
}

void Reuniao::setAgenda(const string& agenda){
	this->agenda = agenda;
}

const string& Reuniao::getDescricao() const{
	return this->descricao;
}

void Reuniao::setDescricao(const string& descricao){
	this->descricao = descricao;
}

bool Reuniao::compareDate(vector<int> data) const{
	if(this->data[0] == data[0] && this->data[1] == data[1] && this->data[2] == data[2])
		return true;
	else return false;
}

bool Reuniao::operator < (const Reuniao &r1) const{
	if(this->data[2] < r1.data[2])
		return true;
	else if(this->data[2] == r1.data[2]){
		if(this->data[1] < r1.data[1])
			return true;
		else if(this->data[1] == r1.data[1]){
			if(this->data[0] < r1.data[0])
				return true;
		}
	}
	return false;
}

bool Reuniao::operator == (const Reuniao &r1) const{
	if(this->data[0] == r1.data[0] &&
			this->data[1] == r1.data[1] &&
			this->data[2] == r1.data[2] &&
			this->estudanteID == r1.estudanteID &&
			this->agenda.compare(r1.agenda) == 0 &&
			this->descricao.compare(r1.descricao) == 0)
		return true;
	else return false;
}

void Reuniao::printReuniaoShort() const{
	cout << this->data[0] << "/" << this->data[1] << "/" << this->data[2] << "	";
	cout << this->estudanteID << "	" << this->agenda << endl;
}

void Reuniao::printReuniao() const{
	cout << "Dia			Estudante	" << endl;
	cout << this->data[0] << "/" << this->data[1] << "/" << this->data[2] << "		";
	cout << this->estudanteID<< endl;
	cout << "Agenda: " << this->agenda << "	" << endl;
	cout << "Descritivo: " << this->descricao << endl;
	cout << "====================================================================" << endl;
}
