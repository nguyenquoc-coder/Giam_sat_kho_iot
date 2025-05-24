#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6Ca4LzjDC"
#define BLYNK_TEMPLATE_NAME "lab2"
#define BLYNK_AUTH_TOKEN "tgvh3MSOJ3crMCPA76q20WbUBYT9Y8na"  

#include <WiFi.h>
#include <WiFiClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <DHT.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "tgvh3MSOJ3crMCPA76q20WbUBYT9Y8na";
char ssid[] = "Wokwi-GUEST";
char pass[] = "";
// khai báo các chân cảm biénee
#define DHTPIN 4
#define DHTTYPE DHT22
#define MQ2PIN 33

// các chân led 
#define LED_TEMP 5   // nhiệt
#define LED_HUM 18   //độ ẩm
#define LED_GAS 19   // gas
#define LED_BUTTON 2  // led cảnh báo ở xưởng 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  pinMode(LED_TEMP, OUTPUT);
  pinMode(LED_HUM, OUTPUT);
  pinMode(LED_GAS, OUTPUT);
  pinMode(LED_BUTTON, OUTPUT);
}

void loop() {
  Blynk.run();
  // đọc dữ liệu từ cảm biếnbiến
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int gasValue = analogRead(MQ2PIN);
  float gasPercent = map(gasValue, 0, 4095, 0, 100);// quy đổi -> %
  Serial.print("Temp: "); Serial.print(temp); Serial.println("°C");
  Serial.print("Humidity: "); Serial.print(hum); Serial.println("%");
  Serial.print("Gas Level: "); Serial.print(gasPercent); Serial.println("%\n");
  // đẩy dl lên blynk 
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, hum);
  Blynk.virtualWrite(V2, gasPercent);
  // đèn sáng khi nhiệt độ vượt quá ngưỡng an toàn 
  if (temp > 25 || temp < 5) {
    Blynk.virtualWrite(V5, HIGH);
    digitalWrite(LED_TEMP, HIGH);
    Blynk.logEvent("cảnh báo nhiệt độ ", "nhiệt độ không thích hợp");
  } else {
    Blynk.virtualWrite(V5, LOW);
    digitalWrite(LED_TEMP, LOW);
  }
  // độ ẩm 
  if (hum > 60 || hum < 30) {
    Blynk.virtualWrite(V6, HIGH);
    digitalWrite(LED_HUM, HIGH);
    Blynk.logEvent("cảnh báo dộ ẩm ", "Độ ẩm không đúng");
  } else {
    Blynk.virtualWrite(V6, LOW);
    digitalWrite(LED_HUM, LOW);
  }
  // gasgas
  if (gasPercent >= 21) {
    Blynk.virtualWrite(V4, HIGH);
    digitalWrite(LED_GAS, HIGH);
    Blynk.logEvent("cảnh báo khí gas", "Có thể có khí lạ (độc)");
  } else {
    Blynk.virtualWrite(V4, LOW);
    digitalWrite(LED_GAS, LOW);
  }

  delay(2000); 
}
// bật công tắc làm sáng đèn ở xưởng
BLYNK_WRITE(V3) {
  int buttonState = param.asInt();
  digitalWrite(LED_BUTTON, buttonState);
}
