////////////////////////////////////////////////////////////////////////////////////
// 
// L1 - DE1
// Capteur à ultrason
//
// S. CRAND - juin 2017
// First version
//
// D. HARDY - sept 2024
// Cleanup + Minor revision
//
////////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------------
// Définition des constantes
//----------------------------------------------------------------------------------

//définition des broches utilisées
const int ECHO    = 4;        // pin 4                       
const int TRIGGER = 3;        // pin 3   

// nombre de lecture pour le 
// calcul de la moyenne
const int NUM_OF_READINGS = 5;  

//----------------------------------------------------------------------------------
// Définition des variables globales
//----------------------------------------------------------------------------------

// stockage de la somme des distances
unsigned long sum;

// nombre de lecture effectuée  
int nbRead;

//----------------------------------------------------------------------------------
// Fonction d'initialisation
//----------------------------------------------------------------------------------
void setup() 
{  
  // Définition des entrées/sorties 
  // du microcontrôleur
  pinMode(TRIGGER, OUTPUT);                     
  pinMode(ECHO, INPUT);                      

  // Définition du débit de la 
  // transmission série : 9600 bits/s
  Serial.begin(9600);

  //initialisation des variables globales
  sum    = 0;
  nbRead = 0;
} 

//----------------------------------------------------------------------------------
// Fonction de mesure de la distance
//
// Retourne la distance (unsigned long)
//----------------------------------------------------------------------------------
unsigned long mesureDistance()
{
    digitalWrite(TRIGGER, HIGH);                    
    delayMicroseconds(10);                  
    digitalWrite(TRIGGER, LOW);                    
    unsigned long pulseTime = pulseIn(ECHO, HIGH);             
    unsigned long distance  = pulseTime/58;
    return distance;
}

//----------------------------------------------------------------------------------
// Fonction principale 
//----------------------------------------------------------------------------------
void loop()
{
  sum += mesureDistance();  // equivalent à : sum = sum + mesureDistance();
  nbRead++;                 // equivalent à : nbRead = nbRead + 1;

  if(nbRead == NUM_OF_READINGS) // si toutes les mesures ont été prises
  {
    int averageDistance = sum / NUM_OF_READINGS;  // Calcul de la moyenne
    Serial.println(averageDistance, DEC);         // Envoi de la distance 
                                                  // sur le port série

    // réinitialisation des variables globales pour la prochaine prise de mesure
    sum    = 0;
    nbRead = 0;
  }

  delay(100); // attente entre deux prises de distance 
}