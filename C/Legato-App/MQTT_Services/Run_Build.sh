#!/bin/bash

make clean_1
make wp77xx

update mqttService.wp77xx.update
update mqttPublisher.wp77xx.update
update mqttSubcriber.wp77xx.update

# mkapp -v -t wp77xx mqttSubcriber.adef
# update mqttSubcriber.wp77xx.update