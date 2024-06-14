#include <LiquidCrystal.h>
//definição dos pinos
int BUZZER_PIN = 10;
int GREEN_LED_PIN = 11;
int YELLOW_LED_PIN = 12;
int RED_LED_PIN = 13;
int TEMP_SENSOR_PIN = A0;
int UMIDADE_SENSOR_PIN = A1;
float LUMINOSIDADE_SENSOR = A2;
int valorLDR = 0;
int RS = 9, EN = 8, DB4 = 5, DB5 = 4, DB6 = 3, DB7 = 2;
LiquidCrystal lcd(RS, EN, DB4, DB5, DB6, DB7);

//definição da saída dos pinos 
void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  int tempValue = analogRead(TEMP_SENSOR_PIN);
  int umidadeValue = analogRead(UMIDADE_SENSOR_PIN);
  int valorLDR = analogRead(LUMINOSIDADE_SENSOR);
  
  int temp = map(tempValue, 20, 358, 0, 50);
  int umidade = map(umidadeValue, 0, 1023, 0, 100);
  int luz = map(valorLDR, 6, 679, 0, 100);
  
  Serial.print("Raw Temp Value: ");
  Serial.println(tempValue);

	

  // Temperatura
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" GRAUS");

  if (temp > 40) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    tone(BUZZER_PIN, 2000);
    lcd.setCursor(0, 1);
    lcd.print("MUITO QUENTE");
  } else if (temp >= 30) {
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    tone(BUZZER_PIN, 1500);
    lcd.setCursor(0, 1);
    lcd.print("QUENTE");
  } else {
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    noTone(BUZZER_PIN);
    lcd.setCursor(0, 1);
    lcd.print("BOA CORRIDA!!");
  }
  
  delay(5000);

  // Umidade
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Umidade: ");
  lcd.print(umidade);

  if (umidade < 20) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    tone(BUZZER_PIN, 2000);
    lcd.setCursor(0, 1);
    lcd.print("UMIDADE PESSIMA");
  } else if (umidade > 80) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    tone(BUZZER_PIN, 2000);
    lcd.setCursor(0, 1);
    lcd.print("CHUVA NA PISTA");
  } else if (umidade <= 30) {
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    tone(BUZZER_PIN, 1500);
    lcd.setCursor(0, 1);
    lcd.print("UMIDADE MEDIA");
  } else if (umidade >= 70) {
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    tone(BUZZER_PIN, 1500);
    lcd.setCursor(0, 1);
    lcd.print("POSSIVEL CHUVA");
  } else {
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    noTone(BUZZER_PIN);
    lcd.setCursor(0, 1);
    lcd.print("BOA CORRIDA!!");
  }

  delay(5000);

  // Luz
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Luz: ");
  lcd.print(luz);

  if (luz < 20) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    tone(BUZZER_PIN, 2000);
    lcd.setCursor(0, 1);
    lcd.print("MUITO ESCURO");
  } else if (luz <= 40) {
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    tone(BUZZER_PIN, 1500);
    lcd.setCursor(0, 1);
    lcd.print("ESCURO");
  } else {
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    noTone(BUZZER_PIN);
    lcd.setCursor(0, 1);
    lcd.print("BOA CORRIDA!!");
  }

  delay(5000);
}
