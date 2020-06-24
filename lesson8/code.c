
#define NOTE_C4  262  //编译器将在编译时将所有提及的NOTE_C4替换为值262
#define NOTE_G3  196  //编译器将在编译时将所有提及的NOTE_G3替换为值196
#define NOTE_A3  220  //编译器将在编译时将所有提及的NOTE_A3替换为值220
#define NOTE_B3  247  //编译器将在编译时将所有提及的NOTE_B3替换为值247
#define NOTE_C4  262  //编译器将在编译时将所有提及的NOTE_C4替换为值262



int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};          //定义一个整型数组，用来表示频率

.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};//定义一个整型数组，包含的数据与声音的持续时间有关

void setup() {
 
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    //for循环，共执行8次内部代码，thisNote的值累加
    
    int noteDuration = 1000 / noteDurations[thisNote];
    //持续时间的计算
    tone(8, melody[thisNote], noteDuration);
    //在引脚8上生成频率为melody[thisNote]的方波，持续时间为noteDuration
    
    int pauseBetweenNotes = noteDuration * 1.30;
    //暂停时间的计算
    delay(pauseBetweenNotes);
    //程序暂停时长为pauseBetweenNotes
    noTone(8);
    //停止产生由引脚8触发的方波
  }
}

void loop() {
  // 没必要进行循环
}