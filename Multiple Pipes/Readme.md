### How it works:

- We create 4 pipes. Why? Because we have 4 roads. From A to B, from B to C, from C to B, and from B to A.
- Important!! we need to close all unused elements.
- Get time using time.h --> time_t variable. 
- Time()-> gets time and ctime() -> returns string
- the pattern is similar,
  1. ​	Get time 
  2. ​    Write it to the write end of the pipe
  3. ​    Read from the other side of the pipe
  4. ​    Print  

- Kill process C
- Kill process B and A