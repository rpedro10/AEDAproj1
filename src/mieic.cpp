#include "mieic.h"

#include <stdio.h>
#include <stdlib.h>

Mieic::Mieic(vector<Uc*> cadeiras, vector<Docente*> docentes, vector<Aluno*> alunos){
	this->cadeiras = cadeiras;
	this->docentes = docentes;
	this->alunos = alunos;
}
