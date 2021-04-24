#include <Steelsquid.h>
#include <FeatherRfm9X.h>

#define FREQUENCY 434.0


FeatherRfm9X rfm9X = FeatherRfm9X(FREQUENCY);


//##########################################################################################
void setup() {
  Steelsquid:init();
  rfm9X.init();
}


//##########################################################################################
void loop() {
  // Check if something to receive
  if(rfm9X.available()){
    // Read the package
    int packageType = rfm9X.receive();
        
    if(packageType == TYPE_REPETER_PING){
      byte bytes[1];
      bytes[0] = FeatherRfm9X::batteryPercent();
      rfm9X.transmitRepeterPong(bytes, 1);
    }
    else if(packageType != TYPE_NONE){
      rfm9X.repetePackage();
    }
  }
}
