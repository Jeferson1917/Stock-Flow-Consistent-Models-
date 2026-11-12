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
B_{s} &= B_{s,t-1} + (G + r_{t-1} \cdot B_{s,t-1}) - (T + r_{t-1} \cdot B_{cb,t-1}) \\ 
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

Além disso, existe uma equação que é verdadeira em todos os períodos:

```math
H_s = H_h
```

Isso porque o dinheiro emitido pelo banco central é utilizado para comprar os títulos remanescentes da dívida pública, e, se são remanescentes, é porque as famílias optaram por não os comprar. Isto é, temos a renda disponível delas, $YD = Y - T + r_{t-1} \cdot B_{h,t-1}$, e esse valor tem três destinos: o consumo, a variação do dinheiro guardado e a variação dos títulos. Logo:

```math
YD = C + \Delta H_h + \Delta B_h
```

Porém, sabemos que houve títulos emitidos pelo governo para cobrir o seu déficit, e que a dívida nova é igual à poupança das famílias (herdando os conceitos já discutidos no modelo SIM). Os títulos que as famílias não compraram ficam com o banco central, que emite exatamente esse valor em dinheiro para comprá-los:

```math
\begin{aligned}
\Delta B_s &= YD - C \quad \text{(dívida nova igual à poupança das famílias)} \\
\Delta B_{cb} &= \Delta B_s - \Delta B_h \quad \text{(o banco central compra o que sobrou)} \\
\Delta H_s &= \Delta B_{cb} \quad \text{(e emite o valor que comprou)} \\
\Rightarrow \Delta H_s &= YD - C - \Delta B_h
\end{aligned}
```

E, da equação da renda disponível, $YD - C - \Delta B_h = \Delta H_h$. Portanto:

```math
\Delta H_s = \Delta H_h
```

Ou seja, a cada período, o dinheiro novo emitido pelo banco central é exatamente igual ao dinheiro novo guardado pelas famílias. Como os dois começam em zero, temos $H_s = H_h$ em todos os períodos. Essa igualdade não é imposta ao modelo: ela é consequência das outras equações, e por isso serve como verificação. Se ela não fechar, alguma das equações está errada.

Agora, tal qual fizemos no SIM, é preciso colocar Y em função dos parâmetros e dos valores do período anterior:

```math
\begin{aligned}
Y &= C + G \\
&= \alpha_1 \cdot YD + \alpha_2 \cdot V_{t-1} + G\\
&= \alpha_1 \cdot ((Y - T + (r_{t-1} \cdot B_{h,t-1}))) + \alpha_2 \cdot V_{t-1} + G \\
&= \alpha_1 \cdot (Y - (\theta(Y + r_{t-1} \cdot B_{h,t-1})) + (r_{t-1} \cdot B_{h,t-1})) + \alpha_2 \cdot V_{t-1} + G  \\
&= \alpha_1 \cdot (Y - ((\theta \cdot Y) + (\theta \cdot r_{t-1} \cdot B_{h,t-1})) + (r_{t-1} \cdot B_{h,t-1})) + \alpha_2 \cdot V_{t-1} + G \\
&= \alpha_1 \cdot Y - \alpha_1 \cdot \theta \cdot Y - \alpha_1 \cdot \theta \cdot r_{t-1} \cdot B_{h,t-1} + \alpha_1 \cdot r_{t-1} \cdot B_{h,t-1} + \alpha_2 \cdot V_{t-1} + G \\
&= Y \cdot (\alpha_1 - \alpha_1 \cdot \theta) - \alpha_1 \cdot \theta \cdot r_{t-1} \cdot B_{h,t-1} + \alpha_1 \cdot r_{t-1} \cdot B_{h,t-1} + \alpha_2 \cdot V_{t-1} + G \\
Y - Y \cdot (\alpha_1 - \alpha_1 \cdot \theta) &= -\alpha_1 \cdot \theta \cdot r_{t-1} \cdot B_{h,t-1} + \alpha_1 \cdot r_{t-1} \cdot B_{h,t-1} + \alpha_2 \cdot V_{t-1} + G \\
Y \cdot (1 - (\alpha_1 - \alpha_1 \cdot \theta))  &= -\alpha_1 \cdot \theta \cdot r_{t-1} \cdot B_{h,t-1} + \alpha_1 \cdot r_{t-1} \cdot B_{h,t-1} + \alpha_2 \cdot V_{t-1} + G \\ 
Y &= \frac{-\alpha_1 \cdot \theta \cdot r_{t-1} \cdot B_{h,t-1} + \alpha_1 \cdot r_{t-1} \cdot B_{h,t-1} + \alpha_2 \cdot V_{t-1} + G }{(1 - (\alpha_1 - \alpha_1 \cdot \theta))} \\
Y &= \frac{\alpha_1 \cdot (1 - \theta) \cdot r_{t-1} \cdot B_{h,t-1} + \alpha_2 \cdot V_{t-1} + G}{1 - \alpha_1 \cdot (1 - \theta)} \quad \text{(desde que } 1 - \alpha_1 \cdot (1 - \theta) \neq 0 \text{)}
\end{aligned} 
```

