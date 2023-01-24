#include <Arduino.h>
#include <src/ESP_LinkedList.h>

struct testStruct{
    int randomNum;
};

ESP_LinkedList<testStruct> list;


void testStruct(){
    for (size_t i = 0; i < 10; i++){
        testStruct newStruct;
        newStruct.randomNum = esp_random();
        list.add(newStruct);
        Serial.printf(
            "Added struct random number at index %d is: %d\n",
            i,
            newStruct.randomNum
        );
    } 
}

void consumeTestStruct(){
    for (size_t i = 0; i < list.size(); i++){
        testStruct consumedStruct = list.get(i);
        Serial.printf(
            "Consumed struct random number at index %d is: %d\n",
            i,
            consumeTestStruct.randomNum
        );
    }
}

void setup(){
    Serial.begin(115200);
    vTaskDelay(1000); // <-- Sanity delay for Serial connection.
    testStruct();
    consumeTestStruct();
}

void loop(){

}