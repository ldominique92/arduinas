// Leitura do sensor DHT 

#include "DHT.h"

#define DHTPIN 2     // Porta escolhida

// Estamos usando o modelo de componente DHT22
// Poderíamos usar DHT11 ou DHT21
#define DHTTYPE DHT22

// COMO MONTAR A PLACA:
// Conectar pino 1 do sensor (esquerda) na porta de alimentação 5V ou 3.3V.
// Conectar pino 2 na porta com o número de DHTPIN
// Conectar pino 4 (direita) na porta GND (terra)
// Conectar um  resistor de 10K do pino 2 (dados) até o pino 1 (energia)

// Inicializar a biblioteca do sensor DHT com o valor da porta e o modelo utilizado
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // inicializa a tela
  Serial.begin(9600);
  Serial.println("Teste do sensor DHT22 (Umidade de temperatura)");

  // inicializa leitura do sensor usando biblioteca
  dht.begin();
}

// TODO: pensar nas variáveis de parametrização para serem enviadas pela interface

void loop() {
  // Tempo de intervalo entre medições. Pode ser parametrizado.
  delay(2000);

  // Leitura do sensor
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  //float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  //float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.println();

  if(h > 50)
    Serial.println("Humidade alta!");
}
