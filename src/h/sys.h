/*
 * sys.h -- system include files.
 */

/*
 * Universal (Standard 1989 ANSI C) includes.
 */
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * POSIX (1003.1-1996) includes.
 */
#include <dirent.h>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <termios.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>

/*
 * Operating-system-dependent includes.
 */

#if MSDOS
   #include <windows.h>
   #include <sys/cygwin.h>
   #include <sys/select.h>
   
   #ifdef MSWindows
      #define int_PASCAL int PASCAL
      #define LRESULT_CALLBACK LRESULT CALLBACK
      #define BOOL_CALLBACK BOOL CALLBACK
      #include <windows.h>
      #include <mmsystem.h>
      #include <process.h>
      #include "../wincap/dibutil.h"
   #endif				/* MSWindows */

   #undef Type
   #undef lst1
   #undef lst2
#endif					/* MSDOS */

/*
 * Window-system-dependent includes.
 */
#ifdef XWindows
   #ifdef HaveXpmFormat
      #include "../xpm/xpm.h"
   #else				/* HaveXpmFormat */
      #include <X11/Xlib.h>
   #endif				/* HaveXpmFormat */
   #include <X11/Xutil.h>
   #include <X11/Xos.h>
   #include <X11/Xatom.h>
#endif					/* XWindows */

#ifdef Graphics
   #define VanquishReturn(s) return s;
#endif					/* Graphics */

/*
 * Feature-dependent includes.
 */
#ifndef HostStr
   #include <sys/utsname.h>
#endif					/* HostStr */

#ifdef LoadFunc
   #include <dlfcn.h>
#endif					/* LoadFunc */

#if WildCards
   #include "../h/filepat.h"
#endif					/* WildCards */
