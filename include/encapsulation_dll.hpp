/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** encapsulation_dll
*/

#include <iostream>
#include <dlfcn.h>
#include <dirent.h>

#ifndef ENCAPSULATION_DLL_HPP_
#define ENCAPSULATION_DLL_HPP_

class Encap_dl
{
    public:
    Encap_dl(const char *file);
    ~Encap_dl();
    // static void *encap_dlopen(const char*file, int flag);
    // static int encap_dlclose(void *handle);
    void * getDlsym(const char *symbol);
    private:
    void * encap_handle;
};

#endif /* !ENCAPSULATION_DLL_HPP_ */
