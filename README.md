# CMAKE_TEMP

*This is an application to control the temperature of a room between minimum and maximum values set by the user.

*To get an instance of the controller:
        TemperatureControlSystem  room(<min_value>, <max_value>);
        
         APIs:
          room.controlTask(); //the main task analyzing the temperature and command other methods
          room.setMinMaxTemp(<min_value>, <max_value>);
          room.getMaxTemp();
          room.getMinTemp();
          
          room.setCurrentTemp(<value>) // it is a redundant method. it added to set the current temp in GTEST
        
The class has a default constructor to set min and max in meaningful values.
The values passed in max and min if they pass the validity check.


* The app has a GUI class to port in LCD, SERIAL PORT, ...
It is an independent class to make the code more maintainable, reusable, and easy to modify.

* Assume that we get the temperature value from an input, ADC, or Serial port, ...
So it needs to be initialized in the init() function.
in the code, the temperature is got from getCurrentTemp() which returns 0 by default. 
The body must be completed with the input source.



