//步兵接收遥控器补弹丸指令，先打开舵机，后启动发射管
//步兵跟补给站采用红外通信,即步兵红外发射端点亮（用手机摄像头观看），补给站红外接收端接受发射端的信号，即可给步兵补弹丸
#include <Servo.h>
Servo myservo;
Servo myservo1;
int pos=0;
int IN=3;  //检测stm32引脚高低电平
int LED=13;//假设为发射管
void setup()
{
  myservo.attach(9);
  myservo1.attach(10);
  pinMode(LED,OUTPUT);
  pinMode(IN,INPUT);
  digitalWrite(IN, HIGH);
}
void loop()
{
	if(digitalRead(IN)==0)
    {
        delay(100);
        if(digitalRead(IN)==0)
       {
        myservo.write(45); 
        myservo1.write(45);
        delay(500); 
        digitalWrite(LED, HIGH); 
       }
    }

    if(digitalRead(IN)==1)
    {
        delay(100);
        if(digitalRead(IN)==1)
       {
        digitalWrite(LED, LOW);
        delay(500); 
        myservo.write(90); 
        myservo1.write(90);
       }
}



}
