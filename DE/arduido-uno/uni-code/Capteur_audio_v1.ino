//////////////////////////////////////////
// 
// L1 - DE1
// Capteur de son
//
// S. CRAND - juin 2017
// First version
//
// D. HARDY - sept 2024
// Minor revision
//
//////////////////////////////////////////

//----------------------------------------
// Définition des constantes
//----------------------------------------

//définition des broches utilisées
const int SON = A1;        // pin ADC1   

//----------------------------------------
// Fonction d'initialisation
//----------------------------------------                         
void setup() 
{             
  // Définition du débit de la 
  // transmission série : 9600 bits/s
  Serial.begin(9600);
}                          

//----------------------------------------
// Fonction principale
//----------------------------------------
void loop() 
{
  int data = analogRead(SON) ; 
  Serial.println(data);
}