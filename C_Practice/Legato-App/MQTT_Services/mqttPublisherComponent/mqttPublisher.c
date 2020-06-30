#include "legato.h"
#include "interfaces.h"

static le_timer_Ref_t Publisher_timer;

static const char brokerURL[] = "m16.cloudmqtt.com";
static const int32_t portNumber = 11933;
static const int32_t keepAlive = 60;
static const int32_t QoS = 0;

static const char Key_Test[] = "Testing";
static const char Value_Test[] = "123456";

static void Publisher_timer_Handler(le_timer_Ref_t timer)
{
    static int32_t errCode;
    LE_INFO("Push data to cloud");
    mqttSer_Send(Key_Test, Value_Test, &errCode);
}

COMPONENT_INIT
{
    LE_INFO("---------------Publisher initialize---------------");

    /* Create and setup timer */
    LE_INFO("Create Timer");
    Publisher_timer = le_timer_Create("Test Publisher data");
    le_timer_SetMsInterval(Publisher_timer, 5 * 1000);
    le_timer_SetRepeat(Publisher_timer, 0);
    le_timer_SetHandler(Publisher_timer, Publisher_timer_Handler);
    le_timer_Start(Publisher_timer);

    /* Reg the MQTT profile */
    mqttSer_Config(brokerURL, portNumber, keepAlive, QoS);
    const char password[] = "123456";
    mqttSer_Connect(password);
}