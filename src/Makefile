LIB = extfuse.a

OBJS := ebpf.o utils.o

CLANG ?= clang

LINUX_HEADERS = /lib/modules/`uname -r`/source

LINUXINCLUDE =	-I $(LINUX_HEADERS)/tools/lib \
		-I $(LINUX_HEADERS)/tools/perf \
		-I $(LINUX_HEADERS)/tools/include \
		-I $(LINUX_HEADERS)/include/uapi \
		-I $(LINUX_HEADERS)/samples/bpf

all: $(OBJS)
	ar -xv libbpf.a
	ar -rv $(LIB) $(OBJS)

clean:
	rm -f $(LIB)
	rm -f $(OBJS) libbpf-in.o

$(OBJS): %.o:%.c
	$(CLANG) -O2 -Wall -Wno-unused-variable -c -o $@ \
		-I../include $(LINUXINCLUDE) \
		$<

