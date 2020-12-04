#ifndef TECLADO_H
#define	TECLADO_H

/// Verifica se um dos bot�es do teclado matricial est� precionado
/// Se um deles estiver, � feito um debound (o testa novamente depois de um atraso)
/// Se ele passar no debounce, ent�o se espera at� o bot�o ser solto, e retorna
/// o numero do bot�o. (Os bot�es '*' e '#' s�o representados por 10 e 12, respectivamente)
/// Caso contr�rio, se retorna 255.
unsigned char tc_tecla();

#endif	