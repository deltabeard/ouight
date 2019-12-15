# SIM800C

## Commands Routines

### Initialise

```
AT # Sync Serial (only required on auto baud setting which is default)
# Use AT+IPR=<rate> to set baud rate (saved in modem non-voltaile memory).

AT+CMEE=2 # Enables verbose error strings

AT+CFUN=1 # Set to full functionality (probably not required)
AT+CPIN? # Check if SIM card requires a password


AT+COPS? # Get Operator Name
```

### Connect to GPRS

```
# Set bearer settings
AT+SAPBR=3,1, "Contype","GPRS"
AT+SAPBR=3,1, "APN","uk.lebara.mobi"
AT+SAPBR=1,1

# Set APN; use your providers settings. I am not sponsored by this provider.
AT+CSTT="uk.lebara.mobi","web","web"
AT+CIICR # Start wireless connection to GPRS/CSD
AT+CIFSR # Get IP address
AT+CIPSTATUS # Status of GPRS connection
```

### Disconnect from GPRS

```
AT+CIPSHUT # Deactivate GPRS
AT+SAPBR=0,1 # Close bearer 1.
```

### HTTP Send/Receive

```
AT+HTTPINIT
AT+CDNSCFG="1.1.1.1","1.0.0.1" # Configure DNS (used cloudflare here)
AT+HTTPPARA="URL","http://example.com"
AT+HTTPPARA="UA","Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:70.0) Gecko/20100101 Firefox/70.0" # Blend in with the crowd
AT+HTTPPARA="USERDATA","text/plain" # Sending plain text in this example
AT+HTTPDATA=100,10000 # Have 10000ms to send 100Bytes of data after command.
# After 10000 seconds...
AT+HTTPACTION=1 # Make HTTP transaction
# Wait until unsolicited message +HTTPACTION
AT+HTTPREAD # Read response if there was any data returned from server

AT+HTTPTERM # Terminate HTTP session
```

### Get time with NTP

TODO

```
AT+CNTP=pool.ntp.org,0
```
