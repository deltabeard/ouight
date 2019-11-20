# *ouight?*
*Y**ou** all r**ight** mate?* This is a feature phone built with free software.

## Requirements

- Portable and modular
- Only using GPLv3 free software
- Simple

### Aims

List of aims for first release *1.0.0*, in no particular order.

- Voice Calling
- SMS
- Airplane Mode using hardware switch for modem power off
- Standby time of *at least* 7 days
- T9 keypad input
- Internet communication with [TLS 1.3 (via WolfSSL)](https://www.wolfssl.com/docs/tls13/) only, for:
  - [DNS over HTTPS](https://developers.cloudflare.com/1.1.1.1/dns-over-https/) (I plan on using existing code)
  - [Roughtime Client](https://developers.cloudflare.com/roughtime/docs/) (I plan on writing library - can't find suitable C library.)
  - [IMAPS email client](https://www.etpan.org/libetpan.html) (I plan on using existing code)

### Future Suggested Aims

List of aims to be implemented in future releases, in no particular order.

- Internet communication via TLS 1.3 only, for:
  - Matrix chat client
  - [SMTPS](https://github.com/somnisoft/smtp-client) for sending email
- Speex encoding and decoding
- Lossy (Opus or Vorbis, and MP3) and lossless (FLAC) music decoding
