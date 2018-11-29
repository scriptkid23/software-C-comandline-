#include <stdio.h>
#include <string.h>

struct MSSV {
  char mssv[100];
};
void display(){
  printf("+-------------------------------------+\n");
  printf("+--CHUONG TRINH TINH DIEM TOT NGHIEP--+\n");
  printf("+-------------------------------------+\n");
  printf("->Menu--------------------------------+\n");
  printf("\n");
  printf("1.Bo sung sinh vien\n");
  printf("2.Danh sach sinh vien bao ve thanh cong\n");
  printf("3.Sap xep theo ten sinh vien\n");
  printf("4.Thoat chuong trinh\n");
}
void checkSum(int sum){
  if(sum >= 20){
    printf("Tong so sinh vien trong hoi dong khong qua 20\n");
    printf("Moi nhap lai !\n");
  }
}
int checkMSSV(char ms[]){
  struct MSSV mst[100];
  FILE *foR ;
  FILE *numberStudent;
  int count;
  int x;
  foR  = fopen("MSSV.DAT","r");
  numberStudent = fopen("numberStudent.DAT","r");
  fscanf(numberStudent,"%d",&count);
/*  char temp[100];
  fscanf(foR,"%s",&temp);
  int x = strcmp(ms,temp);
  if(x == 0){
    return 1;
  }else{
    return 0;
  }*/
  for(int i = 0; i<count ;i++){
    fscanf(foR,"%s",&mst[i].mssv);
  }
  for(int i =0 ;i<count; i++){
    x = strcmp(mst[i].mssv,ms);
    if(x == 0){
      return 1;
    }
  }
  fclose(foR);
  fclose(numberStudent);
}
