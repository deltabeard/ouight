/* The following functions are banned as they may be unsafe. */
#pragma once

#pragma GCC poison strcpy strncpy wcscpy	/* Use strcpy_s */
#pragma GCC poison strcat strncat wcscat	/* Use strcat_s */
#pragma GCC poison sprintf swprintf	/* Use snprintf */
#pragma GCC poison vswprintf vsprintf	/* Use snprintf */
#pragma GCC poison gets			/* Use fgets */
#pragma GCC poison strtok wcstok	/* Use strok_r */
#pragma GCC poison scanf wscanf sscanf swscanf /* Use fgets */
#pragma GCC poison alloca		/* Use malloc */
#pragma GCC poison strdupa strndupa	/* Use strndup */
