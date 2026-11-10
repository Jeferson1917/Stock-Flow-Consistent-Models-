#include <stdio.h>
#include <math.h>
 
// Roda com  gcc -Wall modelo_pc.c -o pc -lm
// ./pc.exe

#define TOLERANCIA 1e-6
 
//função que verifica se PIB esta sendo igual a soma do consumo e dos gastos governamentais
double verifica_renda(double Y, double C, double G){
    return Y-(C+G);
}
 
//função que simula a renda dado os parametros e o gasto governamental inicial
double simula_renda( double A1, double G, double R_ANTERIOR,double BH_ANTERIOR, double THETA, double A2, double V_ANTERIOR){
    return ((A1*R_ANTERIOR*BH_ANTERIOR*(1-THETA)) + G + (A2*V_ANTERIOR))/(1-A1+(A1*THETA));
}
 
//função que sumula o imposto utilizando a alíquota em cima do PIB
double simula_imposto (double Y, double THETA, double R_ANTERIOR, double BH_ANTERIOR){
    return THETA*(Y+(R_ANTERIOR*BH_ANTERIOR));
}
 
//função que simula a renda disponível após o abate do imposto
double simula_renda_disponivel(double Y, double T, double R_ANTERIOR, double BH_ANTERIOR){
    return Y-T+(R_ANTERIOR*BH_ANTERIOR);
}
 
//função que simula o consumo através da propensão de consumir a renda disponivel e o dinheiro em estoque
double simula_consumo (double A1, double YD, double A2,  double V_ANTERIOR){
    return ((A1*YD) + (A2*V_ANTERIOR));
}
 
//função que representa o cálculo do novo estoque baseado em quanto tinha, quanto entrou  e quanto saiu
double simula_estoque (double V_ANTERIOR, double YD, double C){
    return V_ANTERIOR + YD - C;
}
 
//função que verifica se o imposto está sendo calculado corretamente
double imp_arrecada(double T, double Y, double THETA, double R_ANTERIOR, double BH_ANTERIOR){
    return T-(THETA* (Y+(R_ANTERIOR*BH_ANTERIOR)));
}
 
//função que verifica se o imposto esta sendo abatido corretamente do PIB
double ren_disp(double Y,double YD, double T, double R_ANTERIOR, double BH_ANTERIOR){
    return YD - (Y-T+(R_ANTERIOR*BH_ANTERIOR));
}

double verifica_titulos_familia(double BH, double V, double L0, double L1, double L2, double R, double YD){
    return BH - (V*(L0 + L1*R) - L2*YD);
}

double simula_titulos_familia (double V, double L0, double L1, double L2, double R, double YD){
    return V*(L0 + L1*R) - L2*YD;
}

double verifica_dinhiero_familia(double V, double BH, double HH){
    return HH-(V-BH);
}

double simula_dinheiro_familia(double V, double BH){
    return V-BH;
}

double verifica_titulos_emitidos(double BS, double BS_ANTERIOR, double G, double T, double R_ANTERIOR, double BCB_ANTERIOR){
    return BS - (BS_ANTERIOR + (G + R_ANTERIOR*BS_ANTERIOR) - (T + R_ANTERIOR*BCB_ANTERIOR));
}

double simula_titulos_emitidos(double G, double T, double R_ANTERIOR, double BS_ANTERIOR, double BCB_ANTERIOR){
    return BS_ANTERIOR +((G+R_ANTERIOR*BS_ANTERIOR)) - (T + R_ANTERIOR*BCB_ANTERIOR);
}

double verifica_titulos_banco_central(double BCB, double BS, double BH){
    return BCB - (BS-BH);
}

double verifica_dinheiro_emitido(double HS, double HS_ANTERIOR, double BCB, double BCB_ANTERIOR){
    return HS - (HS_ANTERIOR + (BCB - BCB_ANTERIOR));
}

double simula_dinheiro_emitido(double HS_ANTERIOR, double BCB, double BCB_ANTERIOR){
    return HS_ANTERIOR + (BCB - BCB_ANTERIOR);
}

double simula_titulos_banco_central(double BS, double BH){
    return BS-BH;
}
//função que verifica se o consumo esta seguindo sua cartilha
double consumo(double C, double YD, double A1, double V_ANTERIOR, double A2){
    return C-((A1*YD) + (A2*V_ANTERIOR));
}
 
//função que verifica como esta se dando a construção do estoque
double estoque_dinheiro(double V, double V_ANTERIOR, double YD, double C){
    return V-(V_ANTERIOR + YD - C);
}

double verifica_dinheiro (double HH, double HS) {
    return HH-HS;
}

double dinheiroacumula_deficit (double V, double V_ANTERIOR, double G, double T, double R_ANTERIOR, double BH_ANTERIOR){
    return V-(V_ANTERIOR + G - T + (R_ANTERIOR * BH_ANTERIOR));
}

