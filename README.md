## Introduction
When I got my hands on my very own Raspberry Pi, I wanted to make it go faster as I do with most things. So I made a little program in C to run a quick benchmark of the speeds and record the tempreatures. 

This program is not threaded so it won't really work on multi-core machines, but on a Pi it works perfectly!

[You can view an album of my testing here](http://imgur.com/a/ibjTq).

Here is the clock speeds I was using:

```
    ##  Standard Profiles:
    ##                  arm_freq    core_freq    sdram_freq    over_voltage
    ##     -------------------------------------------------------------------------
    ##     None         700         250          400           0
    ##     Modest       800         300          400           0
    ##     Medium       900         333          450           2
    ##     High         950         450          450           6
    ##     Turbo        1000        500          500           6
    ##
```
