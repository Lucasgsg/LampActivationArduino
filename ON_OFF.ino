 //Definir os pinos para o microfone e relé
int relay = 8;
int microphone = A0;
 
int counter = 0;  //Contador de palmas
int counter2 = 0; //Contador de tempo para o Reset

void setup() 
{
  Serial.begin(9600); 
   
  pinMode(relay,OUTPUT);
  pinMode(microphone, INPUT);
   
  /*
   Utilizamos a instrução a seguir para:
   quando ligarmos o arduino
   garantirmos que o relay esteja sempre desligado
  */
  digitalWrite(relay, LOW);
 
}

void loop() {
  
  if(digitalRead(microphone)) 
  {
    Serial.print("PALMA DETECTADA!");
    Serial.print("Valor no Sensor: ");
    Serial.println(analogRead(microphone));
    counter++;
    delay(50);
    counter2 = 0;
    
  //Quando Forem Batidas Duas Palmas
    if(counter == 2) 
    {
      digitalWrite(relay, !digitalRead(relay));
      counter2 = 0;
    }
  
  }
  
  counter2++;
  delay(1);
  
  //Contador p/ detectar tempo entre as palmas
  if(counter2 == 3000)
  {
    Serial.println("Tempo Esgotado!");
    counter = 0;
    counter2 = 0;
  }
  
}
