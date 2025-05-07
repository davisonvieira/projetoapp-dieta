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

    // Ajuste baseado no objetivo
    if (objetivo == "1" || objetivo == "emagrecer") {
        tdee -= 500;
    } else if (objetivo == "3" || objetivo == "aumentar") {
        tdee += 500;
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
n
    // Resultados
    cout << "\nSua necessidade calorica estimada e de aproximadamente: " << tdee << " calorias por dia.\n" << endl;
    cout << "Seu IMC e: " << imc << " - " << classificacao << endl;

    // Pergunta sobre cronograma
    string resposta;
    cout << "\nDeseja ajuda em um cronograma alimentar? (sim/nao): ";
    cin >> resposta;

    while (resposta != "sim" && resposta != "nao") {
        cout << "Digite somente 'sim' ou 'nao', por favor: ";
        cin >> resposta;
    }

    if (resposta == "sim") {
        cout << "\nRecomendacao de cronograma vira aqui futuramente!" << endl;
        // Adicionar sugestões de refeições/macros aqui
    } else {
        cout << "Tudo bem! Cuide da sua saude!" << endl;
    }

    return 0;
}
