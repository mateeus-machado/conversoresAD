#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "./includes/adc.h"
#include "./includes/entradas.h"
#include "./includes/leds.h"
#include "./includes/display.h"
#include "./includes/pwm.h"

// Variáveis globais para leituras ADC
uint16_t valor_adc_x;
uint16_t valor_adc_y;

int main() {
    stdio_init_all();
    
    // Inicializa os módulos
    inicializar_pinos();
    inicializar_adc();
    inicializar_pwm();
    inicializar_leds();
    inicializar_display();
    
    while (true) {
        // Leitura do Joystick
        valor_adc_x = ler_adc(1); // Eixo X
        valor_adc_y = ler_adc(0); // Eixo Y
        
        printf("Eixo X: %d | Eixo Y: %d\n", valor_adc_x, valor_adc_y);
        
        // Controle dos LEDs RGB com PWM (LED Azul e Vermelho)
        controlar_leds(valor_adc_x, valor_adc_y);
        
        // Atualiza a posição do quadrado no display, passando o estado da borda
        atualizar_display(valor_adc_x, valor_adc_y, estado_borda);
    }
}