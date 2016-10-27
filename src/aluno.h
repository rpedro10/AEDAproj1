#include <string>
#include <vector>
#include <iostream>

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
	// Docente tutor
	vector<Uc> cadeiras_inscrito;
public:
	Aluno(int num, string nome, int ano, string data, string email, string estatuto); // falta o vetor de disciplinas e o tutor
};
///////////////////////////////////////
vector<Aluno>GetAllAlunos();