LIB = libextfuse.a

OBJS := ebpf.o utils.o bpf_load.o

CLANG ?= clang

LINUX_HEADERS = /lib/modules/`uname -r`/source

LINUXINCLUDE =	-I $(LINUX_HEADERS)/tools/lib \
		-I $(LINUX_HEADERS)/tools/perf \
		-I $(LINUX_HEADERS)/tools/include \
		-I $(LINUX_HEADERS)/samples/bpf

$(LIB): $(OBJS)
	ar -xv libbpf.a
	ar -csrov $(LIB) $+ libbpf-in.o

CFLAGS = "-D_FILE_OFFSET_BITS=64 -fPIE -O2 -Wall -Wno-unused-variable"
#CFLAGS = "-D_FILE_OFFSET_BITS=64 -fPIE -O0 -g -Wall -Wno-unused-variable"

$(OBJS): %.o:%.c
	$(CLANG) -c -o $@ $(CFLAGS) -I../include $(LINUXINCLUDE) $<

all: $(LIB)

clean:
	rm -f $(LIB)
	rm -f $(OBJS) libbpf-in.o
