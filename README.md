Isso é um programa destinado a rodar em uma placa PICGenios - PIC18F4520,
que é capaz de converter número codificados no Código da Batida, nas letras
correspondentes.

## Compilando

O progama foi feito para ser compilado usando o compilador XC8.
O programa pode ser compilado executando o arquivo ```build.cmd```.

# O Código da Batida

O código da batida é um jeito de criptografar mensagens letra a letra de uma maneira bastante simples, usando uma sequência de batidas que vão se traduzir em coordenadas. Já foi usado por prisioneiros que se comunicavam através de batidas nas grades das celas, por exemplo.

A parte mais fundamental do código da batida, é um quadrado de polybius, que basicamente é uma tabela 5x5, preenchida por letras, de modo que cada letra pode ser representado por dois números de 1 a 5:


|   | 1 | 2 |  3  | 4 | 5 |
|---|:-:|:-:|:---:|:-:|:-:|
| 1 | A | B | C/K | D | E |
| 2 | F | G |  H  | I | J |
| 3 | L | M |  N  | O | P |
| 4 | Q | R |  S  | T | U |
| 5 | V | W |  X  | Y | Z |

Como existem 26 letra, mas apenas 25 posições no quadrado, um par de letras terá a mesma posição. No meu caso, como C e K têm sons parecidos, e K não é muito utilizado em português, ambas as letras são representadas pela mesma posição.

Logo para codificar uma letra, basta convertê-la para um par de números. Em seguida, para transmitir esses números, basta fazer barulhos de batida. Por exemplo, para codificar a letra M você a converte para 3, 2 (linha 3, coluna 2), e a transmite batendo 3 vezes, esperando um pouco e batendo mais 2 vezes.

Por exemplo a mensagem:

41451114421114341415353431241254344543

seria traduzida em:

QUADRADODEPOLIBYOUS