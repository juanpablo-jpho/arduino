// importaciones
// declaraciones devariables

#define SALA 13


void setup() {
  Serial.begin(9600);
  pinMode(SALA, OUTPUT);

}

void loop() {
  int opcion = showMenu();
  doAlgo(opcion);
}

void doAlgo(int opc) {

  if (opc == 1) {
    prenderFoco();
  }
  if (opc == 2) {
    apagarFoco();
  }

}

void prenderFoco() {
  Serial.println("--- Focos a eligir ---");
  Serial.println("(1) Sala");
  Serial.println("(2) Comedor");
  Serial.println("(3) Cocina");
  int foco =  inputTecla("Ingresa foco a encender: ");
  if (foco == 1) {
      if ( digitalRead(SALA) == HIGH )  {
        digitalWrite(SALA, LOW);
        Serial.println("FOCO DE LA SALA APAGADO");
      } else {
        digitalWrite(SALA, HIGH);
        Serial.println("FOCO DE LA SALA PRENDIDO");
      }
  }
  if (foco == 2) {
    //    digitalWrite(COCINA, HIGH);
  }

}


void apagarFoco() {
  Serial.println("--- Focos a eligir ---");
  Serial.println("(1) Sala");
  Serial.println("(2) Comedor");
  Serial.println("(3) Cocina");
  int foco =  inputTecla("Ingresa foco a apagar: ");
  if (foco == 1) {
    digitalWrite(SALA, LOW);
    Serial.println("FOCO DE LA SALA APAGADO");
  }
  if (foco == 2) {
    //digitalWrite(COCINA, LOW);
  }

}


int showMenu() {
  Serial.println("---- Menú ----");
  Serial.println("(1) Prender foco");
  Serial.println("(2) Apagar foco");
  Serial.println("(3) Prender todos");
  Serial.println("(4) Apagar todos");
  Serial.println("(5) Alternar todos");
  Serial.println("(6) Toogle foco");
  Serial.println("------------");

  int opc = inputTecla("Ingresa una opción: ");
  return opc;
}




int inputTecla(String mensaje) {
  int input = 0;
  Serial.print(mensaje);
  while (input == 0)  {
    while (  Serial.available() > 0 )  {
      int value = Serial.parseInt();
      if (value != 0) {
        Serial.println(value);
        input = value;
      }
    }
  }
  return input;
}

int suma2Num(int numeroA, int numeroB) {
  int suma = numeroA + numeroB;
  return suma;
}

void showRespuesta(int value) {
  Serial.print("La respuesta es: ");
  Serial.println(value);
  delay(2000);
}
