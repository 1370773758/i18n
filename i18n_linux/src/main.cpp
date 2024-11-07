#include <iostream>

#include <OpenXLSX/OpenXLSX.hpp>

#include "rena_i18n_trans.h"


int main(int argc, char *argv[])
{
    printf("1\n");
    rena_i18n_cfile_create();
    printf("2\n");
    rena_i18n_hfile_create();
    printf("3\n");
    return 0;
}