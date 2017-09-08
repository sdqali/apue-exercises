BOOK_SOURCE := $(shell pwd)/../apue.3e

ls:
	mkdir -p out
	gcc -o out/ls ls.c -I $(BOOK_SOURCE)/include/ -L $(BOOK_SOURCE)/lib/ -lapue
