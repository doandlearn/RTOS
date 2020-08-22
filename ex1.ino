#include<Arduino_FreeRTOS.h>

// use serial monitor to print the two task based on priorities

//step 1
void Task1(void *param);
void Task2(void *param);

//step 2
TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;

//

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xTaskCreate(Task1, "Task1", 100, NULL, 1, &Task_Handle1);
  xTaskCreate(Task2, "Task1", 100, NULL, 2, &Task_Handle2);
}

void loop() {
  // put your main code here, to run repeatedly:
  // we dont put code here for this problem...

}


// step 3
// task1 fuction details

void Task1(void *param)
{
  (void) param;
  while (1)
  {
    Serial.println("Task1");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}


// task2 fuction details

void Task2(void *param)
{
  (void) param;
  while (1)
  {
    Serial.println("Task2");
    vTaskDelay(1500/portTICK_PERIOD_MS);
  }

}
