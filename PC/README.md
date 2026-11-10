# Modelo PC

O modelo PC (de *Portfolio Choice*, escolha de portfólio) é um modelo macroeconômico que herda as características do modelo SIM, porém agrega a ele um novo ente: o banco central. Este tem a capacidade de fazer emissão monetária para comprar os títulos da dívida pública, que consistem em promessas do governo de pagamento posterior acrescido de uma taxa de juros, definida pelo banco central. O governo emite esses títulos com a intenção de cobrir o seu déficit, e eles são oferecidos às famílias.

As famílias, assim como no SIM, decidem quanto da renda disponível vão consumir e quanto vão guardar. A novidade é que agora elas também decidem em que forma guardar a sua riqueza: em dinheiro, que não rende nada, ou em títulos, que pagam juros. É essa escolha de portfólio que dá nome ao modelo, e ela vale para toda a riqueza acumulada, não apenas para o que foi poupado no período. Os juros recebidos pelos títulos passam a fazer parte da renda das famílias. Já os títulos restantes, que as famílias não quiseram comprar, são comprados pelo banco central.

Antes de entrarmos propriamente nas implicações do sistema, é importante entendermos as equações que o definem:

```math
\begin{aligned}
Y &= C + G \\
T &= \theta \cdot (Y + r_{t-1} \cdot B_{h,t-1}) \\
YD &= Y - T + r_{t-1} \cdot B_{h,t-1} \\
C &= \alpha_1 \cdot YD + \alpha_2 \cdot V_{t-1} \\
V &= V_{t-1} + (YD - C) \\
B_{h} &= V \cdot (\lambda_0 + \lambda_1 \cdot r) - \lambda_2 \cdot YD \\
H_{h} &= V - B_{h} \\
B_{s} &= B_{s, t-1} + (G + r_{t-1} \cdot B_{h, t-1}) - (T + r_{t-1} \cdot B_{cb,t-1}) \\
B_{cb} &= B_{s} - B_{h} \\
H_{s} &= H_{s,t-1} + (B_{cb} - B_{cb, t-1}) \\
r &= \bar{r}
\end{aligned}
``` 

| Símbolo | Significado |
| --- | --- |
| $Y$ | PIB (renda nacional) |
| $T$ | Impostos |
| $YD$ | Renda disponível das famílias |
| $C$ | Consumo das famílias |
| $V$ | Riqueza total das famílias (dinheiro e títulos) |
| $B_h$ | Títulos da dívida pública que estão com as famílias |
| $H_h$ | Dinheiro que as famílias guardam |
| $B_s$ | Títulos emitidos pelo governo (dívida pública total) |
| $B_{cb}$ | Títulos da dívida pública que estão com o banco central |
| $H_s$ | Dinheiro emitido pelo banco central |
| $G$ | Gasto do governo |
| $r$ | Taxa de juros dos títulos |
| $\bar{r}$ | Taxa de juros definida pelo banco central |
| $\theta$ | Alíquota de imposto |
| $\alpha_1$ | Propensão a consumir a renda disponível |
| $\alpha_2$ | Propensão a consumir a riqueza |
| $\lambda_0$ | Preferência básica das famílias por títulos |
| $\lambda_1$ | Quanto os juros aumentam a preferência por títulos |
| $\lambda_2$ | Quanto a renda disponível reduz a preferência por títulos |
| $X_{t-1}$ | Valor da variável $X$ no período anterior |