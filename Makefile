#list of objects in the file
OBJS = history.o tokenizer.o
OBJS_MAIN = $(OBJS) umain.o
OBJS_MAIN = $(OBJS) tester.o

#Compiler flags -g debug -03 optimization
CFLAGS =-g -03

tokenizer.h: tokenizer.o uimain.o
history.h: history.o uimain.o

tokenizer: $(OBJS_MAIN)
	cc -o tokenizer $(CFLAGS) $(OBJS_MAIN)

tokenizer_test: $(OBJS_TEST)
	cc -o tokenizer$(CFLAGS) $(OBJS_TEST)

all: tokenizer

clean:
	rm -f *.o *.c~ *.h~ *~ *.c# *.h#

run:tokenizer
	./tokenizer

test: tokenizer_test
	./tokenize_test
