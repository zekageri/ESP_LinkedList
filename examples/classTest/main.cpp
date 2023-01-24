#include <Arduino.h>
#include <src/ESP_LinkedList.h>

class testClass{
    private:
        int randomNum;
    public:
        testClass(int newRandomNum){
            randomNum = newRandomNum;
        }
        int getNum(){
            return randomNum;
        }
};

ESP_LinkedList<testClass> list;


void testClass(){
    for (size_t i = 0; i < 10; i++){
        testClass newClass = new testClass(esp_random());
        list.add(newClass);
        Serial.printf(
            "Added class random number at index %d is: %d\n",
            i,
            newClass.getNum()
        );
    } 
}

void consumeTestClass(){
    for (size_t i = 0; i < list.size(); i++){
        testClass consumedClass = list.get(i);
        Serial.printf(
            "Consumed class random number at index %d is: %d\n",
            i,
            consumedClass.randomNum
        );
    }
}

void setup(){
    Serial.begin(115200);
    vTaskDelay(1000); // <-- Sanity delay for Serial connection.
    testClass();
    consumeTestClass();
}

void loop(){

}