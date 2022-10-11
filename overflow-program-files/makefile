make: largerProgram-unpatched.c largerProgram-patched.c
		gcc -g -z execstack -fno-stack-protector -no-pie -o oup largerProgram-unpatched.c
		gcc -g -z execstack -fno-stack-protector -no-pie -o op largerProgram-patched.c
