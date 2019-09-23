/*
* Codigo base para LDR (sensor de luminosidade).
*/

// Definicao do LDR - porta analogica
int ldr = A0;

// Definicao do led - porta digital
int led = 13;

void setup()
{
  pinMode(led, OUTPUT); // led - saida
  pinMode(ldr, INPUT);  // ldr - entrada
  Serial.begin(9600);   // Inicializa a comunicacao serial
}

void loop()
{
  // Le a resistencia do ldr
  int estado = analogRead(ldr);
  // Printa o valor no serial monitor
  Serial.println(estado);

  // Acende o led caso a resposta do ldr for maior que 500
  if (estado > 500)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
}