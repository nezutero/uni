const int BP = A3;  
const int X  = A4;
const int Y  = A5;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int data_x  = analogRead(X);
  int data_y  = analogRead(Y);
  int data_bp = analogRead(BP);

  String posX;
  if (data_x < 340) 
  {
    posX = "gauche";
  } 
  else if (data_x > 680) 
  {
    posX = "droite";
  } 
  else 
  {
    posX = "milieu";
  }

  String posY;
  if (data_y < 340) 
  {
    posY = "bas";
  } 
  else if (data_y > 680) 
  {
    posY = "haut";
  } 
  else 
  {
    posY = "milieu";
  }

  String label;
  if (posX == "milieu" && posY == "milieu") 
  {
    label = "milieu";
  } 
  else if (posX == "milieu") 
  {
    label = "milieu en " + posY;
  } 
  else if (posY == "milieu") 
  {
    label = "a " + posX + " au milieu";
  } 
  else 
  {
    label = "a " + posX + " en " + posY;
  }

  Serial.println(label);

  if (data_bp < 500) 
  {
    Serial.println("APPUYE");
  } 
  else 
  {
    Serial.println("NON APPUYE");
  }

  Serial.print("X = "); 
  Serial.println(data_x);
  Serial.print("Y = "); 
  Serial.println(data_y);

  delay(200);
}
