#include <stdio.h>
#include <string.h>
#include <windows.h>

//definição para quantidades de filmes
#define qtd_filmes 4

//Definição para cores

#define ANSI_COLOR_RED_BG     "\x1b[41m"
#define ANSI_COLOR_GREEN_BG   "\x1b[42m"
#define ANSI_COLOR_YELLOW_BG  "\x1b[43m"
#define ANSI_COLOR_BLUE_BG    "\x1b[44m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(){

    SetConsoleOutputCP(65001);
    //Variaveis
    int ingressos[qtd_filmes];
    char filmes[qtd_filmes][30]= {
        "Only Up",
        "Homem Aranha",
        "Caça as Bruxas",
        "Pânico na Floresta"
    };

    int i, total=0, maisVendido=0, menosVendido=0;

    const char *cores_bg[qtd_filmes]={

        ANSI_COLOR_BLUE_BG,
        ANSI_COLOR_GREEN_BG,
        ANSI_COLOR_RED_BG,
        ANSI_COLOR_YELLOW_BG

    };

    printf("\t\tCINEMARK\n");
    printf("\n\t Controle de Vendas\n");
    printf("\nDigite a quantidade de ingressos vendidos para cada filme\n");

    for(i=0; i< qtd_filmes; i++){

        printf("\n%s:", filmes[i]);
        scanf("%d", &ingressos[i]);
        total += ingressos[i];

    }
    
    for(i=1; i < qtd_filmes; i++){

        if(ingressos[i] > ingressos[maisVendido]){
            maisVendido = i;
        }
        if(ingressos[i] < ingressos[menosVendido]){
            menosVendido = i;
        }
    }


    printf("\n\t\tRelátorio Mensal\n");
    printf("Total de ingressos Vendidos no mês: %d\n", total);
    printf("Filme mais assistido: %s(%d ingressos)\n", filmes[maisVendido],ingressos[maisVendido]);
    printf("Filme menos assistido:%s(%d ingressos)\n", filmes[menosVendido],ingressos[menosVendido]);


    printf("\n\t\tGráfico de vendas\n");
    printf("cor a cada de 50 ingressos\n");

    for(i=0; i< qtd_filmes; i++){
        printf("%-20s |",filmes[i]);

        printf("%s", cores_bg[i]);
        for(int j = 0; j < ingressos[i]/ 50; j++){
            printf(" ");
        }

        printf("%s", ANSI_COLOR_RESET);
        printf("(%d)\n", ingressos[i]);
    }

    return 0;
}