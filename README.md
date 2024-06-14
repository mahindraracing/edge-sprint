# Sprint - Challenge Mahindra 🏎️

## Nomes & RM's

<h2>

<li>Caio Suzano Ferreira da Silva: RM 554763</li>
<li>André Nakamatsu Rocha: RM555004</li>
<li>Matheus Rivera Montovaneli: RM 555499</li>
<li>Lucas Vasquez Silva: RM 555159 </li>
<li>Guilherme Linard F. R. Gozzi: RM 555768</li>

# Monitoramento das corridas de Formula E!

<img src="img/arduino.png">

<h2>Link da simulação no <strong><a href="https://www.tinkercad.com/things/b6zULwnCGlu-mighty-hango-fyyran/editel?sharecode=jKtoHGyMiFxj-v5kXj2o_rZkWP5gXwZ2PBNmC2vrHWg">Tinkercad</a></strong> e vídeo no <a href="">Youtube</a></h2>



<li> 🔴 Vermelho: Ruim. </li>
<li> 🟡 Amarelo: Médio. </li>
<li> 🟢 Verde: Bom. </li>

## Componentes

<li>1x Arduino Uno R3</li>
<li>1x Fotorresistor</li> 
<li>1x Potenciômetro</li>
<li>1x Sensor de temperatura [TMP36]</li>
<li>1x Led Vermelho</li>
<li>1x Led Amarelo</li>
<li>1x Led Verde</li>
<li>3x Resistores 220</li>
<li>1x Piezo</li>
<li>1x LCD 16x2</li>
<li>1x Resistor 1k</li>


## Explicando o <a href="https://github.com/mahindraracing/edge-sprint/blob/main/main.cpp">Código</a>

## 1. Inclusão de Bibliotecas e Definição de Pinos

```cpp
#include <LiquidCrystal.h>

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
```

Nesta seção, as bibliotecas necessárias para o projeto são incluídas, e os pinos para os componentes utilizados são definidos. A biblioteca `LiquidCrystal` é incluída para controlar o display LCD, e os pinos para os LEDs, o buzzer e os sensores de temperatura, umidade e luminosidade são definidos.

## 2. Configuração Inicial

```cpp
void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  lcd.begin(16, 2);
}
```

No método `setup()`, são configurados os pinos definidos anteriormente. Os pinos são configurados como saídas `(OUTPUT)`, e o objeto lcd é inicializado com o tamanho do display `LCD (16x2)`.

## 3. Loop Principal

```cpp
void loop() {
  int tempValue = analogRead(TEMP_SENSOR_PIN);
  int umidadeValue = analogRead(UMIDADE_SENSOR_PIN);
  int valorLDR = analogRead(LUMINOSIDADE_SENSOR);
  
  int temp = map(tempValue, 20, 358, 0, 50);
  int umidade = map(umidadeValue, 0, 1023, 0, 100);
  int luz = map(valorLDR, 6, 679, 0, 100);

  Serial.print("Raw Temp Value: ");
  Serial.println(tempValue);

  delay(5000); 
}
```

Este é o loop principal do programa, onde todas as operações são realizadas repetidamente. Aqui, os valores dos `sensores` são lidos, mapeados para escalas desejadas e então são exibidos no `display LCD`. Em seguida, são realizadas as ações de controle com base nos valores dos sensores.

## 4. Controle da Temperatura

```cpp
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
  }
```

Nesta seção, o valor da temperatura é exibido no `display LCD` e são tomadas ações com base nesse valor. Se a temperatura for muito alta, um `LED vermelho é ligado` e um sinal sonoro é emitido pelo buzzer. Se a temperatura for alta, um `LED amarelo é ligado` e um sinal sonoro diferente é emitido. Caso contrário, um LED verde é ligado, indicando uma temperatura normal.

## 5. Controle da Umidade

```cpp
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

```

Assim como na seção de controle da temperatura, o valor da umidade é exibido no `display LCD` e são tomadas ações com base nesse valor. Dependendo da umidade, `diferentes LEDs são acionados e diferentes sinais sonoros são emitidos`.

## 6. Controle da Luminosidade

```cpp
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
```

Nesta seção, o valor da luminosidade é exibido no `display LCD` e são tomadas ações com base nesse valor. `Dependendo da luminosidade, diferentes LEDs são acionados e diferentes sinais sonoros são emitidos`.


## Objetivo

### O `objetivo` deste código é `capturar e monitorar informações` relevantes durante as corridas de Fórmula E da equipe `Mahindra`. Para isso, são utilizados sensores para medir a temperatura ambiente, umidade e luminosidade, proporcionando uma visão abrangente das condições climáticas durante as corridas.

### Por meio da leitura desses sensores, o programa pode `alertar a equipe sobre condições críticas`, como temperaturas elevadas, umidade excessiva ou baixa luminosidade, fornecendo insights valiosos para tomada de decisões estratégicas durante as corridas.



## License

### Este projeto é licenciado sob a <strong>[Licença MIT](LICENSE).</strong>
