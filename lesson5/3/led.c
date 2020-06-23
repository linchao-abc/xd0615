#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
  
 
   
  Serial.begin(9600);
}
byte income[100]={0};
int i=0;
int j=0;

int a=0,k=0;
void loop()
{
  if(Serial.available()>0)
  {
    Serial.readBytes(income,100);
  }
  for(j=0;income[j]>0;j++)
  {
    
    if(income[j]<=0)
    {
    	break;
    }
  }
  
  
  for(k=0;k<=j-4;++k)
  {
  	for(i=k;i<k+4;++i)
  	{
  		
  	
      	//income[i]=income[i]-'0';
      	digitalWrite(S1+i-k,LOW);
    	digitalWrite(2,income[i]&0x1);
    	digitalWrite(3,(income[i]>>1)&0x1);
    	digitalWrite(4,(income[i]>>2)&0x1);
    	digitalWrite(5,(income[i]>>3)&0x1);
      	digitalWrite(S1+i-k,HIGH);
  		delay(1);
        //income[i]=income[i]+'0';
        
   
  	}
    
  delay(1000);
  }
  
  for(i=0;i<100;++i)
  {
    income[i]=0;
  }
}
	