Notamos que, tal qual no modelo SIM, o multiplicador keynesiano aparece, indicando que, mesmo quando aumentamos a complexidade do modelo macroeconômico, 1 real gasto pelo governo se converte em mais de 1 real de renda.

## Implicações econômicas

Essas equações não representam apenas relações matemáticas: elas também têm implicações econômicas. Quando rodamos o código e analisamos os resultados, chegamos em algumas conclusões importantes.

A primeira delas é entender que as conclusões obtidas no SIM continuam válidas aqui:

1. A dívida de um é ativo de outro: se um setor poupa, outro está necessariamente em déficit (os balanços setoriais de Godley); o dinheiro não surge do nada.
2. Transações dentro de um setor não mudam a riqueza do setor. Só as transações entre setores mudam.
3. O gasto gera renda. A produção é puxada pela demanda, e um real gasto gera mais de um real de renda (o multiplicador).
4. O déficit é endógeno. O governo escolhe o gasto e a alíquota, mas o déficit depende da economia.
5. O paradoxo da poupança. Quando todos tentam poupar mais ao mesmo tempo, a renda cai no curto prazo. Porém, no PC, a renda termina mais alta do que antes, pois a riqueza maior é guardada em parte em títulos, e os juros recebidos aumentam a renda das famílias.

A segunda delas é como as variáveis mudam conforme os laços passam: a renda continua a crescer, isso porque podemos definir a renda como $Y = C + G$. O gasto ainda é fixo, mas o consumo não: ele cresce à medida que as variáveis que o definem crescem, que são a riqueza e a renda disponível.

A riqueza cresce no mesmo valor do déficit governamental. Isso se deve principalmente ao ponto 2 das conclusões prévias: como trocas dentro de um mesmo setor não alteram a riqueza total, a única coisa que a altera são as trocas entre setores. Então, a única possibilidade de alterar a riqueza das famílias vem da sua relação com o governo, calculando o que o governo paga a elas e o que ele cobra:

```math
\begin{aligned}
\Delta V &= G + r_{t-1} \cdot B_{h,t-1} - T \\
&= Y - C + r_{t-1} \cdot B_{h,t-1} - T \quad \text{(substituindo } G = Y - C \text{)} \\
&= YD - C \quad \text{(pois } YD = Y - T + r_{t-1} \cdot B_{h,t-1} \text{)}
\end{aligned}
```
Isso confirma o que usamos na seção da igualdade $H_s = H_h$: a dívida nova emitida pelo governo para cobrir o seu déficit é exatamente igual à poupança das famílias. O que o governo gasta a mais do que arrecada, incluindo os juros pagos às famílias, vai parar nas mãos delas.

A terceira implicação é que, em todos os laços, a riqueza das famílias é igual aos títulos emitidos pelo governo:

