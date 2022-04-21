#define LEDSALA 16


boolean focoSala = false;
boolean focoComedor = false;
boolean focoCocina = false;



void setup() {
  Serial.begin(9600);
  pinMode(LEDSALA, OUTPUT);
}

void loop() {
    int opcion = showMenu();
    if (opcion == 1) {
      //hacer algo
    }
    if (opcion == 2) {
       toogleFoco()
    }
    if (opcion == 3) {
      //hacer algo
    }
    //y asi para cada opción

}



int showMenu() {
  int opc = 0;
  Serial.println("Elige una opción");
  Serial.println("1. Abrir puerta");
  Serial.println("2. Prender foco");
  Serial.println("3. Apagar todos los focos");
  Serial.println("4. Conocer estado de un foco");
  Serial.println("5. Prender todos los focos");
  Serial.println("6. Alternar estados de los focos");
  Serial.println("7. Conocer estado de todos los focos");
  Serial.println("8. Salir");
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


void toogleFoco() {
  int focoSelected = 0;
  Serial.println("¿Que foco deseas prender?");
  Serial.println("1. Sala");
  Serial.println("2. Comedor");
  Serial.println("3. Cocina");
  while (focoSelected == 0) {
    while ( Serial.available() > 0 ) {
      int data = Serial.parseInt();
      if (data) {
        focoSelected = data;
        Serial.println(focoSelected);
      }
    }
  }

  if (focoSelected == 3) {
    if (focoCocina == true) {
      Serial.println("Foco de la Cocina apagada");
      focoCocina = false;
    } else {
      Serial.println("Foco de la Cocina prendiddo");
      focoCocina = true;
    }
    if ( digitalRead(LEDSALA) == HIGH ) {
        Serial.println("Foco de la Cocina apagada");
        digitalWrite(LEDSALA, LOW);  
    } else {
         digitalWrite(LEDSALA, HIGH);  
    } 
  }

  if (focoSelected == 2) {
    if (focoComedor == true) {
      Serial.println("Foco de la Comedor apagada");
      focoComedor = false;
    } else {
      Serial.println("Foco de la Comedor prendiddo");
      focoComedor = true;
    }
  }

  if (focoSelected == 1) {
    if (focoSala == true) {
      Serial.println("Foco de la sala apagada");
      focoSala = false;
    } else {
      Serial.println("Foco de la sala prendiddo");
      focoSala = true;
    }
  }




}

void apagarAll() {
      focoSala = false;
      focoComedor = false;
      focoCocina = false;
     Serial.println("Focos apagados con éxito");
     delay(1000);
}

void conocerStateLed() {
  int focoSelected = 0;
  Serial.println("¿De que foco deseas conocer su estado?");
  Serial.println("1. Sala");
  Serial.println("2. Comedor");
  Serial.println("3. Cocina");
  while (focoSelected == 0) {
    while ( Serial.available() > 0 ) {
      int data = Serial.parseInt();
      if (data) {
        focoSelected = data;
        Serial.println(focoSelected);
      }
    }
  }

  if (focoSelected == 3) {
    if (focoCocina == false) {
      Serial.println("Foco de la Cocina apagada");
    
    } else {
      Serial.println("Foco de la Cocina prendiddo");
    }
  }

  if (focoSelected == 2) {
    if (focoComedor == false) {
      Serial.println("Foco de la Comedor apagada");
    } else {
      Serial.println("Foco de la Comedor prendiddo");
    }
  }

  if (focoSelected == 1) {
    if (focoSala == false) {
      Serial.println("Foco de la sala apagada");
    } else {
      Serial.println("Foco de la sala prendiddo");
    }
  }




}
