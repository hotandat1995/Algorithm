#include "legato.h"
#include "interfaces.h"

#define MQTT_CLOUD 1

static le_timer_Ref_t Publisher_timer;
static const int32_t keepAlive = 60;
static const int32_t QoS = 0;

static const char Key_Test[] = "Testing";
static const char Value_Test[] = "{\"hubID\":\"a1546789\"}";

#ifdef MQTT_CLOUD
const char password[] = "123456";
static const char brokerURL[] = "m16.cloudmqtt.com";
static const int32_t portNumber = 11933;
#else
const char password[] = "760ed6d5-0c70-4540-9b84-55ec10f93c51";
static const char brokerURL[] = "mqtt.tago.io";
static const int32_t portNumber = 8883;
#endif

static void Publisher_timer_Handler(le_timer_Ref_t timer)
{
  static int32_t errCode;
  // if (!mqttSer_GetConnectionState())
  // {
  //   LE_ERROR("Not connected!");
  //   return;
  // }
  LE_DEBUG("Push data to cloud");
  mqttSer_Send(Key_Test, Value_Test, &errCode);
}

COMPONENT_INIT
{
  LE_INFO("---------------Publisher initialize---------------");

  /* Reg the MQTT profile */
  mqttSer_Config(brokerURL, portNumber, keepAlive, QoS);
  mqttSer_Connect(password);

  /* Create and setup timer to auto push data */
  LE_INFO("Create Timer");
  Publisher_timer = le_timer_Create("Test Publisher data");
  le_timer_SetMsInterval(Publisher_timer, 5 * 1000);
  le_timer_SetRepeat(Publisher_timer, 0);
  le_timer_SetHandler(Publisher_timer, Publisher_timer_Handler);
  le_timer_Start(Publisher_timer);

  LE_INFO("--------------Publisher initialized---------------");
}