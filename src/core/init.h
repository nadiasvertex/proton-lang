#ifndef __PROTON_INIT_H__
#define __PROTON_INIT_H__

#include <gc.h>

namespace proton
{
	class bootstrapper
	{
		bool initialized;

	private:
		void do_init()
		{
			GC_INIT();
		}

	public:
		bootstrapper():initialized(false) {}

		void init()
		{
			if (!initialized)
			{
				initialized=true;
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
