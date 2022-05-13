// menu inicial
// (1) Añadir gol
// (2) Conocer numero de goles
// (3) Resetear

// 3 leds   ->  codigo binario   ->  
// 3 pulsantes

#define opc1 10
#define opc2 9

#define led1 13
#define led2 12

int golesEquipoA = 0;
int golesEquipoB = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(opc1, INPUT);
  pinMode(opc2, INPUT); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
   int opcion = showMenuInicial();
   if (opcion == 1) {
      addGol();  
   }
   if(opcion == 2) {
     getGoles(); 
   }
   if (opcion == 3) {
      reset(); 
   }
}


int showMenuInicial() {
  int opc = 0;
  Serial.println("---MENU---");  
   Serial.println("(1) Add gol ");  
 Serial.println("(2) get gol ");  
  Serial.println("(3) reset ");
  while (opc == 0) {
        boolean pulsante1 = getEstatePulsante(opc1);
        if (pulsante1 == true) {
            opc = 1;
        }
        boolean pulsante2 = getEstatePulsante(opc2);
        if (pulsante2 == true) {
            opc = 2;
        } 
  }
  return opc;

    
  
}

void addGol() {
  int opc = 0;
  Serial.println("¿Que equipo metio gol?");  
  Serial.println("(1) Equipo A ");  
  Serial.println("(2) Equipo B ");  
  while (opc == 0) {
        boolean pulsante1 = getEstatePulsante(opc1);
        if (pulsante1 == true) {
            opc = 1;
        }
        boolean pulsante2 = getEstatePulsante(opc2);
        if (pulsante2 == true) {
            opc = 2;
        } 
  }
  if (opc == 1) {
    golesEquipoA = golesEquipoA + 1;
  }
     
}

void getGoles() {
  int opc = 0;
  Serial.println("¿De que equipo deseas saber los goles?");  
  Serial.println("(1) Equipo A ");  
  Serial.println("(2) Equipo B ");  
  while (opc == 0) {
        boolean pulsante1 = getEstatePulsante(opc1);
        if (pulsante1 == true) {
            opc = 1;
        }
        boolean pulsante2 = getEstatePulsante(opc2);
        if (pulsante2 == true) {
            opc = 2;
        } 
  }
  if (opc == 1) {
      showGolesInLeds(golesEquipoA);
  }
}

void showGolesInLeds(int goles) {

    if (goles == 0) {
        digitalWrite(led1, LOW); 
        digitalWrite(led2, LOW);  
    }
        if (goles == 1) {
        digitalWrite(led1, HIGH); 
        digitalWrite(led2, LOW);  
    }
           if (goles == 2) {
        digitalWrite(led1, LOW); 
        digitalWrite(led2, HIGH);  
    }

  
}

void reset() {
   golesEquipoA = 0;
   golesEquipoB = 0;  
}





boolean getEstatePulsante(int puerto) {
     boolean estado = digitalRead(puerto);
     boolean presionado = false;
     while(estado) {
        estado = digitalRead(puerto);
        presionado = true;
        delay(100);
     }
     return presionado;
}
