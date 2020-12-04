#include "config.h"
#include "pic18f4520.h"
#include "lcd.h"
#include "decifrar.h"
#include "delay.h"


/// Faz um atraso de +/- 800ms, enquanto anima um LED do port B
/// descendo e subindo.
void atraso_animado() {
    TRISB = 0x00;
    PORTB = 0b01;
    atraso_ms(200);
    while(PORTB != 0b10000000) {
        PORTB = PORTB << 1;
        atraso_ms(150);
    }
    while(PORTB != 0b00000010) {
        PORTB = PORTB >> 1;
        atraso_ms(150);
    }
    PORTB = 0;
}

void main(void) {
    ADCON1 = 0x06;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;
    
    PORTC |= 0b10; // Desliga o buzzer

    lcd_init();
    
    //Teclado num�rico
    TRISB = 0xF8;
    
    // mostra algumas mensagens de instru��o
    lcd_init();
    lcd_str("Tradutor codigo ");
    lcd_set_cursor(1, 0);
    lcd_str("da batida       ");
    atraso_animado();
    lcd_cmd(L_CLR);
    lcd_str("Entre com numero");
    lcd_set_cursor(1, 0);
    lcd_str("de 1 a 5        ");
    atraso_animado();
    lcd_cmd(L_CLR);
    lcd_str("E aperte '#'   ");
    lcd_set_cursor(1, 0);
    lcd_str("para apagar tudo");
    atraso_animado();
    
    // inicia o decifrador
    decifrar();
}