```math
\begin{aligned}
V &= H_h + B_h \quad \text{(a riqueza é dinheiro mais títulos)} \\
&= H_s + B_h \quad \text{(o dinheiro das famílias é o dinheiro emitido)} \\
&= B_{cb} + B_h \quad \text{(o banco central emite o valor dos títulos que comprou)} \\
&= B_s \quad \text{(os títulos estão com o banco central ou com as famílias)}
\end{aligned}
```

Ou seja, a riqueza das famílias é sempre igual à dívida do governo (neste modelo).

A quarta implicação é que, tal qual no modelo SIM, a economia fica em "equilíbrio estático" quando o déficit zera, isto é, quando o imposto finalmente iguala o gasto do governo mais os juros que ele paga sobre os títulos. Nesse ponto, a variação da riqueza é zero, o que quer dizer que $YD - C = 0$: as famílias chegaram a um ponto em que estão consumindo toda a renda disponível. E, do outro lado, como não existe mais déficit, não há mais necessidade de o governo emitir novos títulos. Partindo da condição de equilíbrio:

```math
\begin{aligned}
\Delta V = 0 &\Rightarrow T = G + r \cdot B_{h} \\
\theta \cdot (Y + r \cdot B_{h}) &= G + r \cdot B_{h} \\
\theta \cdot Y + \theta \cdot r \cdot B_{h} &= G + r \cdot B_{h} \\
Y &= \frac{G + r \cdot B_{h} - \theta \cdot r \cdot B_h}{\theta} \\
&= \frac{G + r \cdot B_{h} \cdot (1 - \theta)}{\theta}
\end{aligned}
```

No SIM, o equilíbrio era $Y = G/\theta = 100$. No PC, aparece um termo a mais no numerador: os juros recebidos pelas famílias, depois do imposto. Por isso a renda de equilíbrio é maior, chegando a $106{,}49$ com os valores do livro.

A quinta implicação é que, neste modelo, juros mais altos aumentam a renda. Quando a taxa de juros sobe de 0,025 para 0,035 com a economia em equilíbrio, duas coisas acontecem: as famílias passam a receber mais juros pelos títulos que já têm, e passam a querer guardar uma parte maior da riqueza em títulos. Como os juros recebidos fazem parte da renda disponível, o consumo aumenta, e a renda sobe até cerca de $110{,}09$. Pela fórmula do equilíbrio, isso aparece no numerador: tanto $r$ quanto $B_h$ aumentam.

Ou seja, os juros pagos pelo governo funcionam como um gasto que passa pelas famílias que têm títulos. É a mecânica por trás do argumento de que a conta de juros pesa no orçamento público e também injeta renda na economia. Porém, o modelo não tem inflação, câmbio nem empresas que investem, então ele mostra esse mecanismo isolado, e não o efeito dos juros numa economia real, em que juros altos também encarecem o crédito e desestimulam o investimento.

A sexta implicação é sobre o dinheiro: o banco central não o emite a seu bel-prazer. Ele escolhe a taxa de juros e compra todos os títulos que as famílias não querem; portanto, a emissão de moeda depende da vontade da população de comprar títulos ou guardar dinheiro. É o que os pós-keynesianos definem como moeda endógena, em oposição à visão em que o banco central controla diretamente a quantidade de dinheiro e os juros se ajustam.

A sétima implicação é que as famílias podem reorganizar a riqueza sem poupar nada. No primeiro período depois do aumento dos juros, a riqueza praticamente não muda(porque pra calculos de imposto e etc ela utilzia $(r_(h,t-1))$, mas as famílias trocam dinheiro por títulos, porque os títulos passaram a render mais:

| | Antes do aumento | Primeiro período depois |
| --- | --- | --- |
| Riqueza ($V$) | 86,49 | 86,49 |
| Títulos das famílias ($B_h$) | 64,86 | 69,19 |
| Dinheiro das famílias ($H_h$) | 21,62 | 17,30 |

O banco central vende esses títulos às famílias e recolhe esse dinheiro de circulação, então o dinheiro emitido cai na mesma proporção, e a igualdade $H_s = H_h$ continua valendo.