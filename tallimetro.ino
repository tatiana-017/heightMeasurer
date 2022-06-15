//Declaraciòn de variables
const int pinTrig = 9;
const int pinEcho = 10;
long      duracion = 0;
int       distancia = 0;
int       valFinal = 0;

//Inicializaciòn de LCD
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(pinTrig, OUTPUT); //Transmisor 
  pinMode(pinEcho, INPUT); //Receptor 
  lcd.begin(16, 2);

  Serial.begin(9600);
}

void loop() {

   //Apagamos el sensor 
   digitalWrite(pinTrig, LOW);
   delayMicroseconds(2);

   
   //CONFIGURCIÒN ENVÌO DE LA ONDA
   //Encendemos el sensor para que envìe la onda ultrasònica
   digitalWrite(pinTrig, HIGH);
   //Tiempo de envio de la onda
   delayMicroseconds(10); //Son 10 microsegundos porque la funiòn pulseIn funciona desde ese valor 
   //Apagamos de nuevo el sensor 
   digitalWrite(pinTrig, LOW);

   //CONFIGURCIÒN PARA RECIBIR LA ONDA 
   duracion = pulseIn(pinEcho, HIGH);

    distancia = (0.034*duracion)/2; //Lo dividimos entre dos porque la variable duraciòn almacena el tiempo que tarda la onda en ir y venir 
    valFinal = 180 - distancia; //Tomamos un valor de referencia 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(distancia);
    lcd.print("cm");
    lcd.setCursor(0,1);
    lcd.print("Altura: ");
    lcd.print(valFinal);
    lcd.print("cm");
    delay(2000);
   

}
