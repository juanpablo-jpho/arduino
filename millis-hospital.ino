
// sensar algo critico todo el tiempo -> potenciometro;
// activar un suero -> led

// leer algo de la base de datos -> pulsante 1 seg
// activamos una maquina.

// 3 seg inyectar una gota de medicamento
// serial.print("gota inyectada")

#define sensor A0
#define suero 13
#define maquina 12
#define baseDatos 11



unsigned long tiempoAnt = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  pinMode(suero, OUTPUT);
  pinMode(maquina, OUTPUT);
  pinMode(baseDatos, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensarValorCritico();
  getBaseDatos();

}

void sensarValorCritico() {
  int value = analogRead(sensor);  // 0 - 1023
  if (value > 500) {
      digitalWrite(suero, HIGH);  
  } else {
    digitalWrite(suero, LOW);  
  }
}

void getBaseDatos() {
                                           
   unsigned long tiempoAct = millis();   
   if ( tiempoAct - tiempoAnt >= 1000 ) {
         int valueBD = digitalRead(baseDatos); 
         if (valueBD == HIGH) {
                digitalWrite(maquina, HIGH);  
         } else {
          digitalWrite(maquina, LOW);  
         } 
         tiempoAnt = tiempoAct;
   }
}



