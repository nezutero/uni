//////////////////////////////////////////
// 
// L1 - DE1
// Génération d'un signal sinus - DC
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
const int NB_DATA = 51;
const byte DATA[NB_DATA] = 
{
  B10000000,
  B10010000,
  B10011111,
  B10101111,
  B10111101,
  B11001011,
  B11010111,
  B11100010,
  B11101100,
  B11110011,
  B11111001,
  B11111101,
  B11111111,
  B11111111,
  B11111101,
  B11111001,
  B11110011,
  B11101100,
  B11100010,
  B11010111,
  B11001011,
  B10111101,
  B10101111,
  B10100000,
  B10010000,
  B10000000,
  B01110000,
  B01100000,
  B01010001,
  B01000010,
  B00110100,
  B00101000,
  B00011101,
  B00010100,
  B00001100,
  B00000110,
  B00000010,
  B00000000,
  B00000000,
  B00000010,
  B00000110,
  B00001100,
  B00010011,
  B00011101,
  B00101000,
  B00110100,
  B01000010,
  B01010000,
  B01011111,
  B01101111,
  B01111111,
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
  delayMicroseconds(100);
}