# CCSEP-Overflow-Demo
Demo of Integer and Buffer overflow within a simple database program

"op" is the unpatched program
- run via "./op"

"oup" is the unpatched program
- run via "./oup"

Known Issue:
- The unpatched program will ask for a username and then display the menu and run the add_user method again, which will change the database adding a blank user every time gets is called once because it is within the menu while loop. I have attempted to remedy this problem but I've not found a solution and put it down to something to do with the gets() method itself as it does not occur on the patched version. The exploits still behave as they should and the program demonstrates each appropriately enough for the purposes of this assessment.
