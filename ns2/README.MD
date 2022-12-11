# NS2 Instruction

## TCL file

"Tcl casts everything into the mold of a command, even programming constructs like variable assignment and procedure definition."<br>-Wikipedia

## Structure of TCL file

### 1)Declaring Simulator and setting output file
```bash
set ns [new Simulator]
set nf [open prog1.nam w]
$ns namtrace-all $nf
set nd [open prog1.tr w]
$ns trace-all $nd
```
### 2) Declaring finish{}
```bash
proc finish { } {
global ns nf nd
$ns flush-trace
close $nf
close $nd
exec nam prog1.nam &
exit 0
}
```

### 3) Setting Node and Link
#### Node
Syntax:
```
```

```bash
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
```
#### Link
```bash
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 512Kb 10ms DropTail
$ns queue-limit $n1 $n2 5
```
### 4) Setting Agent
```bash
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
```
```bash
set sink [new Agent/Null]
$ns attach-agent $n2 $sink
$ns connect $udp0 $sink
```

### 5) Settting Application
```bash
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0
```

### 6) Setting simulation times and shedules
```bash
$ns at 0.2 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"
$ns run
```


## AWK file

"Used for purposes of extracting or transforming text, such as producing formatted reports."<br>-Wikipedia