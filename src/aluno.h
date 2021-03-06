#ifndef __aluno_h__
#define __aluno_h__
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "uc.h"
#include "docente.h"

/**
 * Estado da matricula
 */
 enum Estado { decorrer, terminou, interrompeu };


using namespace std;

class Aluno {
	int numero;
	int ano;
	string nome;
	string estatuto;
	string email;
	string morada;

	Estado estado;

	const Docente* tutor;
	vector< pair<string, Uc *> > cadeiras_inscrito;
	vector< pair<string, Uc *> > cadeiras_completadas;
public:
	Aluno(int num, string nome, int ano, string email, string estatuto, Docente* tutor, vector< pair<string, Uc *> > cadeiras_inscrito, vector< pair<string, Uc *> > cadeiras_completadas); // falta o vetor de disciplinas e o tutor
	Aluno();
	//~Aluno();
	int getAno() const;
	void setAno(int ano);

	const string& getEmail() const;
	void setEmail(const string& email);
	const string& getEstatuto() const;
	void setEstatuto(const string& estatuto);
	const string& getNome() const;
	void setNome(const string& nome);
	int getNumero() const;
	void setNumero(int numero);
	const Docente* getTutor() const;
	//Estado getEstado();
	//void setEstado(Estado estado);

	vector< pair<string, Uc *> > getCadeirasInscrito() const;
	void setCadeirasInscrito(vector< pair<string, Uc *> > cadeirasInscrito);

	vector< pair<string, Uc *> > getCadeirasCompletadas() const;
	void setCadeirasCompletadas(vector< pair<string, Uc *> > cadeirasCompletadas);

	void displayAlunoInfo();
	void displayAluno();

	void inscreverCadeira(Uc *uc);
	bool estaInscrito(Uc* uc);
	bool completou(Uc* uc);
	void save(ofstream* output);

	bool operator == (const Aluno* & p2) const;

	void terminarAno();

	vector<Uc*> getUCsAnoBase(int semestre);
	Estado getEstado() const;
	void setEstado(Estado estado);
	const string& getMorada() const;
	void setMorada(const string& morada);
	unsigned int getUCsSemestre(int semestre);
};


//__________________________________________________________

vector<Aluno*> initAlunos(vector <Docente*> docentes, vector<Uc*> ucs);

#endif
