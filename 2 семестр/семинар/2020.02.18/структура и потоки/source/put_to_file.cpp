#include "functions.h"
void put_on_file (struct Bio man, const char* path){
    FILE *fp=fopen (path,"wb");
if (fp==NULL) {
 puts ("не удалось открыть файл");
 getchar(); exit (1);
}
fwrite (man.name, sizeof(man.name),1,fp);
fprintf(fp,"\n");
fwrite (man.date, sizeof(man.date),1,fp);
fprintf(fp,"\n");
fwrite (man.sex, sizeof(man.sex),1,fp);
fprintf(fp,"\n");
fwrite (man.place, sizeof(man.place),1,fp);
fprintf(fp,"\n");
fwrite (man.famstatus, sizeof(man.famstatus),1,fp);
fprintf(fp,"\n");
fwrite (man.education, sizeof(man.education),1,fp);
fprintf(fp,"\n");
fwrite (man.phone, sizeof(man.phone),1,fp);
fprintf(fp,"\n");
fwrite (man.email, sizeof(man.email),1,fp);
fprintf(fp,"\n");
fwrite (man.hobby, sizeof(man.hobby),1,fp);
fprintf(fp,"\n");
fwrite (man.job, sizeof(man.job),1,fp);
 fclose(fp);
}
