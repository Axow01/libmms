#include "libmms.h"
#include <stdlib.h>

int	main(void)
{
		char	*str;

		mms_set_alloc_fn(calloc);
		str = mms_alloc(10, sizeof(char));
		mms_kill("Fuck yu", true, EXIT_SUCCESS);
}
