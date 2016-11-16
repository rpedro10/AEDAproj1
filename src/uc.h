#ifndef __uc_h__
#define __uc_h__
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

class Aluno;

class Uc {
protected:
	string nome;
	string sigla;
	int semestre;
	int ano;
	float creditos;
	vector<Aluno*> alunos;

public:
	Uc(string nome,string sigla,int semestre,int ano,float creditos);
	virtual ~Uc(){};
	int getAno() const;
	void setAno(int ano);
	float getCreditos() const;
	void setCreditos(float creditos);
	const string& getNome() const;
	void setNome(const string& nome);
	int getSemestre() const;
	void setSemestre(int semestre);
	const string& getSigla() const;
	void setSigla(const string& sigla);
	vector<Aluno*> getAlunos() const;
	void setAlunos(vector<Aluno*> alunos);

	virtual int addAluno(Aluno* aluno) = 0;
	virtual void displayUC()=0;

	//virtual int getVagas();
	//virtual void setVagas(int vagas);

	//virtual void display_incomplete(int ano);
};

class Optativa: public Uc {
	int vagas;
	string curso;
	string faculdade;
	string area;
public:
	Optativa(string nome,string sigla,int semestre,int ano,float cred,int vagas,string curso,string fac,string area);
	~Optativa(){};
	const string& getArea() const;
	void setArea(const string& area);
	const string& getCurso() const;
	void setCurso(const string& curso);
	const string& getFaculdade() const;
	void setFaculdade(const string& faculdade);
	int getVagas() const;
	void setVagas(int vagas);
	void displayUC();
	int addAluno(Aluno* aluno);
	//void display_incomplete(int ano);


};

class N_Optativa: public Uc {

public:
	N_Optativa(string nome,string sigla,int semestre,int ano,float cred);
	~N_Optativa(){};
	void displayUC();
	int addAluno(Aluno* aluno);

	//void display_incomplete(int year);


};

vector<Uc*> initUCs();

#endif


