CC       = cc
CPPFLAGS = -D_XOPEN_SOURCE=700
CFLAGS   = -std=c11 -pedantic -Wall -Werror -pthread -g
LIBS     = -lpthread
RM       = rm -f

OBJS    = monitor.o ethernet.o pn-dcp.o

.PHONY: all clean

all: monitor

clean:
	$(RM) monitor *.o

monitor: $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $(OBJS) -L $(LIBS)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $<

monitor.o:	monitor.c ethernet.h
ethernet.o:	ethernet.c ethernet.h
pn-dcp.o:	pn-dcp.c pn-dcp.h