double titulos_riqueza(double V, double V_ANTERIOR, double BS, double BS_ANTERIOR){
    return (BS-BS_ANTERIOR) - (V-V_ANTERIOR);
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
    double Y, C, G, T, YD, V, THETA, A1, A2, L0, L1, L2, R, BH, HH, BS, BCB, HS;
    double V_ANTERIOR = 0;
    double BH_ANTERIOR = 0;
    double BS_ANTERIOR = 0;
    double BCB_ANTERIOR = 0;
    double HS_ANTERIOR = 0;

    printf("=== Parametros ===\n");
    printf("Aliquota de imposto (theta): ");
    scanf("%lf", &THETA);
    printf("Propensao a consumir a renda (alfa1): ");
    scanf("%lf", &A1);
    printf("Propensao a consumir a riqueza (alfa2): ");
    scanf("%lf", &A2);
    printf("Taxa de juros (r): ");
    scanf("%lf", &R);
    double R_ANTERIOR = R;
    printf("Preferencia basica por titulos do governo (lambda0): ");
    scanf("%lf", &L0);
    printf("Quanto os juros aumentam a preferencia por titulos (lambda1): ");
    scanf("%lf", &L1);
    printf("Quanto a renda reduz a preferencia por titulos (lambda2): ");
    scanf("%lf", &L2);

    printf("\n=== Variaveis do periodo ===\n");
    printf("Gasto do governo (G): ");
    scanf("%lf", &G);

    for (int x = 0; x < 100; x++){
        // 1) bloco simultaneo: renda, impostos, renda disponivel e consumo
        Y  = simula_renda(A1, G, R_ANTERIOR, BH_ANTERIOR, THETA, A2, V_ANTERIOR);
        T  = simula_imposto(Y, THETA, R_ANTERIOR, BH_ANTERIOR);
        YD = simula_renda_disponivel(Y, T, R_ANTERIOR, BH_ANTERIOR);
        C  = simula_consumo(A1, YD, A2, V_ANTERIOR);

        // 2) familias: riqueza e escolha de portfolio
        V  = simula_estoque(V_ANTERIOR, YD, C);
        BH = simula_titulos_familia(V, L0, L1, L2, R, YD);
        HH = simula_dinheiro_familia(V, BH);

        // 3) governo e banco central
        BS  = simula_titulos_emitidos(G, T, R_ANTERIOR, BS_ANTERIOR, BCB_ANTERIOR);
        BCB = simula_titulos_banco_central(BS, BH);
        HS  = simula_dinheiro_emitido(HS_ANTERIOR, BCB, BCB_ANTERIOR);

        printf("\nPeriodo %d: Y=%.2f  T=%.2f  YD=%.2f  C=%.2f  V=%.2f  BH=%.2f  HH=%.2f  BS=%.2f  BCB=%.2f  HS=%.2f\n",
               x+1, Y, T, YD, C, V, BH, HH, BS, BCB, HS);

        // 4) verificacoes
        int fecham = 0;
        fecham += checa("Renda", verifica_renda(Y, C, G));
        fecham += checa("Impostos", imp_arrecada(T, Y, THETA, R_ANTERIOR, BH_ANTERIOR));
        fecham += checa("Renda disponivel", ren_disp(Y, YD, T, R_ANTERIOR, BH_ANTERIOR));
        fecham += checa("Consumo", consumo(C, YD, A1, V_ANTERIOR, A2));
        fecham += checa("Riqueza", estoque_dinheiro(V, V_ANTERIOR, YD, C));
        fecham += checa("Titulos familias", verifica_titulos_familia(BH, V, L0, L1, L2, R, YD));
        fecham += checa("Dinheiro familias", verifica_dinhiero_familia(V, BH, HH));
        fecham += checa("Titulos emitidos", verifica_titulos_emitidos(BS, BS_ANTERIOR, G, T, R_ANTERIOR, BCB_ANTERIOR));
        fecham += checa("Titulos BC", verifica_titulos_banco_central(BCB, BS, BH));
        fecham += checa("Dinheiro emitido", verifica_dinheiro_emitido(HS, HS_ANTERIOR, BCB, BCB_ANTERIOR));
        fecham += checa("Riqueza = deficit", dinheiroacumula_deficit(V, V_ANTERIOR, G, T, R_ANTERIOR, BH_ANTERIOR));
        fecham += checa("Divida = riqueza", titulos_riqueza(V, V_ANTERIOR, BS, BS_ANTERIOR));
        fecham += checa("HS = HH", verifica_dinheiro(HH, HS));

        if (fecham == 13)
            printf("O sistema esta BALANCEADO: todas as 13 verificacoes fecham.\n");
        else
            printf("O sistema NAO esta balanceado: %d de 13 verificacoes fecham.\n", fecham);

        // 5) passa os estoques adiante (so depois das verificacoes)
        V_ANTERIOR   = V;
        BH_ANTERIOR  = BH;
        BS_ANTERIOR  = BS;
        BCB_ANTERIOR = BCB;
        HS_ANTERIOR  = HS;
        R_ANTERIOR   = R;
    }

    return 0;
}