#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Docente {
	int codigo;
	string nome;
	
	//	vector<Aluno> inscritos;
	
public:
	Docente(int cod, string nome);
	int getCodigo() const;
	void setCodigo(int codigo);
	const string& getNome() const;
	void setNome(const string& nome);
};

vector<Docente>GetAllDocentes();
