#ifndef TECLADO_H
#define	TECLADO_H

/// Verifica se um dos botões do teclado matricial está precionado
/// Se um deles estiver, é feito um debound (o testa novamente depois de um atraso)
/// Se ele passar no debounce, então se espera até o botão ser solto, e retorna
/// o numero do botão. (Os botões '*' e '#' são representados por 10 e 12, respectivamente)
/// Caso contrário, se retorna 255.
unsigned char tc_tecla();

#endif	