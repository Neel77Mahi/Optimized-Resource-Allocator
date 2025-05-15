# Optimized-Resource-Allocator

This project implements an efficient **First-Fit Decreasing (FFD)** algorithm combined with **max-heap server prioritization** to allocate resource requests to cloud servers. Written in C, this simulation demonstrates how dynamic job allocation can be optimized for real-world systems like cloud infrastructure, operating systems, or server farms.

---

##  Features

-  Greedy algorithm using First-Fit Decreasing
-  Priority Queue behavior via max-heap simulation (using `qsort`)
-  Struct-based resource tracking (each server maintains max & current capacity)
-  Tracks execution time of the allocation process
-  Clean terminal output with allocation success/failure per request

---

## Project Structure

 Resource-Allocator
├── main.c # Main program logic
├── README.md # Project description and usage instructions

---

## Algorithm Overview

### First-Fit Decreasing (FFD):
1. Sort requests in **descending order** of demand.
2. Sort servers by **available capacity** (max-heap behavior).
3. Allocate each request to the **first server** that can accommodate it.
4. Re-sort the servers after each allocation to maintain priority.

---

## Compilation & Execution

### Requirements
- GCC (or any C compiler)
- Linux/Mac/Windows terminal

### Compile
```bash
gcc main.c -o allocator
```

#### Run
```bash
./allocator
```

Sample Input/Output
Enter the number of requests: 3
Request 1 demand: 20
Request 2 demand: 10
Request 3 demand: 30

Enter the number of servers: 2
Enter max capacity for Server 1: 40
Enter max capacity for Server 2: 30

Request 1 (demand 30) allocated to Server 2
Request 2 (demand 20) allocated to Server 1
Request 3 (demand 10) allocated to Server 1
Execution time: 0.000015 seconds

Educational Value
This project is ideal for students studying:
Data Structures (sorting, greedy algorithms)
Operating Systems (resource scheduling)
Cloud Computing (load balancing)
Systems Programming in C

Neeladri Bandopadhyay
