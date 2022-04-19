// declaracion de variables y definiciones e imprtaciones de librerias

int numero = 10;
boolean estado = false;
String mensaje = "hola mundo"; 
int contador = 0; 
   


void setup() {
  //  put your setup code here, to run once:
  int variable = 30;
  Serial.begin(9600);
  Serial.println("estoy en la funcion setup");
  Serial.println(numero);
  Serial.println(variable);
}





void loop() {

    String respuesta = validarPase(100, 90, 40);    
    Serial.println(respuesta);
    delay(2000);   
}

String validarPase(int momento1, int momento2, int momento3) {
    int suma = momento1 + momento2 + momento3;
    int promedio = suma / 3; 
    if (promedio < 30) {
        return "Reprobado";  
    }
    if (promedio > 30 && promedio < 70) {
        return "Supletorio" ;   
    }
    if (promedio >= 70) {
        return "Aprobo" ; 
    }
}
