Zelio Soft 2

==================================================================

*************************** Version 4.1 ************************
Firmware FBD v4.01
Firmware LADDER v4.01
Firmware SR2COM01 v1.0.12

*************************** Version 3.1 ************************
Firmware FBD v3.09
Firmware LADDER v3.09
Firmware SR2COM01 v1.0.12

- IMPORTANT : During firmware update operation (through memory card SR2MEM02 or PC), module power supply must not be 
interrupted before firmware transfer is completed. In case of power loss during firmware transfer, product could seem to be damaged: loss of display (on LCD controller) or flashing LED (on controller without display).
In this instance switch on module power supply and repeat firmware transfer operation (Menu: Module/ Update module firmware).

- IMPORTANT : Connection of extensions must be done with power disconnected to the module. Please refer to the instruction sheet provided with the extension.

- Comments on 'E-mail via SMS' sending:
SR2COM01 communication interface builds its messages using the following frame:
<Recipient email adress><remote station name> <date hour> <alarm message subject><alarm message body>
(Above Characters '<' et '>' are only used to delimit frame fields, they are not included in the sent frame).
Therefore, you have to obey Email service syntax related to the selected provider. Include these specifics characters in directories (recipients and/or remote stations) and/or message (subject and/or body).

- SR2COM01 communication interface must be reinitialized at each link type change (Cable SR2CBL01 or SR2CBL07).
Program transfer or Module run can't be proceeded until LED flashing is not achieved.

- For SR2COM01 communication interface used on a phone network requiring prefix, include additional characters in phone number syntax (recipients and/or remote station).

- In order to send commands from ZelioLogicAlarm, phone number syntax (international format, prefix) must match with those used in ZelioSoft2 remote station configuration.   

- In order to receive alarm message from SR1COM01 communication interface on ZelioLogic Alarm, PC Modem must be configured with following parameters: 9600 Bauds,8 bits and no parity 

*************************** Version 2.4 ************************
Firmware FBD v2.18
Firmware LADDER v2.19

*************************** Version 2.2 ************************
The clock for SR2 and SR3 modules works differently to 
to that for SR1 modules. If the clock is set to ON
on Monday at 11pm and set to OFF on Monday at 1am, it does not 
switch OFF on Tuesday at 1am but on the following Monday 
at 1am. If no other command has been executed, 
the clock remains set to ON all the other days of the 
week. You must check that the clocks are working using 
using the help function when transferring programs running on 
SR1 modules to SR2 and SR3 modules.

The CHANGE D/T and CHANGE SUMM/WINT menus as well as the 
PARAMETER menu in LADDER mode only are no longer password- 
protected.

*************************** Version 2.1 ************************
Firmware FBD v2.16
Firmware LADDER v2.16

*************************** Version 2.0 ************************
This version can be used to program automation applications 
either by using LADDER diagrams as with Zelio Soft or by 
using FBD (Functional Block Diagram) language.

Online help can be accessed by clicking on the question 
marks in the toolbars, the function block configuration 
windows or by using the F1 key on the keyboard in the 
designated menus (reverse video).

This version provides assistance with transferring programs 
running on SR1 smart relays to 
SR2 and SR3 smart relays. Only programs generated using version
 1.5 of Zelio Soft are supported. To make the transfer, simply 
open the .zel program in Zelio Soft 2. The software 
workshop makes the following matches:

   Zelio Logic 1    Zelio Logic 2 
   SR1 B121JD  to  SR2 B121JD   (2 additional mixed inputs)
   SR1 A101BD  to  SR2 A101BD   
   SR1 B121BD  to SR2 B121BD   (2 additional mixed inputs)
   SR1 B122BD  to SR2 B122BD   (2 additional mixed inputs)
   SR1 B101B  to SR2 B121B  (2 additional discrete inputs)
   SR1 A101FU  to SR2 A101FU
   SR1 B101FU  to SR2 B121FU  (2 additional discrete inputs)
   SR1 A201BD  to SR2 A201BD  (2 additional mixed inputs)
   SR1 B201BD  to SR2 B201BD   (4 additional mixed inputs)
   SR1 B201B   to SR2 B201B
   SR1 A201FU  to SR2 A201FU
   SR1 B201FU  to SR2 B201FU

The matching of inputs and the functionality of
the transferred program should be checked. The user can 
then save the program in Zelio Soft 2. From the 
"Module" menu it is also possible to replace the SR2 smart 
relay by a SR3 smart relay with the same or a greater number 
of inputs - outputs.

Note:
With Windows 95 and 98 operating systems, "non-intelligent" device drivers 
may overload the serial port and cause interruptions in 
communication between the PC and the module.

It is not allowed to set the module time between 2 a.m. and 3 a.m. the day 
of the change to wintertime.

Anomaly identified and still to be corrected:
The Zx keys used in the program cannot be accessed
from the front panel of the relay in MONITORING mode.  

 
