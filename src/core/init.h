#ifndef __PROTON_INIT_H__
#define __PROTON_INIT_H__

#include <gc.h>
#include <gmp.h>

namespace proton {

static void* gmp_alloc_hook(size_t sz) {
	return GC_malloc(sz);
}

static void gmp_free_hook(void *p, size_t sz) {
	GC_free(p);
}

static void* gmp_realloc_hook(void *p, size_t old_sz, size_t new_sz) {
	return GC_realloc(p, new_sz);
}

class bootstrapper {
	bool initialized;

private:
	void do_init() {
		GC_INIT();

		mp_set_memory_functions(&gmp_alloc_hook, &gmp_realloc_hook, &gmp_free_hook);
	}

public:
	bootstrapper() :
		initialized(false) {
	}

	void init() {
		if (!initialized) {
			initialized = true;
			do_init();
		}
	}
};

/// The one and only bootstrapper object.  This initializes
/// the runtime system for things that have to happen once
/// and only once.
static bootstrapper *Bootstrapper = new bootstrapper();
}

#endif
