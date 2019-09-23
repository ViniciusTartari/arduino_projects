/*
* Codigo exemplo de utilizacao do sensor DHT11 (temperatura e humidade).
* Utiliza biblioteca do sensor.
*/

#include <DHT11.h>

// Definicao do pino de dados do dht11
int pin = 4;

// Inicializacao pela biblioteca
DHT11 dht11(pin);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int err;
  float temp, humi;
  if ((err = dht11.read(humi, temp)) == 0)
  {
    Serial.print("Temperatura:");
    Serial.print(temp);
    Serial.print(" Humidade:");
    Serial.print(humi);
    Serial.println();
  }
  else
  {
    Serial.println();
    Serial.print("Erro Nro :");
    Serial.print(err);
    Serial.println();
  }
  delay(DHT11_RETRY_DELAY); //delay de releitura
}
