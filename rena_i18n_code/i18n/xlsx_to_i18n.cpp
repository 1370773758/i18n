#include "xlsx_to_i18n.h"
#include <QDebug>

#include <iostream>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#include <QFile>

using namespace QXlsx;

#define XLSX_PWD        "../rena_i18n.xlsx"
#define C_FILE_PWD      "../rena_i18n.c"
#define H_FILE_PWD      "../rena_i18n.h"

void rena_i18n_hfile_create(void);
void rena_i18n_cfile_create(void);

void rena_i18n_xlsx_change(void)
{

}

void rena_i18n_hfile_create(void)
{
    int i;
    QVariant str1;
    QXlsx::Document xlsx(XLSX_PWD);

    int rowLen = xlsx.dimension().rowCount();
    int columnLen = xlsx.dimension().columnCount();

    QFile file(H_FILE_PWD);
    file.open(QFile::WriteOnly|QFile::Truncate);
    QTextStream in(&file);
    in.setCodec("UTF-8");
    in <<"#ifndef _RENA_I18N_H"<< endl;
    in <<"#define _RENA_I18N_H\n"<< endl;
    in<<"#include <stdint.h>"<<endl;
    in<<"#include <string.h>\n"<<endl;
    in<<"#include \"lvgl/lvgl.h\""<<endl;

    in<<"typedef enum\n"<<"{"<<endl;
    for(i = 2; i <= columnLen; i++)
    {
        QVariant str2;
        str1 = xlsx.read(2,i);
        str2 = xlsx.read(1,i);
        in<<str1.toByteArray()<<"," << "    //" << str2.toByteArray()<<endl;
    }
    in<<"language_max"<<endl;
    in<<"}rena_i18n_language_e;\n"<<endl;
    for (i = 3; i < rowLen; i++)
    {
        str1 = xlsx.read(i,1);
        in <<"#define "<<str1.toByteArray()<<"  "<<"("<<i-3<<")"<<endl;
    }
    in<<"#define STR_MAX"<<"  "<<"("<<rowLen-3<<")"<<endl;
    in<<endl;
    in<<"void rena_i18n_set_local(rena_i18n_language_e l_name);"<<endl;
    in<<"const char *rena_i18n_get_text(uint32_t msg_id);"<<endl;
    in<<"rena_i18n_language_e rena_i18n_get_local(void);"<<endl;
    in<<"#define _(msg_id)   rena_i18n_get_text(msg_id)"<<endl;
    in <<"\n#endif\n"<< endl;
    file.close();
}

void rena_i18n_cfile_create(void)
{
    int i,j;
    QVariant str1;
    QXlsx::Document xlsx(XLSX_PWD);

    int rowLen = xlsx.dimension().rowCount();
    int columnLen = xlsx.dimension().columnCount();

    QFile file(C_FILE_PWD);
    file.open(QFile::WriteOnly|QFile::Truncate);

    QTextStream in(&file);
    in.setCodec("UTF-8");
    in<< "#include \"rena_i18n.h\"\n"<<endl;
    for(i = 2; i <= columnLen; i++)
    {
        str1 = xlsx.read(2,i);
        in<<"static char *"<<str1.toByteArray()<<"_buf[] = {"<<endl;
        for(j = 3; j <= rowLen; j++)
        {
            str1 = xlsx.read(j,i);
            in<<"\""<<str1.toByteArray()<<"\","<<endl;
        }
        in<<"NULL\n"<<"};\n"<<endl;
    }
        str1 = xlsx.read(2,2);
    in<<"static rena_i18n_language_e local_language = "<<str1.toByteArray()<<";"<<endl;
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
    for(i = 2; i <= columnLen; i++)
    {
        str1 = xlsx.read(2,i);
        in<<"       case "<<str1.toByteArray()<<":"<<endl;
        in<<"           return "<<str1.toByteArray()<<"_buf[msg_id];"<<endl;
    }
    str1 = xlsx.read(2,2);
    in<<"       default"<<": "<<"return "<<str1.toByteArray()<<"_buf[msg_id];"<<endl;
    in<<"       }"<<endl;
    in<<"}\n"<<endl;
    file.close();
}
