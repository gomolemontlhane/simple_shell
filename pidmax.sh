#!/bin/bash
pidmax=$(cat /proc/sys/kernel/pid_max)
echo "The maximum process ID (PID) value on this system is: $pidmax"
