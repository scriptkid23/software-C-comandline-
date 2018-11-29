#include <stdio.h>
#include <string.h>

#include "display.c"

struct student {
    char  MSSV[5];
    char  Username[15],tempUser[8];
    float pointHD,pointPB,pointHD1,pointHD2,pointHD3;
    float giuaKy,cuoiKy;
};
void inputStudent(struct student sv[],int n){

    FILE *ms  ; ms   = fopen("MSSV.DAT","w+");
    FILE *user; user = fopen("username.DAT","w+");
    FILE *pHD ; pHD  = fopen("pointHD.DAT","w+");
    FILE *pPB ; pPB  = fopen("pointPB.DAT","w+");
    FILE *pHD1; pHD1 = fopen("pointHD1.DAT","w+");
    FILE *pHD2; pHD2 = fopen("pointHD2.DAT","w+");
    FILE *pHD3; pHD3 = fopen("pointHD3.DAT","w+");
    for(int i = 0; i < n; i++){
    printf("Student[%d] \n",i+1);
    fflush(stdin);
    printf("MSSV: "); gets(sv[i].MSSV); fprintf(ms,"%s\n",sv[i].MSSV);
    fflush(stdin);
    printf("Username: "); gets(sv[i].Username); fprintf(user,"%s\n",sv[i].Username);
    fflush(stdin);
    printf("Point huong dan : "); scanf("%f",&sv[i].pointHD);fprintf(pHD,"%.1f\n",sv[i].pointHD);
    fflush(stdin);
    printf("Point phan bien : "); scanf("%f",&sv[i].pointPB);fprintf(pPB,"%.1f\n",sv[i].pointPB);
    fflush(stdin);
    printf("Point hoi dong 1: "); scanf("%f",&sv[i].pointHD1);fprintf(pHD1,"%.1f\n",sv[i].pointHD1);
    fflush(stdin);
    printf("Point hoi dong 2: "); scanf("%f",&sv[i].pointHD2);fprintf(pHD2,"%.1f\n",sv[i].pointHD2);
    fflush(stdin);
    printf("Point hoi dong 3: "); scanf("%f",&sv[i].pointHD3);fprintf(pHD3,"%.1f\n",sv[i].pointHD3);
    fflush(stdin);
  }
    fclose(ms);fclose(user);fclose(pHD);fclose(pPB);fclose(pHD1);fclose(pHD2);fclose(pHD3);
}
void updateStudent(struct student sv[],int n){
    FILE *ms  ; ms   = fopen("MSSV.DAT","a+");
    FILE *user; user = fopen("username.DAT","a+");
    FILE *pHD ; pHD  = fopen("pointHD.DAT","a+");
    FILE *pPB ; pPB  = fopen("pointPB.DAT","a+");
    FILE *pHD1; pHD1 = fopen("pointHD1.DAT","a+");
    FILE *pHD2; pHD2 = fopen("pointHD2.DAT","a+");
    FILE *pHD3; pHD3 = fopen("pointHD3.DAT","a+");

    for(int i = 0; i < n; i++){
    printf("Student_NEW[%d] \n",i+1);
    fflush(stdin);
    printf("MSSV: "); gets(sv[i].MSSV);
    if(checkMSSV(sv[i].MSSV) == 1){
      printf("+--------------------------+\n");
      printf("|Ma so sinh vien da ton tai|\n");
      printf("|      Moi nhap lai ^^     |\n");
      printf("+--------------------------+\n");
      updateStudent(sv,n);
    }else{
    fprintf(ms,"%s\n",sv[i].MSSV);
    fflush(stdin);
    printf("Username: "); gets(sv[i].Username); fprintf(user,"%s\n",sv[i].Username);
    fflush(stdin);
    printf("Point huong dan : "); scanf("%f",&sv[i].pointHD);fprintf(pHD,"%.1f\n",sv[i].pointHD);
    fflush(stdin);
    printf("Point phan bien : "); scanf("%f",&sv[i].pointPB);fprintf(pPB,"%.1f\n",sv[i].pointPB);
    fflush(stdin);
    printf("Point hoi dong 1: "); scanf("%f",&sv[i].pointHD1);fprintf(pHD1,"%.1f\n",sv[i].pointHD1);
    fflush(stdin);
    printf("Point hoi dong 2: "); scanf("%f",&sv[i].pointHD2);fprintf(pHD2,"%.1f\n",sv[i].pointHD2);
    fflush(stdin);
    printf("Point hoi dong 3: "); scanf("%f",&sv[i].pointHD3);fprintf(pHD3,"%.1f\n",sv[i].pointHD3);
    fflush(stdin);
      }
    }
    fclose(ms);fclose(user);fclose(pHD);fclose(pPB);fclose(pHD1);fclose(pHD2);fclose(pHD3);
}
void displayStudent(struct student sv[],int n){
    FILE *ms  ; ms   = fopen("MSSV.DAT","r");
    FILE *user; user = fopen("username.DAT","r");
    FILE *pHD ; pHD  = fopen("pointHD.DAT","r");
    FILE *pPB ; pPB  = fopen("pointPB.DAT","r");
    FILE *pHD1; pHD1 = fopen("pointHD1.DAT","r");
    FILE *pHD2; pHD2 = fopen("pointHD2.DAT","r");
    FILE *pHD3; pHD3 = fopen("pointHD3.DAT","r");
    FILE *giuaKy; giuaKy = fopen("giuaKy.DAT","r");
    FILE *cuoiKy; cuoiKy = fopen("cuoiKy.DAT","r");
    for(int i =0; i < n; i++){

      fscanf(ms,"%s",&sv[i].MSSV);
      fflush(stdin);
      fgets(sv[i].Username,15,user);

    //  fscanf(user,"%s",sv[i].Username);
      fscanf(pHD,"%f",&sv[i].pointHD);
      fscanf(pPB,"%f",&sv[i].pointPB);
      fscanf(pHD1,"%f",&sv[i].pointHD1);
      fscanf(pHD2,"%f",&sv[i].pointHD2);
      fscanf(pHD3,"%f",&sv[i].pointHD3);


    }
    printf("+-----MSSV-----+Ho va ten+--------+HD---+PB---+HD1---+HD2---+HD3---+giuaKy---+cuoiKy+\n");
    for(int i = 0; i < n; i++){
      printf("|%-14s|%-18s|%-5.1f|%-5.1f|%-6.1f|%-6.1f|%-6.1f|%-9.1f|%-6.1f \n",sv[i].MSSV,sv[i].Username,sv[i].pointHD,sv[i].pointPB,sv[i].pointHD1,sv[i].pointHD2,sv[i].pointHD3,sv[i].giuaKy,sv[i].cuoiKy);
    }
    fclose(ms);fclose(user);fclose(pHD);fclose(pPB);fclose(pHD1);fclose(pHD2);fclose(pHD3);
}
void processStudent(struct student sv[],int n){
    FILE *ms  ; ms   = fopen("MSSV.DAT","r");
    FILE *user; user = fopen("username.DAT","r");
    FILE *pHD ; pHD  = fopen("pointHD.DAT","r");
    FILE *pPB ; pPB  = fopen("pointPB.DAT","r");
    FILE *pHD1; pHD1 = fopen("pointHD1.DAT","r");
    FILE *pHD2; pHD2 = fopen("pointHD2.DAT","r");
    FILE *pHD3; pHD3 = fopen("pointHD3.DAT","r");
    FILE *giuaKy; giuaKy = fopen("giuaKy.DAT","w");
    FILE *cuoiKy; cuoiKy = fopen("cuoiKy.DAT","w");
    for(int i =0; i < n; i++){

      fscanf(ms,"%s",&sv[i].MSSV);
      fscanf(user,"%s",&sv[i].Username);
      fscanf(pHD,"%f",&sv[i].pointHD);
      fscanf(pPB,"%f",&sv[i].pointPB);
      fscanf(pHD1,"%f",&sv[i].pointHD1);
      fscanf(pHD2,"%f",&sv[i].pointHD2);
      fscanf(pHD3,"%f",&sv[i].pointHD3);

    }
    for(int i=0; i< n ; i++){
        sv[i].giuaKy = (sv[i].pointHD+ sv[i].pointPB)/2;
        fprintf(giuaKy,"%.1f",sv[i].giuaKy);
        sv[i].cuoiKy = (sv[i].pointHD1 + sv[i].pointHD2 + sv[i].pointHD3)/3;
        fprintf(cuoiKy,"%.1f",sv[i].cuoiKy);
    }
    fclose(ms);fclose(user);fclose(pHD);fclose(pPB);fclose(pHD1);fclose(pHD2);fclose(pHD3);
}
int main(int argc, char const *argv[]) {

    FILE *numberStudentW;
    FILE *numberStudentR;
    FILE *numberStudentUpdate;


    numberStudentW = fopen("numberStudent.DAT","w+");
    numberStudentR = fopen("numberStudent.DAT","r");
    numberStudentUpdate = fopen("numberStudent.DAT","w+");
    struct student a[100];
    int n,plus,temp,numbersv,tempNumberSV;
    plus = 0;
    printf("NHAP SO LUONG SINH VIEN: ");
    scanf("%d",&numbersv);
    fprintf(numberStudentW,"%d",numbersv);
    fclose(numberStudentW);
    inputStudent(a,numbersv);
    do{
      display();
      scanf("%d",&n);
      switch (n) {
        case 1:
          printf("nhap so luong sinh vien can them\n");
          scanf("%d",&plus);
          updateStudent(a,plus);
          tempNumberSV = numbersv + plus;
          fprintf(numberStudentUpdate,"%d",tempNumberSV);
          fclose(numberStudentUpdate);

          fscanf(numberStudentR,"%d",&numbersv);
          fclose(numberStudentR);
          processStudent(a,numbersv);
          printf("0.quay lai menu\n");
          scanf("%d",&temp);
          break;
        case 2:
          printf("DANH SACH SINH VIEN\n");
          processStudent(a,numbersv);
          displayStudent(a,numbersv);
          printf("0.quay lai menu\n");
          scanf("%d",&temp);
          break;
        default:
          temp = n;
          break;
      }
    }while(temp == 0);


  return 0;
}
