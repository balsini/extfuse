#ifndef __EBPF_LOOKUP_H__
#define __EBPF_LOOKUP_H__

#include <linux/limits.h>
#include <linux/types.h>


typedef struct lookup_entry_key {
	__u64 nodeid;		/* parent node id */
	char name[NAME_MAX];	/* node name */
} lookup_entry_key_t;

typedef struct lookup_entry_value {
	__u32 stale;
	__u64 nlookup;		/* ref cnt */
	__u64 nodeid;		/* child node id */
	__u64 generation;
	__u64 entry_valid;
	__u32 entry_valid_nsec;
} lookup_entry_val_t;

/* number of entries in hash lookup table */
#define MAX_ENTRIES (2 << 16)

#endif /* __EBPF_LOOKUP_H__ */
