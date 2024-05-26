#include <iostream> //Biblioteca principal para saída e entrada de dados
#include <string>   //Biblioteca Manipulção de textos
#include <cstdlib>  //Biblioteca para funções relacionadas ao sistema
#include <vector>   //Biblioteca para utilização de vetores
#include <iomanip>
using namespace std;

bool isUserLogged = false; // Variável Booleana para verificar se o usuário está Logado
const double valor_nosso_app = 35;
// Custos por programador
const double programador_senior = 100;
const double programador_pleno = 60;
const double programador_back_end = 40;
const double programador_front_end = 40;

// Tempo de desenvolvimento
const int dias_semana = 5; // 5x8 = 40
const int horas_trabalhadas_diariamente = 8;
const int semanas_totais_trabalhadas = 12; // 40x24 =960 horas trabalhadas

// Cálculos Custos
double calculo_custos_programadores = (programador_senior + programador_pleno + programador_front_end + programador_back_end); // Soma do salário de todos os programadores = 240
double calculo_horas_trabalhadas = (dias_semana * horas_trabalhadas_diariamente);                                              // 40 horas trabalhadas
double calculo_horas_semanas = (calculo_horas_trabalhadas * semanas_totais_trabalhadas);                                       // 960 horas trabalhadas

// Cálculo Final Desenvolvimento
double horas_vezes_custo_programadores = (calculo_custos_programadores * calculo_horas_semanas);
// Caso haja novo cadastro de custo no sistema
double valor_soma_total = 0;


struct Despesa // Estrutura struct para armazenar valores das despesas
{
    string data;
    double valor;
    string categoria;
    string descricao;
    string metodo_pagamento;
    int pagantes;
};



void registrarDespesa(vector<Despesa> &despesas)
{
    Despesa novaDespesa;
    system("cls");
    cout << "Registrar Nova Custo" << endl;
    cout << "-----------------------" << endl;

    cout << "Valor: ";
    cin >> novaDespesa.valor;
    cin.ignore(); // Ignorar o restante da linha após a leitura do valor

    cout << "Descricao: ";
    getline(cin, novaDespesa.descricao);

    despesas.push_back(novaDespesa);
    system("cls");
    cout << "Custo registrada com sucesso!" << endl;
}
void listarCustos(const vector<Despesa> &despesas)
{

    system("cls");
    cout << "Custo com o Software:" << endl;
    cout << "-----------------" << endl;
    cout << "Licenca: " << endl;                                              // colocar valor da licenca do software
    cout << "Desenvolvimento: R$" << horas_vezes_custo_programadores << endl; // valor do desenvolvimento
    cout << "Manutencao: " << endl;                                           // Valor do desenvolvimento
    cout << "Suporte tecnico: " << endl;                                      // valor do suporte mensal
    cout << "Treinamento do sistema: " << endl;                               // valor do treinamento do sistema
    cout << "Total dos Custos: " << endl;                                     // valor total dos custos
    cout << "-----------------" << endl;

    for (const auto &despesa : despesas)
    {
        cout << "Valor: " << despesa.valor << endl;
        cout << "Descricao: " << despesa.descricao << endl;
        cout << "-----------------" << endl;
    }
}
void calcular_nossos_custos(vector<Despesa> &despesas)
{
    Despesa quantidade;
    system("cls");
    cout << "Insira a quantidade de pagantes: " << endl;
    cin >> quantidade.pagantes;

    double valor_soma_total = horas_vezes_custo_programadores;
    for (const auto &despesa : despesas)
    {
        valor_soma_total += despesa.valor;
    }
    cout << valor_soma_total << endl;
    double preco_usuario_pagante = (valor_soma_total / quantidade.pagantes); // Calcular o Preço por Usuário Pagante
    double vendas_necessarias = (valor_soma_total / valor_nosso_app);        // Número de vendas necesárias
    cout << setprecision(2) << fixed << preco_usuario_pagante << " reais de custo por assinante " << endl;
    cout << setprecision(0) << fixed << vendas_necessarias << " oque eu preciso" << endl;

    if (quantidade.pagantes < vendas_necessarias)
    {
        double vendas_faltantes = (vendas_necessarias - quantidade.pagantes);
        cout << "Faltam " << vendas_faltantes << " Vendas ate o ponto de equilibrio" << endl;
    }
    else if (quantidade.pagantes > vendas_necessarias)
    {
        float porcentagem_lucro = ((quantidade.pagantes / vendas_necessarias) * 100);
        cout << "parabens voce passou o ponto de equilibrio e arrecadou " << porcentagem_lucro << "%" << " de lucro" << endl;
    }
    else if (quantidade.pagantes == vendas_necessarias)
    {
        cout << "voce chegou no ponto de equilibrio";
    }
}

int main() // Função Principal
{
    
    vector<Despesa> despesas; // Declaração de um vetor para armazenar múlitplas despesas
    system("cls");
    int opcao;
    do
    {
        cout << "Sistema de Registro de Custos" << endl;
        cout << "1. Registrar Novo Custo" << endl;
        cout << "2. Listar custos" << endl;
        cout << "3. Calcular Percentual de Lucro" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(); // Ignorar o restante da linha após a leitura da opção

        switch (opcao)
        {
        case 1:
            registrarDespesa(despesas);
            break;
        case 2:
            listarCustos(despesas);
            break;
        case 3:
            calcular_nossos_custos(despesas);
            break;
        case 4:
            cout << "Saindo do sistema..." << endl;
            break;
        default:
            cout << "Opcaoo invalida. Tente novamente." << endl;
        }
    } while (opcao != 4);

    if (opcao == 4)
    {
        exit(0);
    }

    registrarDespesa(despesas);
    listarCustos(despesas);
    calcular_nossos_custos(despesas);

    return 0;
}