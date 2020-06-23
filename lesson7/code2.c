#include <MsTimer2.h>     //定时器库的头文件
 
int income = 0; //计数值
 
//中断服务程序
void onTimer()
{
    digitalWrite(4,income&0x1);
    digitalWrite(5,(income>>1)&0x1);
    digitalWrite(6,(income>>2)&0x1);
    digitalWrite(7,(income>>3)&0x1);
  if(income<=9){income++;}
  if(income>9){income=0;}
  	delay(1);
}
int pinInterrupt = 2; //接中断信号的脚
 
void onChange()
{
   income=0;
}
 
 
void setup()
{ 
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  pinMode( pinInterrupt, INPUT);//设置管脚为输入
   
   //Enable中断管脚, 中断服务程序为onChange(), 监视引脚变化
   attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
  MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时
}
 
void loop()
{
  
}
