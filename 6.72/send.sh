#!/bin/bash

#
# YOU NEED TO REPLACE THE IP, WITH YOUR PS4's IP ADDRESS 
# AND YOU NEED TO REPLACE THE PORT, WITH THE ONE THE BIN LOADER DISPLAYED
#

echo "> Sending the Payload to PS4"
socat -u FILE:ps4debug.bin TCP:192.168.1.141:9020
echo "> Sent!"