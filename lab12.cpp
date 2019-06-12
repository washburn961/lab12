/*
Nome: Gabriel Bortoletto Molz
Matricula: 2019003459
Data: 11/06/19
Turma: 03
Laboratório 11
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

struct Aluno
{
    string nome, situacao;
    int matricula, faltas;
    float nota1, nota2, nota3, media;
};

float media_aluno(float n1, float n2, float n3)
{
    return ((n1+n2+n3)/3);
}

string situacao_aluno(float media, int faltas)
{
    if (media>=6 && faltas<=10)
    {
        return ("Aprovado");
    }
    else return ("Reprovado");
}

Aluno le_dado()
{using namespace std;
    Aluno dado;

    cin.ignore();
    cout << "Entre com nome: ";
    getline(cin, dado.nome);
    cout << "Entre com matrícula: ";
    cin >> dado.matricula;
    cout << "Entre com nota1, nota2, nota3: ";
    cin >> dado.nota1 >> dado.nota2 >> dado.nota3;
    cout << "Entre com o número de faltas: ";
    cin >> dado.faltas;

    return (dado);
}

void obtem_dados(vector <Aluno> &dados)
{
    Aluno dado;
    char temp;
    bool continua(1);

    while (continua)
    {
        cout << "Digite x para encerrar, qualquer tecla para continuar: ";
        cin >> temp;
        if (temp!='x')
        {
            dado = le_dado();
            dados.push_back(dado);
        }
        else continua = 0;
    }
}

void imprime_dados(vector <Aluno> &dados)
{
    cout << endl;

    for (int i=0; i<dados.size(); i++)
    {
        dados[i].media = media_aluno(dados[i].nota1, dados[i].nota2, dados[i].nota3);
        dados[i].situacao = situacao_aluno(dados[i].media, dados[i].faltas);

        cout << "Dado do aluno(a): " << endl << endl;
        cout << "Nome: " << dados[i].nome << endl << endl;
        cout << "Matrícula: " << dados[i].matricula << endl << endl;
        cout << "Faltas: " << dados[i].faltas << endl << endl;
        cout << "Média: " << setprecision(3) << dados[i].media << endl << endl;
        cout << "Situação: " << dados[i].situacao << endl << endl;
    }
}

void grava_dados(vector <Aluno> dados)
{
    ofstream arquivo;
    arquivo.open(" "); //indicar arquivo.

    for (int i=0; i<dados.size(); i++)
    {
        arquivo << "Dado do aluno(a): " << endl;
        arquivo << "Nome: " << dados[i].nome << endl;
        arquivo << "Matrícula: " << dados[i].matricula << endl;
        arquivo << "Média: " << setprecision(3) << dados[i].media << endl;
        arquivo << "Situação: " << dados[i].situacao << endl;
    }

    arquivo.close();
}

int main()
{
    vector <Aluno> dados;

    obtem_dados(dados);
    imprime_dados(dados);
    grava_dados(dados);

    return 0;
}
