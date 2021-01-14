#ifndef __MAIN_H__
#define __MAIN_H__

#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <windows.h>
#include <Lmcons.h>
#include <dirent.h>
#include <time.h>
#include <ShellApi.h>
/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT SomeFunction(const LPCSTR sometext);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
