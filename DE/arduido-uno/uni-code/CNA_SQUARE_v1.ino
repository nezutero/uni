//////////////////////////////////////////
// 
// L1 - DE1
// Génération d'un signal carré - DC
//
// S. CRAND - juin 2017
// First version
//
// D. HARDY - sept 2024
// Cleanup + Minor revision
//
//////////////////////////////////////////

//----------------------------------------
// Définition des constantes
//----------------------------------------

//définition des broches utilisées
const int NB_CNA_DATA_PIN = 8;
const int CNA_DATA_PIN[NB_CNA_DATA_PIN] = 
  {
    6, 7, 8, 9, 10, 11, 12, 13
  };
const int CNA_WRB = 5; 
const int WRB_CAN = 2; 

// définition des DATA
const int NB_DATA     = 2;
const byte LEVEL_HIGH = B10000000;
const byte LEVEL_LOW  = B00000000;
const byte DATA[NB_DATA] = 
{
  LEVEL_HIGH,LEVEL_LOW
};

//----------------------------------------
// Définition des variables globales
//----------------------------------------

// indice courant dans DATA 
int data_index;

//----------------------------------------
// Fonction d'initialisation
//----------------------------------------  
void setup()
{
  // Définition des entrées/sorties
  // du microcontrôleur
  pinMode(WRB_CAN, OUTPUT);
  pinMode(CNA_WRB, OUTPUT);
  for (int i=0; i<NB_CNA_DATA_PIN; i++)
  {
	  pinMode(CNA_DATA_PIN[i], OUTPUT);
  }

  //mise à l'état HIGH de WRB_CAN
  digitalWrite(WRB_CAN, HIGH);
  delay(1);

  //initialisation des variables globales
  data_index = 0;
}

//----------------------------------------
// Fonction principale
//----------------------------------------
void loop()
{
  for(int i=0;i<NB_CNA_DATA_PIN;i++)
  {
    if (DATA[data_index] & (1<<i))
    { 
      digitalWrite(CNA_DATA_PIN[i],HIGH); 
    }
    else
    { 
      digitalWrite(CNA_DATA_PIN[i],LOW); 
    }
  }

  data_index = (data_index + 1) % NB_DATA;

  digitalWrite(CNA_WRB, LOW);
  delayMicroseconds(1);
  digitalWrite(CNA_WRB, HIGH);
  //delay(1);
}