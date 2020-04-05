#ifndef __EXTFUSE_ATTR_H__
#define __EXTFUSE_ATTR_H__

#include <linux/fuse.h>
#include <linux/types.h>


typedef struct lookup_attr_key {
	/* node id */
	__u64 nodeid;
} lookup_attr_key_t;

typedef struct lookup_attr_value {
	__u32 stale;
	/* node attr */
	struct fuse_attr_out out;
} lookup_attr_val_t;

/* number of entries in hash lookup table */
#undef MAX_ENTRIES
#define MAX_ENTRIES (2 << 16)

#endif /* __EBPF_ATTR_H__ */
