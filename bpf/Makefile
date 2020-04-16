OBJS = extfuse.o

LLC ?= llc
CLANG ?= clang

all: $(OBJS)

clean:
	rm -f $(OBJS)

LINUX_HEADERS ?= /lib/modules/`uname -r`/source

LINUXINCLUDE =	-I $(LINUX_HEADERS)/arch/x86/include \
 		-I $(LINUX_HEADERS)/arch/x86/include/uapi \
 		-I $(LINUX_HEADERS)/arch/x86/include/generated \
 		-I $(LINUX_HEADERS)/arch/x86/include/generated/uapi \
 		-I $(LINUX_HEADERS)/include \
 		-I $(LINUX_HEADERS)/include/uapi \
 		-I $(LINUX_HEADERS)/include/generated \
 		-I $(LINUX_HEADERS)/include/generated/uapi \
 		-I $(LINUX_HEADERS)/tools/testing/selftests/bpf \
 		-I $(LINUX_HEADERS)/fs/fuse

INC_FLAGS = -nostdinc -isystem `$(CLANG) -print-file-name=include`

MUTE_FLAGS = -Wno-unused-value -Wno-pointer-sign \
	     -Wno-compare-distinct-pointer-types \
	     -Wno-gnu-variable-sized-type-not-at-end \
	     -Wno-address-of-packed-member -Wno-tautological-compare \
	     -Wno-unknown-warning-option

$(OBJS): %.o:%.c
	$(CLANG) $(INC_FLAGS) $(EXTRA_CFLAGS) $(MUTE_FLAGS) \
		-D__KERNEL__ -D__ASM_SYSREG_H \
		-O2 -emit-llvm \
 		$(LINUXINCLUDE) -I../include \
		-include $(LINUX_HEADERS)/include/linux/kconfig.h \
 		-c $< -o - | $(LLC) -march=bpf -filetype=obj -o $@
