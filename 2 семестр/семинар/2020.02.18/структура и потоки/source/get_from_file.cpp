#include "functions.h"
get_from_file (struct Bio man, const char* path){
    FILE *fp=fopen (path,"rb");
if (fp==NULL) {
 puts ("не удалось открыть файл");
 getchar(); exit (1);
}
fread (man.name, 1,sizeof(man.name),fp);
fscanf(fp,"\n");
puts (man.name);
fread (man.date, 1,sizeof(man.date),fp);
fscanf(fp,"\n");
puts (man.date);
fread (man.sex, 1,sizeof(man.sex),fp);
fscanf(fp,"\n");
puts (man.sex);
fread (man.place, 1,sizeof(man.place),fp);
fscanf(fp,"\n");
puts (man.place);
fread (man.famstatus, 1,sizeof(man.famstatus),fp);
fscanf(fp,"\n");
puts (man.famstatus);
fread (man.education, 1,sizeof(man.education),fp);
fscanf(fp,"\n");
puts (man.education);
fread (man.phone, 1,sizeof(man.phone),fp);
fscanf(fp,"\n");
puts (man.phone);
fread (man.email, 1,sizeof(man.email),fp);
fscanf(fp,"\n");
puts (man.email);
fread (man.hobby, 1,sizeof(man.hobby),fp);
fscanf(fp,"\n");
puts (man.hobby);
fread (man.job, 1,sizeof(man.job),fp);
fscanf(fp,"\n");
puts (man.job);
fclose (fp);
}
