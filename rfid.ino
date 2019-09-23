/*
* Codigo exemplo de utilizacao do sensor MFRC522(RFID).
* Utiliza biblioteca do sensor.
*/

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

// Definicao das portas do MFRC522
#define SS_PIN 10
#define RST_PIN 9

// Cria a instancia MFRC522 .
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Define as portas da tela LCD
LiquidCrystal lcd(6, 7, 5, 4, 3, 2);

void mensageminicial()
{
  // Mensagem inicial do serial monitor
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();

  // Mensagem inicial da tela LCD
  lcd.clear();
  lcd.print(" Aproxime o seu");
  lcd.setCursor(0, 1);
  lcd.print("cartao do leitor");
}

void setup()
{
  Serial.begin(9600); // Inicia a serial
  SPI.begin();        // Inicia  SPI bus
  mfrc522.PCD_Init(); // Inicia MFRC522
  lcd.begin(16, 2);   //Define o número de colunas e linhas do LCD:

  // Executa mensagem inicial no LCD e no serial monitor
  mensageminicial();
}

void loop()
{
  // Procurando
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Selecionando
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  //Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo = "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");

  // Converte conteudo lido em caixa alta para comparacao
  conteudo.toUpperCase();

  if (conteudo.substring(1) == "ED 78 03 CA") //UID 1 - Chaveiro
  {
    Serial.println("Ola chaveiro!");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ola chaveiro!");
    lcd.setCursor(0, 1);
    lcd.print("Acesso liberado!");
  }

  if (conteudo.substring(1) == "BD 9B 06 7D") //UID 2 - Cartao
  {
    Serial.println("Ola cartao!");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ola cartao!");
    lcd.setCursor(0, 1);
    lcd.print("Acesso Negado!");
  }
  delay(3000);
  mensageminicial();
}

/*
   https://github.com/miguelbalboa/rfid
   renomear rfid-master para MFRC522
   colocar na pasta libraries da IDE
}*/