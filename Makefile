
all : exercise1 exercise2 exercise3 exercise4 exercise5 exercise6
	echo "OK"
	
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

clean:	.PHONY
	make -C exercise1 clean
	make -C exercise2 clean
	make -C exercise3 clean
	make -C exercise4 clean
	make -C exercise5 clean
	make -C exercise6 clean
	
.PHONY:
	@true
	

