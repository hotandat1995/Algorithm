#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define NUMBER_OF_RELAY 4
#define ON 1
#define OFF 0
/* Đặt tên các chân*/
#define RELAY_1_PIN 5
#define RELAY_2_PIN 4
#define RELAY_3_PIN 14
#define RELAY_4_PIN 12

/*================================================================================================*/
/* Biến global */
// Phần configure của Wifi
const char *ssid = "ThinhHome";
const char *password = "123456789";
ESP8266WebServer server(80);

// Các biến quản lý

/*================================================================================================*/
/* Khai báo Prototype */
void handleSentVar();

/*================================================================================================*/
/* Setup phần cứng trước khi vào vòng lặp*/
void setup()
{
  Serial.begin(115200);
  delay(1000);

  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  /* When the server receives a request with /data/ in the string then run
  the handleSentVar function */
  server.on("/data/", HTTP_GET, handleSentVar);
  server.begin();
  Serial.println("Server start listening!");

  /* Khởi tạo các chân I/O để control các relay */
  pinMode(RELAY_1_PIN, OUTPUT);   // set pin to output
  digitalWrite(RELAY_1_PIN, HIGH); // turn off pullup resistors
  pinMode(RELAY_2_PIN, OUTPUT);   // set pin to output
  digitalWrite(RELAY_2_PIN, HIGH); // turn off pullup resistors
  pinMode(RELAY_3_PIN, OUTPUT);   // set pin to output
  digitalWrite(RELAY_3_PIN, HIGH); // turn off pullup resistors
  pinMode(RELAY_4_PIN, OUTPUT);   // set pin to output
  digitalWrite(RELAY_4_PIN, HIGH); // turn off pullup resistors

  delay(100);
}

/*================================================================================================*/
/* Vòng lặp chính */
void loop()
{
  server.handleClient();
}

/*================================================================================================*/
/* Nội dung các hàm cần đã khai báo */

/* Hàm xử lý khi nhận được */
void handleSentVar()
{
  if (server.hasArg("command_from_pc"))
  {
    // This is the variable sent from the client
    int readingInt = server.arg("command_from_pc").toInt();
    char readingToPrint[6]; //Buffer đùng để chứa string convert

    /* Convert giá trị nhận được từ request từ integer sang string */
    itoa(readingInt, readingToPrint, 10);

    /* Cập nhật lại trạng thái của các relay */
    /*========================================================================*/
    /* Relay 1*/
    if (readingToPrint[1] != '1')
      digitalWrite(RELAY_1_PIN, HIGH);
    else
      digitalWrite(RELAY_1_PIN, LOW);

    /* Relay 2*/
    if (readingToPrint[2] != '1')
      digitalWrite(RELAY_2_PIN, HIGH);
    else
      digitalWrite(RELAY_2_PIN, LOW);

    /* Relay 3*/
    if (readingToPrint[3] != '1')
      digitalWrite(RELAY_3_PIN, HIGH);
    else
      digitalWrite(RELAY_3_PIN, LOW);

    /* Relay 4*/
    if (readingToPrint[4] != '1')
      digitalWrite(RELAY_4_PIN, HIGH);
    else
      digitalWrite(RELAY_4_PIN, LOW);
    /*========================================================================*/

    // server.send(200, "text/html", "Data received");
    // In ra serial port để debug
    Serial.print("The number is: ");
    Serial.println(readingToPrint);
  }
}
