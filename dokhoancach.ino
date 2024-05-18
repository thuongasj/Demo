//khai báo các chân của cảm biến siêu âm
int trigPintrai = 2;
int echoPintrai = 3;
int trigPingiua = 9;
int echoPingiua = 13;
int trigPinphai = 6;
int echoPinphai = 5;
int dorongxungtrai, dorongxunggiua, dorongxungphai;
float kcL, kcM, kcR;
// khai báo chân cho cảm biến hồng ngoại
int hongngoai = A0;
int h;
int a = 0;
//khai báo các chân của động cơ
int in1 = 12;
int in2 = 8;
int in3 = 7;
int in4 = 4;
int e1 = 10;
int e2 = 11;
void setup()
{
  Serial.begin(9600);
  pinMode(trigPintrai,OUTPUT);
  pinMode(echoPintrai,INPUT);
  pinMode(trigPingiua,OUTPUT);
  pinMode(echoPingiua,INPUT);
  pinMode(trigPinphai,OUTPUT);
  pinMode(echoPinphai,INPUT);
  pinMode(hongngoai,INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}
void loop()
{
  dokhoangcachtrai();
  dokhoangcachgiua();
  dokhoangcachphai();
  dohongngoai();
  if(h==HIGH)
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    analogWrite(e1,150);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(e2,150);
    a = 1;
  }
  if (a==0 && h==LOW && (kcL<=20 && kcM>20 && kcR<=20) || a==0 && h==LOW &&(kcL>20 && kcM>20 && kcR>20))
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(e1,150);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    analogWrite(e2,150);
  }
  if(a==1 && h==LOW || h==LOW && (kcL<=20 && kcM<=20 && kcR>20) || h==LOW && (kcL<=20 && kcM<=20 && kcR>20) || h==LOW && (kcL<=20 && kcM>20 && kcR > 20) || kcL<=20 && kcM>20 && kcR>20)
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(e1,150);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(e2,150);
    a = 0;
  }

  if(h==LOW && (kcL>20 && kcM<=20 && kcR<=20) || h==LOW && (kcL>20 && kcM>20 && kcR<=20) || h==LOW && (kcL>20 && kcM<=20 && kcR>20))
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    analogWrite(e1,150);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    analogWrite(e2,150);
  }



}
void dokhoangcachtrai()
{
  //phat xung tu chan trig
  digitalWrite(trigPintrai,LOW); //Tat chan trig
  delayMicroseconds(2);
  digitalWrite(trigPintrai,HIGH); //Phat xung tu chan trig
  delayMicroseconds(10);
  digitalWrite(trigPintrai,LOW); //Tat chan trig
  //tinh thoi gian
  dorongxungtrai = pulseIn(echoPintrai,HIGH); //Đo độ rộng xung HIGH ở chân echo
  kcL = dorongxungtrai * 0.034/2.0;  //Tinh khoang cach den vat
  Serial.print("khoancachtrai: ");
  Serial.println(kcL);
  delay(10);
}
void dokhoangcachgiua()
{
  digitalWrite(trigPingiua,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPingiua,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPingiua,LOW);
  dorongxunggiua = pulseIn(echoPingiua,HIGH);
  kcM = dorongxunggiua * 0.034/2.0; 
  Serial.print("khoancachgiua: ");
  Serial.println(kcM);
  delay(10);
}
void dokhoangcachphai()
{
  digitalWrite(trigPinphai,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinphai,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinphai,LOW);
  dorongxungphai = pulseIn(echoPinphai,HIGH);
  kcR = dorongxungphai * 0.034/2.0; 
  Serial.print("khoancachphai: ");
  Serial.println(kcR);
  delay(10);
}
void dohongngoai()
{
  h = digitalRead(hongngoai);
  Serial.println(h);
}