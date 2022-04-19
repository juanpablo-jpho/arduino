void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

  int opc = selecOpc();
  if (opc == 1) {
    suma2Num();
  }
  if (opc == 2) {
    resta2Num();
  }
  delay(2000);

}

int selecOpc() {

  int opc = 0;
  Serial.println("Elige una opción");
  Serial.println("1. Abrir puerta");
  Serial.println("2. Prender foco");
  Serial.println("3. Salir");
  while (opc == 0) {

    while ( Serial.available() > 0 ) {
      int data = Serial.parseInt();
      if (data) {
        opc = data;
        Serial.println(opc);
      }

    }

  }


  return opc;

}


void resta2Num() {

  Serial.println("Estoy en la función Resta");
}

void suma2Num() {

  int numeroA = 0;
  int numeroB = 0;

  Serial.print("Ingresa 1er número: ");
  while (numeroA == 0) {
    while ( Serial.available() > 0 ) {
      int data = Serial.parseInt();
      if (data > 0) {
        numeroA = data;
      }
    }
  }
  Serial.println(numeroA);

  Serial.print("Ingresa 2do número: ");
  while (numeroB == 0) {
      while ( Serial.available() > 0 ) {
        int data = Serial.parseInt();
        if (data > 0) {
          numeroB = data;
        }
      }
  }
  Serial.println(numeroB);
  Serial.print("La suma es: ");
  int suma = numeroA + numeroB;
  Serial.println(suma);

}
