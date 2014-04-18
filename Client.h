#ifndef client_h
#define client_h

#include "Print.h"
#include "Stream.h"
#include "IPAddress.h"

class Client : public Stream {

public:

  //ABSTRACT CLASS
  
  virtual int connect(IPAddress ip, uint16_t port) = 0;
  virtual int connect(const char *host, uint16_t port) = 0;
  virtual size_t write(uint8_t) = 0;
  virtual size_t write(const uint8_t *buf, size_t size) = 0;
  virtual int available() = 0;
  virtual int read() = 0;
  virtual int read(uint8_t *buf, size_t size) = 0;
  virtual int peek() = 0;
  virtual void flush() = 0;
  virtual void stop() = 0;
  virtual uint8_t connected() = 0;
  virtual operator bool() = 0;

  
/*
  //FALSE DECLARED CLASS
  virtual int connect(IPAddress ip, uint16_t port);
  virtual int connect(const char *host, uint16_t port);
  virtual size_t write(uint8_t);
  virtual size_t write(const uint8_t *buf, size_t size);
  virtual int available();
  virtual int read();
  virtual int read(uint8_t *buf, size_t size);
  virtual int peek();
  virtual void flush();
  virtual void stop();
  virtual uint8_t connected();
  virtual operator bool();
*/
  
protected:
  uint8_t* rawIPAddress(IPAddress& addr) { 
    return addr.raw_address(); 
  };

};

#endif