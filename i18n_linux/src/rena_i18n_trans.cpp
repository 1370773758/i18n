#include "rena_i18n_trans.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fstream>

#include <OpenXLSX/OpenXLSX.hpp>

using namespace OpenXLSX;
using namespace std;

#define XLSX_PWD        "../rena_i18n.xlsx"
#define C_FILE_PWD      "../rena_i18n.c"
#define H_FILE_PWD      "../rena_i18n.h"

void rena_i18n_cfile_create()
{
    XLDocument doc;
    XLCell cell;
    string str1;
    doc.open(XLSX_PWD);
    auto sheet = doc.workbook().worksheet("Sheet1");

    uint16_t column_count = sheet.columnCount();
    uint32_t row_count = sheet.rowCount();
    printf("col = %d row = %d\n", column_count, row_count);

    std::ofstream in;
    in.open(C_FILE_PWD, std::ios::out | std::ios::trunc);
    in<< "#include \"rena_i18n.h\"\n"<<endl;
    for(uint16_t i = 2; i <= column_count; i++)
    {
        cell = sheet.cell(2, i);
        str1 = cell.value().get<string>();
        in<<"static char *"<< str1.c_str() <<"_buf[] = {"<<endl;
        
        for(uint16_t j = 3; j <= row_count; j++)
        {
            cell = sheet.cell(j,i);
            str1 = cell.value().get<string>();
            in<<"\""<< str1.c_str() <<"\","<<endl;
        }

        in<<"NULL\n"<<"};\n"<<endl;
        printf("112\n");
    }
printf("11\n");
    cell = sheet.cell(2, 2);
    str1 = cell.value().get<string>();
    in<<"static rena_i18n_language_e local_language = "<< str1.c_str() <<";"<<endl;
    in<<"void rena_i18n_set_local(rena_i18n_language_e l_name)"<<endl;
    in<<"{"<<endl;
    in<<"    if(l_name < language_max && l_name >= 0){"<<endl;
    in<<"        local_language = l_name;"<<endl;
    in<<"      }"<<endl;
    in<<"}\n"<<endl;

    in<<"rena_i18n_language_e rena_i18n_get_local(void)"<<endl;
    in<<"{"<<endl;
    in<<"   return local_language;"<<endl;
    in<<"}"<<endl;

    in<<"const char *rena_i18n_get_text(uint32_t msg_id)"<<endl;
    in<<"{"<<endl;
    in<<"    if(msg_id >= STR_MAX) return "<<"\"NO DATE\""<<";"<<endl;
    in<<"       switch(local_language){"<<endl;
    for(uint16_t i = 2; i <= column_count; i++)
    {
        cell = sheet.cell(2, i);
        string str1 = cell.value().get<string>();
        in<<"       case "<< str1.c_str() <<":"<<endl;
        in<<"           return "<< str1.c_str() <<"_buf[msg_id];"<<endl;
    }

    cell = sheet.cell(2, 2);
    str1 = cell.value().get<string>();
    in<<"       default"<<": "<<"return "<< str1.c_str() <<"_buf[msg_id];"<<endl;
    in<<"       }"<<endl;
    in<<"}\n"<<endl;

    in.close();
}

void rena_i18n_hfile_create()
{
    XLDocument doc;
    XLCell cell;
    string str1;
    string str2;
    doc.open(XLSX_PWD);
    auto sheet = doc.workbook().worksheet("Sheet1");

    uint16_t column_count = sheet.columnCount();
    uint32_t row_count = sheet.rowCount();

    std::ofstream in;
    in.open(H_FILE_PWD, std::ios::out | std::ios::trunc);
    
    in <<"#ifndef _RENA_I18N_H"<< endl;
    in <<"#define _RENA_I18N_H\n"<< endl;
    in<<"#include <stdint.h>"<<endl;
    in<<"#include <string.h>\n"<<endl;
    in<<"#include \"lvgl/lvgl.h\""<<endl;

    in<<"typedef enum\n"<<"{"<<endl;
    for(uint16_t i = 2; i <= column_count; i++)
    {
        cell = sheet.cell(2, i);
        str1 = cell.value().get<string>();
        cell = sheet.cell(1, i);
        str2 = cell.value().get<string>();

        in<< str1.c_str() <<"," << "    //" << str2.c_str() <<endl;
    }
    in<<"language_max"<<endl;
    in<<"}rena_i18n_language_e;\n"<<endl;
    for (uint16_t i = 3; i < row_count; i++)
    {
        cell = sheet.cell(i, 1);
        str1 = cell.value().get<string>();
        in <<"#define "<< str1.c_str() <<"  "<<"("<<i-3<<")"<<endl;
    }
    in<<"#define STR_MAX"<<"  "<<"("<<row_count-3<<")"<<endl;
    in<<endl;
    in<<"void rena_i18n_set_local(rena_i18n_language_e l_name);"<<endl;
    in<<"const char *rena_i18n_get_text(uint32_t msg_id);"<<endl;
    in<<"rena_i18n_language_e rena_i18n_get_local(void);"<<endl;
    in<<"#define _(msg_id)   rena_i18n_get_text(msg_id)"<<endl;
    in <<"\n#endif\n"<< endl;

    in.close();
}
