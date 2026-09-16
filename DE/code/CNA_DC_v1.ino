//////////////////////////////////////////
// 
// L1 - DE1
// Génération d'un signal continu - DC
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

// définition de DATA
const byte DATA = B10000000;

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

  //DC mode => DATA constant
  for(int i=0;i<NB_CNA_DATA_PIN;i++)
  {
    if (DATA & (1<<i))
    { 
      digitalWrite(CNA_DATA_PIN[i],HIGH); 
    }
    else
    { 
      digitalWrite(CNA_DATA_PIN[i],LOW); 
    }
  }

  //mise à l'état HIGH de WRB_CAN
  digitalWrite(WRB_CAN, HIGH);
  delay(1);
}

//----------------------------------------
// Fonction principale
//----------------------------------------
void loop()
{
  digitalWrite(CNA_WRB, LOW);
  delayMicroseconds(10);
  digitalWrite(CNA_WRB, HIGH);
  delay(1);
}