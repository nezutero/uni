//////////////////////////////////////////
// 
// L1 - DE1
// Fusion de données
//
// S. CRAND - septembre 2018
// First version
//
// D. HARDY - sept 2024
// Cleanup + Minor revision
//
//////////////////////////////////////////

//----------------------------------------
// Exemple d'une trame :
//
// balisedebut
// joystick,x,514
// joystick,y,123
// joystick,bp,0
// temperature,19
// ultrason,25
// son,72
// lumiere,2
// balisefin
//
//----------------------------------------

//----------------------------------------
// Définition des constantes
//----------------------------------------

// Joystick : Broches utilisées              
const int BP = A3;        // pin ADC3
const int X  = A4;        // pin ADC4
const int Y  = A5;        // pin ADC5

// Capteur température : Broches utilisées
const int TEMP = A2;        // pin ADC2                       

// Capteur ultrason : Broches utilisées
const int ECHO    = 4;     // pin 4                       
const int TRIGGER = 3;     // pin 3

// Capteur audio : Broches utilisées 
const int SON = A1;        // pin ADC1 

// Capteur lumière : Broches utilisées
const int LUM = A0;        // pin ADC0
         
//----------------------------------------
// Fonction d'initialisation
//----------------------------------------  
void setup()
{
  // Définition des entrées/sorties
  // du microcontrôleur
  pinMode(TRIGGER, OUTPUT);                     
  pinMode(ECHO, INPUT);

  // Définition du débit de la 
  // transmission série : 9600 bits/s
  Serial.begin(9600);
}

//----------------------------------------------------------------------------------
// Fonction principale 
//----------------------------------------------------------------------------------
void loop() 
{
  // Joystick           
  int data_bp = analogRead(BP);
  int data_x = analogRead(X);
  int data_y = analogRead(Y);
 
  if (data_bp < 100) 
  {
	  data_bp = 0;
  }
  else 
  {
	  data_bp = 1;
  } 
  
  // Capteur Temperature
  int data_temp = analogRead(TEMP); 

  // Capteur Ultrason 
  digitalWrite(TRIGGER, HIGH);                    
  delayMicroseconds(10);                  
  digitalWrite(TRIGGER, LOW);                    
  unsigned long pulseTime = pulseIn(ECHO, HIGH);             
  unsigned long distance = pulseTime/58;                        
  int data_capus = distance;         

  // Capteur audio
  int data_son = analogRead(SON);

  // Capteur Lumiere
  int data_lum = analogRead(LUM);

  // Envoi trame sur le port série 
  Serial.println("balisedebut");
  Serial.print("joystick,x,");
  Serial.println(data_x);
  Serial.print("joystick,y,");
  Serial.println(data_y);
  Serial.print("joystick,bp,");
  Serial.println(data_bp);
  Serial.print("temperature,");
  Serial.println(data_temp);
  Serial.print("ultrason,");
  Serial.println(data_capus);
  Serial.print("son,");
  Serial.println(data_son);
  Serial.print("lumiere,");
  Serial.println(data_lum);
  Serial.println("balisefin");

  delay(2000);                      
}