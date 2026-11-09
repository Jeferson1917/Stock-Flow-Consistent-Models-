# Modelo SIM

O modelo SIM (de *simplest*, o mais simples) é um modelo macroeconômico que busca ser o mais simples possível. Nele só existem o governo e as famílias, e toda a produção da economia é paga às famílias como renda. Conhecendo a alíquota de imposto, a propensão a consumir a renda disponível, a propensão a consumir o estoque de dinheiro e o gasto do governo, conseguimos definir todas as outras variáveis do sistema. Para isso, o modelo usa as seguintes equações.

## Equações

```math
\begin{aligned}
Y &= C + G \\
T &= \theta \cdot Y \\
YD &= Y - T \\
C &= \alpha_1 \cdot YD + \alpha_2 \cdot H_{t-1} \\
H &= H_{t-1} + G - T
\end{aligned}
```

Em que:

| Símbolo | Significado |
| --- | --- |
| $Y$ | PIB (no SIM, igual à renda nacional) |
| $T$ | Impostos |
| $YD$ | Renda disponível |
| $C$ | Consumo |
| $H$ | Estoque de dinheiro das famílias |
| $G$ | Gasto do governo |
| $\theta$ | Alíquota de imposto |
| $\alpha_1$ | Propensão a consumir a renda disponível |
| $\alpha_2$ | Propensão a consumir o estoque de dinheiro |
| $H_{t-1}$ | Estoque de dinheiro do período anterior |

## Forma resolvida e multiplicador keynesiano

Para podermos definir todas as variáveis do sistema, precisamos manipular as equações para que $Y$ fique em função apenas das variáveis inicialmente definidas, logo temos:

```math
\begin{aligned}
Y &= C + G \\
\text{(substituindo C)} &= \alpha_1 \cdot YD + \alpha_2 \cdot H_{t-1} + G \\
\text{(substituindo YD)} &= \alpha_1 \cdot (Y-T) +\alpha_2 \cdot H_{t-1} + G\\
\text{(substituindo T)} &= \alpha_1 \cdot (Y-(\theta \cdot Y)) + \alpha_2 \cdot H_{t-1} + G \\
&= \alpha_1 \cdot Y - \alpha_1 \cdot \theta \cdot Y + \alpha_2 \cdot H_{t-1} + G \Rightarrow \\
Y - \alpha_1 \cdot Y +  \alpha_1 \cdot \theta \cdot Y &= \alpha_2 \cdot H_{t-1} + G \Rightarrow \\
Y(1-\alpha_1 + \alpha_1 \cdot \theta) &= \alpha_2 \cdot H_{t-1} + G \Rightarrow \\
Y &= \frac{\alpha_2 \cdot H_{t-1} + G}{(1-\alpha_1 \cdot (1-\theta))}\quad \text{(desde que } 1 - \alpha_1 \cdot (1 - \theta) \neq 0 \text{)}
\end{aligned} 
```

Essa equação nos diz que $Y$, isto é, a renda da população (o PIB), é determinada pelo gasto do governo mais a propensão a consumir o estoque de dinheiro vezes o estoque do período anterior, tudo isso multiplicado pelo que é conhecido como multiplicador keynesiano, $\frac{1}{1-\alpha_1 \cdot (1-\theta)}$.

Esse multiplicador indica o quanto rende 1 real gasto pelo governo, pois, quando ele gasta 1 real, esse valor vira renda de uma família. Dessa renda será cobrado o imposto, e esse valor vai para o governo, e o restante será usado em consumo ou será guardado. A parte que foi usada no consumo vira renda de outra família, ou seja, parte daquele 1 real gasto se converteu em renda para outra família. A cada rodada dessa, a parte que passa adiante é:

```math
q = \alpha_1 \cdot (1 - \theta)
```

Somando todas as rodadas, temos uma progressão geométrica de razão $q$:

```math
G + G \cdot q + G \cdot q^2 + \dots = \frac{G}{1 - q} = \frac{G}{1 - \alpha_1 \cdot (1 - \theta)}
```

Assim, 1 real gasto pelo governo se converte em mais de 1 real de renda. Como $H_{t-1}$ é conhecido ao fim de cada período, a cada novo período conseguimos calcular $Y$ e, a partir dele, todas as outras variáveis.

Contudo, como o gasto do governo também modifica o estoque monetário das famílias e, consequentemente, seu consumo nos períodos seguintes, os efeitos acumulados sobre a renda podem ser maiores. No equilíbrio de longo prazo do modelo SIM, o multiplicador dos gastos públicos permanentes é dado por $(1/\theta)$.

## Implicações econômicas

