<h1>Fan-Controller-System</h1>
  <p></p>
  <h2>Project Description</h2>
    <p>
     <br>The project is a system that controls the speed of a fan depending on the temperature.</br>
    </p>
  <h2>Project Specifications</h2>
    <p>
     <br>The LM35 temperature sensor will give continuous analog output corresponding to the temperature sensed by it. This analog signal is given to the ADC, which            converts the analog values to digital values.
     </br>
     <br>The digital output of the ADC is equivalent to the sensed analog voltage.</br>
     <br>In order to get the temperature from the sensed analog voltage, we need to perform some calculations in the programming for the microcontroller.</br>
     <br>Once the calculations are done by the microcontroller according to the logic, the temperature is displayed on the LCD.</br>
     <br>The main principle of the circuit is to switch on/off the fan connected to DC motor based on temperature value.</br>
     <br>The DC-Motor rotates in clock-wise direction or stopped based on the fan state.</br>
     <br>The LCD displays the temperature value and the fan state continuously.</br>
     <br>The DC-Motor speed is controlled using PWM signal generated from Timer0.</br>
     <br>The project is designed and implemented based on the layered architecture model.</br>
    </p>
  <h2>Project Components</h2>
    <h3>Micrcontroller</h3>
      <p>
       <br>- ATmega32</br>
      </p>
    <h3>Drivers</h3>
      <p>
       <br>- ADC</br>
       <br>- LCD</br>
       <br>- PWM</br>
       <br>- GPIO</br>
       <br>- DC-Motor</br>
       <br>- LM35 Sensor</br>
      </p>
    <h3>Hardware</h3>
      <p>
       <br>- 2x16 LCD</br>
       <br>- DC-Motor</br>
       <br>- L2935 Chip</br>
       <br>- LM35 Temperature Sensor</br>
      </p>
  <h2>Files</h2>
    <p>
     <br>main.c : This file contains the code of the project.</br>
     <br>adc.h : This file contains the code of the project.</br>
     <br>adc.c : This file contains the code of the project.</br>
     <br>lcd.h : This file contains the code of the project.</br>
     <br>lcd.c : This file contains the code of the project.</br>
     <br>pwm.h : This file contains the code of the project.</br>
     <br>pwm.c : This file contains the code of the project.</br>
     <br>gpio.h : This file contains the code of the project.</br>
     <br>gpio.c : This file contains the code of the project.</br>
     <br>dc-mototr.h : This file contains the code of the project.</br>
     <br>dc-mototr.c : This file contains the code of the project.</br>
     <br>lm35_sensor.h : This file contains the code of the project.</br>
     <br>lm35_sensor.c : This file contains the code of the project.</br>
    </p>
