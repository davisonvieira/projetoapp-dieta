#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    float peso, altura;
    int idade, frequencia;
    string objetivo, sexo;

    cout << "Digite seu peso (kg): ";
    cin >> peso;

    cout << "Digite sua altura (cm): ";
    cin >> altura;

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "Digite seu sexo (1.masculino / 2.feminino): ";
    cin >> sexo;

    cout << "Quantos dias por semana voce faz atividade fisica? (0-7): ";
    cin >> frequencia;

    cout << "Qual seu objetivo? (1.emagrecer / 2.manter / 3.aumentar): ";
    cin >> objetivo;

    // Calcula TMB com base no sexo
    float tmb;
    if (sexo == "masculino" || sexo == "1") {
        tmb = 10 * peso + 6.25 * altura - 5 * idade + 5;
    } else if (sexo == "feminino" || sexo == "2") {
        tmb = 10 * peso + 6.25 * altura - 5 * idade - 161;
    } else {
        cout << "Sexo invalido. Use '1' ou '2'." << endl;
        return 1;
    }

    // Fator de atividade física
    float fator;
    if (frequencia <= 1)
        fator = 1.2;
    else if (frequencia <= 3)
        fator = 1.375;
    else if (frequencia <= 5)
        fator = 1.55;
    else
        fator = 1.725;

    // Gasto calórico diário total (TDEE)
    float tdee = tmb * fator;

    // Déficit para emagrecimento
    float calorias_dia = tdee;

    if (objetivo == "1" || objetivo == "emagrecer") {
        string intensidade;
        cout << "\nQual a intensidade desejada para emagrecimento?" << endl;
        cout << "1. Leve (250 kcal/dia)\n2. Moderado (500 kcal/dia)\n3. Agressivo (750 kcal/dia)" << endl;
        cout << "Escolha (1/2/3): ";
        cin >> intensidade;

        int deficit = 0;
        if (intensidade == "1")
            deficit = 250;
        else if (intensidade == "2")
            deficit = 500;
        else if (intensidade == "3")
            deficit = 750;
        else {
            cout << "Intensidade invalida. Encerrando programa." << endl;
            return 1;
        }

        calorias_dia = tdee - deficit;

        cout << "\nSeu gasto calórico total (TDEE) é: " << tdee << " kcal/dia." << endl;
        cout << "Com um déficit de " << deficit << " kcal, você deverá consumir: " << calorias_dia << " kcal/dia." << endl;
    } else if (objetivo == "3" || objetivo == "aumentar") {
        calorias_dia += 500;
    } else if (objetivo != "2" && objetivo != "manter") {
        cout << "Objetivo invalido. Use 1, 2 ou 3." << endl;
        return 1;
    }

    // Cálculo do IMC
    float altura_m = altura / 100.0;
    float imc = peso / pow(altura_m, 2);

    string classificacao;
    if (imc < 18.5)
        classificacao = "Abaixo do peso";
    else if (imc < 25)
        classificacao = "Peso normal";
    else if (imc < 30)
        classificacao = "Sobrepeso";
    else if (imc < 35)
        classificacao = "Obesidade grau 1";
    else if (imc < 40)
        classificacao = "Obesidade grau 2";
    else
        classificacao = "Obesidade grau 3";

    // Resultados
    cout << "\nSeu IMC é: " << imc << " - " << classificacao << endl;
    cout << "Calorias diárias recomendadas com base no objetivo: " << calorias_dia << " kcal/dia." << endl;

    // Pergunta sobre cronograma
    string resposta;
    cout << "\nDeseja ajuda em um cronograma alimentar? (sim/nao): ";
    cin >> resposta;

    while (resposta != "sim" && resposta != "nao") {
        cout << "Digite somente 'sim' ou 'nao', por favor: ";
        cin >> resposta;
    }

    if (resposta == "sim") {
        cout << "\nRecomendacao de cronograma virá aqui futuramente!" << endl;
    } else {
        cout << "\nTudo bem! Cuide da sua saude!" << endl;
    }

    return 0;
}
