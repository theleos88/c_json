src = $(wildcard src/*.c)
obj = $(src:src/%.c=obj/%.o)
objs = $(src:src/%.c=obj/%.oo)

hdir = $(shell pwd)/hdr
odir = $(shell pwd)/obj
ldir = $(shell pwd)/lib

libname = $(ldir)/libcjson.a
libshared = $(ldir)/libcjson.so

AR = ar
CC = gcc
SHAREDCP = -fPIC
SHAREDLD = -shared
LNAME = -lcjson


MAIN = main.c
export LD_LIBRARY_PATH=$(ldir)

$(libname): $(obj)
	$(AR) rc $@ $^
	ranlib $(libname)

#$(obj): | objd

#objd:
#	@mkdir -p obj

#obj/%.o : %.c
#	@echo $<
#	$(CC) -c -I$(hdir)  $< -o $@

$(obj):
	$(CC) -c $(src) -I$(hdir) -o $@

$(objs):
	$(CC) -c $(SHAREDCP) $(src) -I$(hdir) -o $@

shared: $(objs)
	$(CC) $(SHAREDLD) -o $(libshared) $(objs)

clean:
	rm -f $(ldir)/* $(odir)/* example

example: $(obj) shared
	$(CC) $(MAIN) -L$(ldir) -I$(hdir) $(LNAME) -o $@

run: example
	./$< $(LNAME)
