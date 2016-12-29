#ifndef REUNIAO_H
#define REUNIAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * Class Reuniao
 * Classe usada pelo Docente para marcar
 * reunioes com os estudantes.
 *
 * @param data
 * Data da reuniao
 *
 * @param estudanteID
 * ID do estudante que participa na reuniao
 *
 * @param agenda
 * Titulo da Reuniao
 *
 * @param descricao
 * Breve descricao dos topicos da Reuniao
 */
class Reuniao {
	vector<int> data;
	int estudanteID;
	string agenda;
	string descricao;

public:
	/**
	 *  Simples construtor da class Reuniao
	 */
	Reuniao(vector<int> data, int id, string agenda, string desc);

	/**
	 * getter simples
	 * @return Data da Reuniao
	 */
	vector<int> getData() const;

	/**
	 * setter simples
	 * sets Data da Reuniao
	 */
	void setData(const vector<int> data);

	/**
	 * getter simples
	 * @return ID do Estudante
	 */
	int getID() const;

	/**
	 * getter simples
	 * @return Agenda
	 */
	const string& getAgenda() const;

	/**
	 * setter simples
	 * sets Agenda
	 */
	void setAgenda(const string& agenda);

	/**
	 * getter simples
	 * @return Descricao
	 */
	const string& getDescricao() const;

	/**
	 * setter simples
	 * sets Descricao
	 */
	void setDescricao(const string& descricao);

	/**
	 * Compara se duas datas sao iguais
	 */
	bool compareDate(vector<int> data) const;

	/**
	 * Operator < overloading
	 * O termo de comparacao e' agenda
	 */
    bool operator < (const Reuniao &r1) const;

    /**
     * Operator == overloading
     * Compara todos os parametros
     */
    bool operator == (const Reuniao &r1) const;

    /**
     * Imprime alguns detalhes de uma reuniao
     */
    void printReuniaoShort() const;

    /**
     * Imprime todos detalhes de uma reuniao
     */
    void printReuniao() const;
};

#endif
