#include "led.h"

LedState_Type led1_state;       // Variabler som tar in status 0/1
LedState_Type led2_state;
LedState_Type led3_state;

Led led1(RED,ON);               // Skapar objekt led1 som är röd och på

int main(void){      //huvudfunktion konstruerar och hanterar LED-lamporna
  USART2_Init();                // Initierar/skapar funktionen USART2_init

  Led led2(BLUE,ON);            // Skapar objektet led2 som är Blå och på

  Led *led3 = new Led(YELLOW,ON); //Dynamiskt minnes allokerat objekt, gul och på.

  led1_state = led1.getState();  // Hämtar tillståndet påslagen av från led1

  led1.setState(OFF);             // Skickar genom set metod tillståndet OFF till led1 

  delete led3;                    // Tar bort led3 och friar minnet som riskerar "leakage"  
                                  // i små chip iom dynamiskt allokerat minne.
  while(1){}

}
