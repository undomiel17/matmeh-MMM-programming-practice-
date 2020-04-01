#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct Bio {
char name[40];
char date[12];
char sex[5];
char place[20];
char famstatus [10];
char education [15];
char phone [12];
char email [40];
char hobby[30];
char job[20];
};
void put_on_file (struct Bio man, const char* path){
    FILE *fp=fopen (path,"wb");
if (fp==NULL) {
 puts ("íå óäàëîñü îòêðûòü ôàéë");
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
get_from_file (struct Bio man, const char* path){
    FILE *fp=fopen (path,"rb");
if (fp==NULL) {
 puts ("íå óäàëîñü îòêðûòü ôàéë");
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
int main()
{
setlocale(LC_ALL, "Rus");
struct Bio man1= { "Àíäðååâ Âàäèì Ñåðãååâè÷", "20.01.1989", "ìóæ", "Ìîñêâà", "æåíàò", "ÑÏáÃó, õèì-ôàê", "89693475490", "andreeeeev58@gmail.com", "ñïîðò, òåàòð", "ñàíòåõíèê"  };
const char* path;
path="notebook.txt";
put_on_file (man1, path);
get_from_file (man1, path);
    return 0;
}