Essas equações não representam apenas relações matemáticas: elas também têm implicações econômicas. Quando rodamos o código, percebemos que a renda, o consumo e a renda disponível crescem, porém, à medida que o laço avança, o ritmo em que crescem diminui, até o ponto em que param de crescer (não param propriamente de crescer, mas o ritmo fica tão baixo que praticamente não mudam). Mas o que podemos tirar disso?

Quando analisamos as variáveis à medida que os laços passam, observamos o déficit do governo, definido como $G-T$. O gasto do governo é fixo, já o imposto não: ele é variável e é calculado sobre a renda, $T = \theta \cdot Y$. Ou seja, à medida que a renda cresce, o quanto é tributado aumenta, e com isso o déficit fica cada vez menor. E o que isso implica?

$H$, o estoque de dinheiro, representa todo o dinheiro em estoque das famílias. Logo, esse valor só é alterado por valores relacionados ao governo, pois, se uma família gasta e outra recebe, esses valores se cancelam. Já o governo influencia esse valor, somando o gasto dele e retirando o imposto. Daí vem a fórmula $H = H_{t-1} + G - T$, e já sabemos que $G - T$ é o déficit do governo, ou seja, a poupança das famílias (dinheiro que sobra), que é a renda disponível menos o consumo, é igual ao déficit, e o estoque de dinheiro cresce exatamente nesse valor:

```math
\begin{aligned}
YD &= Y - T \\
\text{(subtraindo C)} \quad YD - C &= Y - T - C \\
\text{(substituindo Y)} &= C + G - T - C \\
&= G - T
\end{aligned}
```
Além disso, como vimos antes, à medida que o tempo passa, $T$ aumenta e $G$ é constante, ou seja, o déficit diminui com o tempo, e por conta disso o quanto o estoque aumenta também diminui. A implicação de tudo isso é que, quando o déficit zera, isto é, quando $G = T$, o estoque de dinheiro para de crescer. E o que isso significa?

Significa que a população não á mais guardando dinheiro, e, se não está guardando, está consumindo, ou seja, chega o ponto em que $YD = C$, as famílias passam a consumir toda a sua renda disponível. Nesse ponto, a economia fica nesse "equilíbrio estático", no qual toda a renda disponível é consumida.

Outra implicação interessante que podemos observar é como a política fiscal determina o nível da economia. Quando o déficit é zerado, temos:

```math
\begin{aligned}
T &= G \quad \text{(déficit zero)} \\
T &= \theta \cdot Y \\
\Rightarrow \theta \cdot Y &= G \\
\Rightarrow Y &= \frac{G}{\theta}
\end{aligned}
```

Ou seja, podemos definir a renda da população como o gasto governamental dividido pela alíquota do imposto. Então o governo define o nível da economia de acordo com quanto pretende gastar e quanto de imposto cobrará, porém, assim, ele não define o déficit, pois, como mostramos anteriormente, esse converge para 0 (no nosso sistema) à medida que a renda cresce, ou seja, o déficit é endógeno.

 **Paradoxo da poupança:** quando as famílias decidem poupar mais, isto é, quando a propensão a consumir a renda disponível ($\alpha_1$) cai, o consumo diminui. Como o consumo de uma família é a renda de outra, a renda de todas cai junto: no nosso modelo, ao reduzir $\alpha_1$ de 0,6 para 0,5, a renda cai de 100 para 86,67 logo no primeiro período. Com a renda menor, a arrecadação também cai e o governo volta a ter déficit, e é justamente esse déficit que permite às famílias acumular mais dinheiro: o estoque sobe de 80 para 100. No fim, a renda volta a 100, pois o equilíbrio $Y = \frac{G}{\theta}$ não depende de $\alpha_1$. Ou seja, quando todos tentam poupar mais ao mesmo tempo, a renda cai, e as famílias só conseguem guardar mais porque o governo teve déficit no caminho.
## Conclusão

É importante ressaltar que esse modelo É extremamente limitado: ele não contém uma série de fatores, que na realidade, temos, títulos da divida pública, juros, importação, exportação, câmbio e etc.

Mesmo assim, existem fatores importantes que podemos absorver do nosso modelo, os quais podemos generalizar:

1 - A dívida de um, é ativo de outro: Se um setor poupa, outro está necessariamente em déficit (os balanços setoriais de Godley), o dinheiro não surge do nada

2 - Transações dentro de um setor não mudam a riqueza do setor. Só as transações entre setores mudam.

3 - O gasto gera renda. A produção é puxada pela demanda, e um real gasto gera mais de um real de renda (o multiplicador).

4- O déficit é endógeno. O governo escolhe o gasto e a alíquota, mas o déficit depende da economia.

5 - O paradoxo da poupança. Quando todos tentam poupar mais ao mesmo tempo, a renda cai.