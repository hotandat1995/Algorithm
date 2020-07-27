#!/bin/bash

make clean_1
make wp77xx

update mqttService.wp77xx.update
update mqttPublisher.wp77xx.update
