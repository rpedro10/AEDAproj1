/*
 * Ucs.h
 */


#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Uc {
	string nome;
	string sigla;
	int semestre;
	int ano;
	float creditos;
//	vector<Aluno> inscritos;

public:
	Uc(int semestre,int ano,int sem);
};

class Optativa: public Uc {
	int vagas;
	string curso;
	string faculdade;
	string area;
public:
	Optativa(string nome,string sigla,int semestre,int ano,float cred,int vagas,string curso,string fac,string area);

};

class N_Optativa: public Uc {

public:
	N_Optativa(string nome,string sigla,int semestre,int ano,float cred);

};




