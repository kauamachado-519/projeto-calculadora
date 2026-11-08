
#include <stdio.h>
#include <ctype.h>

int main(void) {

    int opcao;
    double num1, num2, resultado;
    char resposta;
    char operador;
    char entrada[100];
    char extra;

    while (1) {

        // Menu inicial
        printf("===============================\n");
        printf("   Calculadora Simples\n");
        printf("===============================\n");
        printf("Selecione uma operacao:\n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("5. Sair\n");
        printf("Opcao: ");

        // Leitura completa e validacao da opcao
        if (scanf("%99s", entrada) != 1) {
            continue;
        }

        if (sscanf(entrada, "%d%c", &opcao, &extra) != 1 ||
            opcao < 1 || opcao > 5) {

            printf("Opcao invalida! Digite um numero inteiro entre 1 e 5.\n");
            continue;
        }

        // Opcao para sair
        if (opcao == 5) {
            printf("Obrigado por usar a calculadora! Ate a proxima.\n");
            break;
        }

        // Entrada do primeiro numero
        printf("Digite o primeiro numero: ");

        if (scanf("%lf", &num1) != 1) {
            printf("Entrada invalida! Digite um numero valido.\n");

            while (getchar() != '\n');

            continue;
        }

        // Entrada do segundo numero
        printf("Digite o segundo numero: ");

        if (scanf("%lf", &num2) != 1) {
            printf("Entrada invalida! Digite um numero valido.\n");

            while (getchar() != '\n');

            continue;
        }

        // Operacoes matematicas
        switch (opcao) {

            case 1:
                resultado = num1 + num2;
                operador = '+';
                break;

            case 2:
                resultado = num1 - num2;
                operador = '-';
                break;

            case 3:
                resultado = num1 * num2;
                operador = '*';
                break;

            case 4:
                if (num2 == 0) {
                    printf("Erro: Divisao por zero nao e permitida.\n");
                    break;
                }

                resultado = num1 / num2;
                operador = '/';
                break;
        }

        // Exibicao do resultado
        if (opcao != 4 || num2 != 0) {
            printf("Resultado: %g %c %g = %g\n",
                   num1, operador, num2, resultado);
        }

        // Pergunta se deseja realizar outra operacao
        while (1) {

            printf("Deseja realizar outra operacao? (s/n): ");

            if (scanf(" %c", &resposta) != 1) {
                continue;
            }

            resposta = tolower((unsigned char)resposta);

            if (resposta == 's') {
                break;
            }

            else if (resposta == 'n') {
                printf("Obrigado por usar a calculadora! Ate a proxima.\n");
                return 0;
            }

            else {
                printf("Resposta invalida. Por favor, digite 's' para sim ou 'n' para nao.\n");
            }
        }
    }

    return 0;
}
