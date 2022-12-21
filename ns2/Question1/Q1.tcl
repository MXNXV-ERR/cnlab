#Create a new Simulator
set ns [new Simulator]
#Creating nam file to record nam trace
set nf [open prog1.nam w]
$ns namtrace-all $nf
#Creating tr file to record trace
set nd [open prog1.tr w]
$ns trace-all $nd

#Standard finish{} procedure
proc finish { } {
global ns nf nd
$ns flush-trace
#Closing files before exit
close $nf
close $nd
#Executing the Network AniMator(NAM)
exec nam prog1.nam &
exit 0
}

#Creating 3 nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

#Setting up links between nodes
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 512Kb 10ms DropTail
$ns queue-limit $n1 $n2 5

#Setting up agents on each node
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
set sink [new Agent/Null]
$ns attach-agent $n2 $sink
$ns connect $udp0 $sink

#Setting up application CBR(Constant bitrate)
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0


#Schedules to start the  components
$ns at 0.2 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"
$ns run

