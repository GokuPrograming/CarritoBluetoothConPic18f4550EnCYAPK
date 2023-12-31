#include <18F4550.h> // Para PIC18F4550 cambiar por: #include <18F4550.h>
#use delay( clock=20Mhz, crystal ) // Tipo de oscilador y frecuencia dependiendo del microcontrolador
#build( reset=0x02000, interrupt=0x02008 ) // Asigna los vectores de reset e interrupci�n para la versi�n con bootloader
#org 0x0000,0x1FFF {} // Reserva espacio en memoria para el bootloader

//-------------------------------------------------------------------------------
#USE RS232( stream=SERIE, BAUD=9600, PARITY=N, XMIT=PIN_C6, RCV=PIN_C7, BITS=8)

#define LED pin_A4
#define Boton pin_A2
#use fast_io(b)
#use fast_io(d)

void main(void) {
   set_tris_b(0x00); // Configura el puerto B como salida
   set_tris_d(0xFF); // Configura el puerto D como entrada
   
   output_low(pin_b0); // Apaga el LED RB0
   output_low(pin_b1); // Apaga el LED RB1
   output_low(pin_b2); // Apaga el LED RB2
   output_low(pin_b3); // Apaga el LED RB3
   
   while (true) { // Bucle infinito
      if (kbhit()) { // Pregunta si hay algun dato recibido
         char Caracter = getc(); // Guarda el caracter
         switch (Caracter) { // Compara el caracter con los casos posibles
            case '1': // Si el caracter es 1
               output_high(pin_b0); // Enciende el LED RB0
               output_high(pin_b1); // Enciende el LED RB1
               output_high(pin_b2); // Enciende el LED RB2
               output_high(pin_b3); // Enciende el LED RB3
               break; // Sale del switch
            case '2': // Si el caracter es 2
               output_low(pin_b1); // Apaga el LED RB1
               output_low(pin_b3); // Apaga el LED RB3
               output_high(pin_b0); // Enciende el LED RB0
               output_high(pin_b2); // Enciende el LED RB2
               break; // Sale del switch
            case '3': // Si el caracter es 3
               output_low(pin_b0); // Apaga el LED RB0
               output_low(pin_b2); // Apaga el LED RB2
               output_high(pin_b1); // Enciende el LED RB1
               output_high(pin_b3); // Enciende el LED RB3
               break; // Sale del switch
            case '4': // Si el caracter es 4
               output_low(pin_b0); // Apaga el LED RB0
               output_low(pin_b1); // Apaga el LED RB1
               output_low(pin_b2); // Apaga el LED RB2
               output_high(pin_b3); // Enciende el LED RB3
               break; // Sale del switch
            case '5': // Si el caracter es 5
               output_low(pin_b1); // Apaga el LED RB1
               output_low(pin_b2); // Apaga el LED RB2
               output_low(pin_b3); // Apaga el LED RB3
               output_high(pin_b0); // Enciende el LED RB0
               break; // Sale del switch            
         }
      }
   }
}

