#include <stdio.h>
#include <math.h>

// Roda com  gcc -Wall modelo_sim.c -o sim -lm
// ./sim.exe
#define TOLERANCIA 1e-6

//função que verifica se PIB esta sendo igual a soma do consumo e dos gastos governamentais
double eq_renda(double Y, double C, double G){
    return Y-(C+G);
}

//função que simula a renda dado os parametros e o gasto governamental inicial
double simula_renda( double A2, double G, double H_ANTERIOR, double THETA, double A1){
    return (((A2*H_ANTERIOR) + G)/ (1-A1*(1-THETA)));
}

//função que sumula o imposto utilizando a alíquota em cima do PIB
double simula_imposto (double Y, double THETA){
    return Y*THETA;
}

//função que simula a renda disponível após o abate do imposto
double simula_renda_disponivel(double Y, double T){
    return Y-T;
}

//função que simula o consumo através da propensão de consumir a renda disponivel e o dinheiro em estoque
double simula_consumo (double A1, double YD, double A2,  double H_ANTERIOR){
    return ((A1*YD) + (A2*H_ANTERIOR));
}

//função que representa o cálculo do novo estoque baseado em quanto tinha, quanto entrou  e quanto saiu
double simula_estoque (double H_ANTERIOR, double G, double T){
    return H_ANTERIOR + G -T;
}

//função que verifica se o imposto está sendo calculado corretamente
double imp_arrecada(double T, double Y, double THETA){
    return T-(Y*THETA);
}

//função que verifica se o imposto esta sendo abatido corretamente do PIB
double ren_disp(double Y,double YD, double T){
    return YD - (Y-T);
}

//função que verifica se o consumo esta seguindo sua cartilha
double consumo(double C, double YD, double A1, double H_ANTERIOR, double A2){
    return C-((A1*YD) + (A2*H_ANTERIOR));
}

//função que verifica como esta se dando a construção do estoque
double estoque_dinheiro(double H, double H_ANTERIOR, double G, double T){
    return H-(H_ANTERIOR + G -T);
}

//função que analisa o resultado das funções de verificações
int checa(const char *nome, double residuo){
    if (fabs(residuo) < TOLERANCIA) {
        printf("  %-20s OK\n", nome);
        return 1;
    }
    printf("  %-20s NAO fecha (diferenca de %.4f)\n", nome, residuo);
    return 0;
}

int main() {
    double Y,C,G,T,YD,H,THETA, A1, A2;
    double H_ANTERIOR = 0;
    printf("=== Parametros ===\n");
    printf("Aliquota de imposto (theta): ");
    scanf("%lf", &THETA);
    printf("Propensao a consumir a renda (alfa1): ");
    scanf("%lf", &A1);
    printf("Propensao a consumir a riqueza (alfa2): ");
    scanf("%lf", &A2);

    printf("\n=== Variaveis do periodo ===\n");
    printf("Gasto do governo (G): ");
    scanf("%lf", &G);

    for (int x = 0; x < 30; x++){
    Y = simula_renda(A2, G, H_ANTERIOR, THETA, A1);
    T  = simula_imposto(Y, THETA);
    YD = simula_renda_disponivel(Y, T);
    C  = simula_consumo(A1, YD, A2, H_ANTERIOR);
    H  = simula_estoque(H_ANTERIOR, G, T);

    printf("\n=== Verificacao ===\n");
    int fecham = 0;
    fecham += checa("Renda", eq_renda(Y, C, G));
    fecham += checa("Impostos", imp_arrecada(T, Y, THETA));
    fecham += checa("Renda disponivel", ren_disp(Y, YD, T));
    fecham += checa("Consumo", consumo(C, YD, A1, H_ANTERIOR, A2));
    fecham += checa("Dinheiro", estoque_dinheiro(H, H_ANTERIOR, G, T));
   printf("\n");
    if (fecham == 5)
        printf("O sistema esta BALANCEADO: todas as 5 equacoes fecham.\n");
    else
        printf("O sistema NAO esta balanceado: %d de 5 equacoes fecham.\n", fecham);
     H_ANTERIOR = H;
    printf("\nPeriodo %d: Y=%.2f  T=%.2f  YD=%.2f  C=%.2f  H=%.2f\n", x+1, Y, T, YD, C, H);
    }

    return 0;
}