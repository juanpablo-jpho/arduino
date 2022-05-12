// 3 pulsantes
// 3 leds  (binario)

// menu inicial:
// (1) Añadir gol
// (2) Conocer numero de goles
// (3) Resetear


#define opc1 13
#define opc2 12

#define led1 10
#define led2 9

int golesEquipoA = 0;
int golesEquipoB = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(opc1, INPUT);
  pinMode(opc2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int opc = showMenuInicial();
  if (opc == 1) {
      addGol();  
  }
  if (opc == 2) {
      getGol();  
  }
  if (opc == 3) {
      reset();  
  }

}

int showMenuInicial() {
  int opc = 0;
  Serial.println("Elige una opción");
  Serial.println("1. Añadir gol");
  Serial.println("2. Conocer goles");
  Serial.println("3. Resetear");
  while( opc == 0) {
     boolean estateOpc1 = getEstatePulsante(opc1);
     if (estateOpc1 == true) {
      opc = 1;
     } 
     boolean estateOpc2 = getEstatePulsante(opc2);
     if (estateOpc2 == true) {
      opc = 2;
     } 
  } 
  return opc;
}

boolean getEstatePulsante(int puerto) {
   boolean estado = digitalRead(puerto);
   boolean presionado = false;
   while (estado) {
      estado = digitalRead(puerto);
      delay(100);
      presionado = true;
   }
   if (presionado) {
     return true;
   } else {
       return false;
   }
}

void addGol() {
  int opc = 0;
  Serial.println("Elige el equipo para añadir gol");
  Serial.println("1. Equipo A");
  Serial.println("2. Equipo B");
  while( opc == 0) {
     boolean estateOpc1 = getEstatePulsante(opc1);
     if (estateOpc1 == true) {
      opc = 1;
     } 
     boolean estateOpc2 = getEstatePulsante(opc2);
     if (estateOpc2 == true) {
      opc = 2;
     } 
  } 
  if (opc == 1) {
      golesEquipoA = golesEquipoA + 1;
  }
  if (opc == 2) {
      golesEquipoB = golesEquipoB + 1;
  }
  // festejar gol con los leds
}


void getGol() {
 int opc = 0;
  Serial.println("Elige el equipo conocer los goles");
  Serial.println("1. Equipo A");
  Serial.println("2. Equipo B");
  while( opc == 0) {
     boolean estateOpc1 = getEstatePulsante(opc1);
     if (estateOpc1 == true) {
      opc = 1;
     } 
     boolean estateOpc2 = getEstatePulsante(opc2);
     if (estateOpc2 == true) {
      opc = 2;
     } 
  } 
  if (opc == 1) {
      showGolesInleds(golesEquipoA);
  }
  if (opc == 2) {
     showGolesInleds(golesEquipoB);
  }
}

void showGolesInleds(int goles) {
  if (goles == 1) {
      digitalWrite(led1, HIGH); 
      digitalWrite(led2, LOW);   
  }
  if (goles == 0) {
      digitalWrite(led1, LOW); 
      digitalWrite(led2, LOW);   
  }
}

void reset() {
  golesEquipoA = 0;
  golesEquipoB = 0;
}
