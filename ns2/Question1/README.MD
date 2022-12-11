# Steps to execute the Question 1 NS2

 ****Assuming using this in ubuntu or wsl ubuntu****

## 1)Creating the files Q1.tcl and Q1.awk

## 2)Executing the .tcl file 
This lauches the simulator GUI
```sql
ns Q1.tcl
```
Also this generates two new file in the folder where the Q1.tcl is present<br>
* prog1.nam<br>
* prog1.tr <br>

Due to code in Q1.tcl<br>

<P ALIGN="CENTER"><IMG SRC="https://github.com/MXNXV-ERR/cnlab/blob/main/ns2/documentation/Q11.png?raw=True"></P>


## 3)Executing the awk file 
Awk file typically used as a data extraction and reporting tool.
```sql
awk -f Q1.awk prog1.tr
```
Expected output:
<P ALIGN="CENTER"><IMG SRC="https://github.com/MXNXV-ERR/cnlab/blob/main/ns2/documentation/Q12.png?raw=True"></P>
