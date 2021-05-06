/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** encapsulation_dll
*/

#include "encapsulation_dll.hpp"

Encap_dl::Encap_dl(const char *file)
{
    this->encap_handle = dlopen(file, RTLD_LAZY);
    if (this->encap_handle == NULL)
        throw(dlerror());
}

Encap_dl::~Encap_dl()
{
    dlclose(this->encap_handle);
}

void *Encap_dl::getDlsym(const char *symbol)
{
    return (dlsym(this->encap_handle, symbol));
}