

#include <iostream>
#include <fstream>
#include <string>
#include<vector>

#include "uc.h"

using namespace std;

class Aluno {
	int  numero;
	int ano;
	string nome;
	string data;
	string estatuto;
	string email;
	// Docente* tutor
	vector<Uc *> cadeiras_inscrito;
public:
	Aluno(int num, string nome, int ano, string data, string email, string estatuto); // falta o vetor de disciplinas e o tutor

	int getAno() const;
	void setAno(int ano);
	const vector<Uc*>& getCadeirasInscrito() const;
	void setCadeirasInscrito(const vector<Uc*>& cadeirasInscrito);
	const string& getData() const;
	void setData(const string& data);
	const string& getEmail() const;
	void setEmail(const string& email);
	const string& getEstatuto() const;
	void setEstatuto(const string& estatuto);
	const string& getNome() const;
	void setNome(const string& nome);
	int getNumero() const;
	void setNumero(int numero);
};
///////////////////////////////////////
	vector<Aluno> GetAllAlunos();
