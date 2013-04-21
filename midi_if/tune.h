#ifndef _TUNE_H_
#define _TUNE_H_

#include <stdint.h>

#define MAX_TUNE 128

using namespace std;

class key {
  
  private:
    uint8_t _channel;
    uint8_t _note;

  public:
    key() {
      _channel = 1<<7;
      _note =  1<<7;
    }
    key(uint8_t channel, uint8_t note): _channel(channel), _note(note){};
    ~key(){};
    
    inline bool operator== (const key& a) {
      return (_channel == a._channel) && (_note == a._note);
    };

    inline bool operator != (const key& a) {
      return (_channel != a._channel) || (_note != a._note);
    };

};

class tune {

  private:
    key _data[MAX_TUNE];
    uint16_t _cpt_add;

  public:
    tune(){
      _cpt_add = 0;
    };
    ~tune(){};

    uint8_t add_tune(uint8_t channel, uint8_t note);
    uint8_t remove_tune(uint8_t channel, uint8_t note);
    uint8_t find_tune (uint8_t channel, uint8_t note);
   
};

#endif