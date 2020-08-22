#include<Arduino_FreeRTOS.h>

// use serial monitor to print the two task based on priorities

//step 1
void Task_button(void *param);
void Task_print(void *param);

//step 2
TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;

//

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(8,INPUT_PULLUP);
  xTaskCreate(Task_button, "Task1", 100, NULL, 1, &Task_Handle1);
  xTaskCreate(Task_print, "Task2", 100, NULL, 1, &Task_Handle2);
}

void loop() {
  // put your main code here, to run repeatedly:
  // we dont put code here for this problem...

}


// step 3
// task_buton fuction details

void Task_button(void *param)
{
  (void) param;
  while (1)
  {
    if(digitalRead(8)==0)
    {
      while(digitalRead(8)==0)
      digitalWrite(13,LOW);
    }
    else digitalWrite(13,HIGH);//turn OFF
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}


// task2 fuction details

void Task_print(void *param)
{
  (void) param;
  while (1)
  {
    Serial.println("Taskprint");
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }

}
