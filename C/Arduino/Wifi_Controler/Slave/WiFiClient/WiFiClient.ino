#include <ESP8266WiFi.h>

#define COMMAND_BUFF_SIZE 100
#define NUMBER_OF_RELAY 4
#define ON 1
#define OFF 0
/* Command string */
#define RELAY_1_ON "turn on relay one"
#define RELAY_1_OFF "turn off relay one"
// #define RELAY_2_ON  "turn on relay one"
// #define RELAY_2_OFF "turn off relay one"
// #define RELAY_3_ON  "turn on relay one"
// #define RELAY_3_OFF "turn off relay one"
// #define RELAY_4_ON  "turn on relay one"
// #define RELAY_4_OFF "turn off relay one"

/*================================================================================================*/
/* Biến global */
// Phần configure của Wifi
const char *ssid = "ThinhHome";     // Tên Wifi
const char *password = "123456789"; // Mật khẩu Wifi

/* Phần lưu các trạng thái của command từ PC */
char command_buff[COMMAND_BUFF_SIZE];                   // Nơi chứa tin nhắn của PC gửi xuống
uint16_t cmd_buf_idx = 0;                               // Biến chứa index của buffer
char compare_buff[COMMAND_BUFF_SIZE];                   // Nơi chứa command nhận được, dùng để
                                                        // compare với các lệnh điều khiển
bool relay_status[NUMBER_OF_RELAY] = {0};               // Nơi chứa trạng thái các relay điều khiển
char relay_status_string[NUMBER_OF_RELAY + 1] = "0000"; // Nơi chưa string của relay status

/*================================================================================================*/
/* Khai báo Prototype */
bool check_pc_command();
void send_data_to_server();
void check_and_update_cmd_list();

/*================================================================================================*/
/* Setup phần cứng trước khi vào vòng lặp*/
void setup()
{
  Serial.begin(115200);
  delay(1000);

  Serial.println("Connecting to server\n");

  // Setup ESP8266 ở dạng STATION (WiFi-client)
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Đợi kết nối Wifi thành công
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.printf(".");
    delay(500);
  }

  // In ra màn hình sau khi đã kết nối thành công
  Serial.println("\nWifi is connected!\n");
}

/*================================================================================================*/
/* Vòng lặp chính */
void loop()
{

  /* Kiểm tra xem có thông tin từ PC gửi xuống hay không */
  if (check_pc_command()) // Nếu có command gửi xuống
  {
    check_and_update_cmd_list(); // Update lại danh sách trạng thái các relay
  }

  /* Gửi thông tin đó đến server để thực thi */
  send_data_to_server();

  /* Delay 500 ms */
  delay(500);
}

/*================================================================================================*/
/* Nội dung các hàm cần đã khai báo */

/* Hàm check tin nhắn gửi đến từ máy tính */
bool check_pc_command()
{
  if (Serial.available() > 0)
  {
    while (Serial.available() > 0)
    {
      char temp = Serial.read();
      /* Khi không phải là kí tự kết thúc chuỗi thì dồn kí tự vào mảng */
      if (temp != '\r')
      {
        command_buff[cmd_buf_idx++] = temp;
      }
      /* Ngược lại thêm kí tự kết thúc string vào buffer để so sánh */
      else
      {
        command_buff[cmd_buf_idx] = '\0';
        cmd_buf_idx = 0;
        strcpy(compare_buff, command_buff);
        return true;
      }
    }
  }
  return false;
}

/* Hàm kiểm tra xem lệnh gửi xuống có hợp lệ hay không và cập nhật lại bảng relay status */
void check_and_update_cmd_list()
{
  if (strcmp(RELAY_1_ON, compare_buff) == 0)
  {
    relay_status[0] = ON;
    relay_status_string[0] = '1';
  }
  if (strcmp(RELAY_1_OFF, compare_buff) == 0)
  {
    relay_status[0] = OFF;
    relay_status_string[0] = '0';
  }
  /* Thêm vào cho các relay khác */
}

/* Hàm truyền command đến server */
void send_data_to_server()
{
  // Sử dụng class WiFiClient để tạo kết nối TCP
  WiFiClient client;
  const char *host = "192.168.4.1";
  const int httpPort = 80;

  // Try to connect to server
  if (!client.connect(host, httpPort))
  {
    Serial.println("Connection failed!");
    return;
  }

  // Tạo URL để yêu cầu cập nhật giá trị trên board master.
  // Data gửi đi có dạng /data/?command_from_pc=0000
  String url = "/data/";
  url += "?command_from_pc=";
  // relay_status_string là biến chưa giá trị của các relay ở dạng kí tự
  url += relay_status_string;

  // Hàm gửi yêu cầu đến server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  // Check xem client có còn kết nối hay không nếu không thì sẽ đóng kết nối với
  // board server
  unsigned long timeout = millis();
  while (client.available() == 0)
  {
    if (millis() - timeout > 5000)
    {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
}
