/*
 * Ucs.h
 */


#include <iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;

class Uc {
	string nome;
	string sigla;
	int semestre;
	int ano;
	float creditos;
//	vector<Aluno> inscritos;

public:
	Uc(string nome,string sigla,int semestre,int ano,float creditos);
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
};

class Optativa: public Uc {
	int vagas;
	string curso;
	string faculdade;
	string area;
public:
	Optativa(string nome,string sigla,int semestre,int ano,float cred,int vagas,string curso,string fac,string area);
	const string& getArea() const;
	void setArea(const string& area);
	const string& getCurso() const;
	void setCurso(const string& curso);
	const string& getFaculdade() const;
	void setFaculdade(const string& faculdade);
	int getVagas() const;
	void setVagas(int vagas);
};

class N_Optativa: public Uc {

public:
	N_Optativa(string nome,string sigla,int semestre,int ano,float cred);

};
vector<Uc>GetAllCadeiras();




