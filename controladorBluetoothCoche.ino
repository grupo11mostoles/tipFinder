/*
 * VAMOS A CONTROLAR LOS MOTORES MEDIANTE COMANDOS Y ADEMAS
 * UTILIZAREMOS UNA APLICACION ANDROID PARA QUE MANDE DICHOS
 * COMANDOS POR BLUETOOTH A NUESTRO SENSOR POR PUERTO SERIAL.
 */
int dd1=13;
int dd2=12;
int di1=11;
int di2=10;
int ti1=9;
int ti2=8;
int td1=7;
int td2=6;
char caracter;
String instruccion;

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()>0){
    caracter = Serial.read();
    instruccion.concat(caracter);
    delay(10);
  }
  if(instruccion.equals("avanzar")==true){
    digitalWrite (dd1, HIGH);
    digitalWrite (dd2, LOW);
 
    digitalWrite (di1, HIGH);
    digitalWrite (di2, LOW);
    
    digitalWrite (td1, HIGH);
    digitalWrite (td2, LOW);
    
    digitalWrite (ti1, HIGH);
    digitalWrite (ti2, LOW);
     
    Serial.println("Coche avanzando");
  }
  if(instruccion.equals("atras")==true){
    digitalWrite (dd1, LOW);
    digitalWrite (dd2, HIGH);
 
    digitalWrite (di1, LOW);
    digitalWrite (di2, HIGH);
    
    digitalWrite (td1, LOW);
    digitalWrite (td2, HIGH);
    
    digitalWrite (ti1, LOW);
    digitalWrite (ti2, HIGH);
    
    Serial.println("Marcha atras");
  }

  if(instruccion.equals("derecha")==true){
    digitalWrite (dd1, HIGH);
    digitalWrite (dd2, LOW);
 
    digitalWrite (di1, LOW);
    digitalWrite (di2, LOW);
    
    digitalWrite (td1, HIGH);
    digitalWrite (td2, LOW);
    
    digitalWrite (ti1, LOW);
    digitalWrite (ti2, LOW);
    
    Serial.println("Girando a la derecha");
  }
  if(instruccion.equals("izquierda")==true){
    digitalWrite (dd1, LOW);
    digitalWrite (dd2, LOW);
 
    digitalWrite (di1, HIGH);
    digitalWrite (di2, LOW);
    
    digitalWrite (td1, LOW);
    digitalWrite (td2, LOW);
    
    digitalWrite (ti1, HIGH);
    digitalWrite (ti2, LOW);
    
    Serial.println("Girando a la izquierda");
  }

  if(instruccion.equals("parar")==true){
    digitalWrite (dd1, LOW);
    digitalWrite (dd2, LOW);
 
    digitalWrite (di1, LOW);
    digitalWrite (di2, LOW);
    
    digitalWrite (td1, LOW);
    digitalWrite (td2, LOW);
    
    digitalWrite (ti1, LOW);
    digitalWrite (ti2, LOW);
    
    Serial.println("Coche parado");
  }

  instruccion="";
}
