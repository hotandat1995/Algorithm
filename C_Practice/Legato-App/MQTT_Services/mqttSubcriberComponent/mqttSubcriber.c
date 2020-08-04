#include "legato.h"
#include "interfaces.h"

// const char topicName[128]="352653090008913/messages/json";
// char key[128];
// char value[128];
// char timestamp[16];

mqtt_IncomingMessageHandlerRef_t InComeMessage;

COMPONENT_INIT
{
  LE_INFO("---------------Subcriber initialize---------------");
  InComeMessage = mqttSer_AddIncomingMessageHandler(InComeMessage);

  LE_INFO("--------------Subcriber initialized---------------");
}