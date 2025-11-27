# MotionSenser_display
Arduino


      -GND
DHT11 -VCC
      -DATA

Time_delay_adjust  Sensitivity_Adjust
	     HC-SR501
          |      |      |
	Power Output Ground

VSS VDD V0 RS RW E D0 D1 D2 D3 D4 D5 D6 D7 A K
		   LCD1602

 |(1)    |(2)
Potentiometer
      |(3)

5V - +(redline)
GND - -(blueline)
+(redline) - VCC(DHT11)
-(blueline) - GND(DHT11)
DATA(DHT11) - Pin2
+(redline) - Power(HC-SR501)
-(blueline) - Ground(HC-SR501)
Output(HC-SR501) - Pin3
+(redline) - VDD(LCD1602)
	   - A(LCD1602)
	   - |(2)(Potentiometer)
-(blueline) - VSS(LCD1602)
	    - RW(LCD1602)
	    - K(LCD1602)
	    - |(1)(Potentiometer)
V0(LCD1602) - |(3)(Potentiometer)
RS - Pin7
E - Pin8
D4 - Pin9
D5 - Pin10
D6 - Pin11
D7 - Pin12
