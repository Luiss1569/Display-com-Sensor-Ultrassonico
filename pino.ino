#include <LiquidCrystal.h>

const int gatilho = 9; 
const int echo = 8;    
const int D4_pin = 2;
const int D5_pin = 3;
const int D6_pin = 4;
const int D7_pin = 5;
const int En_pin = 11;
const int Rs_pin = 12;
const int Ana_pin = 6;

/*
 *Ligar Sensor
 * Vcc 5v
 * Trig pin 9
 * echo pin 8
 * Gnd gnd
 * 
 *Ligar Dislplay 
 * Gnd
 * VCC 5v
 * Voltimetro 5v, VO Dis, gnd
 * Rs 12, RW gnd, E 11
 * DB4,5,6,7 = 2,3,4,5
 * led 5v ligado resistor 220 ohms red,red,brown(vermelho,vermelho,marrom)
 *  ou apenas ligue na porta 6
 * led gnd
*/

float tempo; // para armazenar o tempo de ida e volta do sinal em microsegundos
float distancia_cm; // para armazenar a distância em centímetros
float distancia_in; // para armazenar a distância em polegadas
 

LiquidCrystal lcd(
  Rs_pin,
  En_pin,
  D4_pin,
  D5_pin,
  D6_pin,
  D7_pin
);

void setup(){
  lcd.begin(16, 2); 
  pinMode(Ana_pin,OUTPUT);
  pinMode(gatilho,OUTPUT);
 // deixa pino em LOW
  digitalWrite(gatilho,LOW);
  delayMicroseconds(10);
  analogWrite(Ana_pin,0);
 // configura pino ECHO como entrada
  pinMode(echo,INPUT);
}

void loop(){
  // disparar pulso ultrassônico
  digitalWrite(gatilho, HIGH);
  delayMicroseconds(10);
  digitalWrite(gatilho, LOW);
 
 // medir tempo de ida e volta do pulso ultrassônico
  tempo = pulseIn(echo, HIGH);
 
 // calcular as distâncias em centímetros e polegadas
  distancia_cm = tempo / 29.05 / 2;
  distancia_in = tempo / 74.7 / 2;
  
  lcd.clear();
  lcd.print("Dist:");
  lcd.print(distancia_cm);
  lcd.print("cm");
  delay(1000);
}
