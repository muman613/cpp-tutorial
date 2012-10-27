###############################################################################
# Makefile for C++ tutorial project
###############################################################################
#

all : exercise1 exercise2 exercise3 exercise4  \
      exercise5 exercise6 exercise7 exercise8  \
      exercise9
	@echo "OK"
	
exercise1:	.PHONY
	make -C exercise1
	
exercise2:	.PHONY
	make -C exercise2

exercise3:	.PHONY
	make -C exercise3
	
exercise4:	.PHONY
	make -C exercise4
	
exercise5:	.PHONY
	make -C exercise5

exercise6:	.PHONY
	make -C exercise6

exercise7:	.PHONY
	make -C exercise7

exercise8:	.PHONY
	make -C exercise8

exercise9:	.PHONY
	make -C exercise9

clean:	.PHONY
	make -C exercise1 clean
	make -C exercise2 clean
	make -C exercise3 clean
	make -C exercise4 clean
	make -C exercise5 clean
	make -C exercise6 clean
	make -C exercise7 clean
	make -C exercise8 clean
	make -C exercise9 clean
	
.PHONY:
	@true
	

