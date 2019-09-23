/*
* Codigo exemplo de utilizacao do sensor hc-sr04(ultrasom).
* SEM BIBLIOTECA.
*/

// Definicao dos pinos do sensor
int trigPin = 13;
int echoPin = 12;

void setup()
{
  // Inicializacao dos pinos do sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Inicializacao da comunicacao serial
  Serial.begin(9600);
}

void loop()
{
  long tempo, distancia;

  // Gera um pulso no trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Le o pulso no pino de echo
  tempo = pulseIn(echoPin, HIGH);

  // Calcula a distancia baseado na velocidade do som / 2 (ida e volta)
  distancia = ((tempo * 340) / 1000) / 2;

  Serial.print(tempo);
  Serial.println(" microssegundos, ");
  Serial.print(distancia);
  Serial.println(" mm, ");
  Serial.print(distancia / 10);
  Serial.println(" cm, ");
  Serial.print(distancia / 100);
  Serial.println(" m.");

  // Delay para prox leitura
  delay(500);
}