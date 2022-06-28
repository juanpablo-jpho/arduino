#define led 12
#define sensor A0
#define ventilador 7


unsigned long tiempoAnt = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(ventilador, OUTPUT);
  pinMode(sensor, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  indicadorLed();
  // getTemperatura();
  // setVentilador();
  
}

// tiempoAnt  = 3000 ms; 
void indicadorLed() {
    unsigned long tiempoAct = millis();   // 6000 ms
    if (tiempoAct - tiempoAnt >= 3000 ) {
        digitalWrite(led, !digitalRead(led));
        tiempoAnt = tiempoAct;
    }  
}




