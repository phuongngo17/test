#include<stdio.h>
#include<string.h>
struct Student{
		int id;
		char name[50];
		char birthday [50];
		char address[50];
		int status;
	};
	void print_book(struct Student student) {
    printf("%-10s%-30s%-20s%-10.2f%-20s\n", student.id,student.name,student.birthday, student.address,student.status);
    
}
int main(){
	 struct Student studentList[100];
    int count = 0;
    int choice = 0;
    do{
    	printf("***************MENU*****************\n");
	    printf("1.In ra toan bo danh sach\n ");
	    printf("2.Them moi sinh vien vao vi tri cuoi cung, thong tin sinh vien do nguoi dung nhap vao\n");
	    printf("3.Cap nhap thong tin cua mot sinh vien\n");
	    printf("4.Thuc hien chuc nang xoa mot sinh vien\n");
	    printf("5.Thuc hien chuc nang sap xep va in ra danh sach da duoc sap xep\n");
	    printf("6.Thuc hien chuc nang tim kiemm va in ra thong tin cua sinh vien\n");
	    printf("7.Thuc hien chuc nang tim kiem va in ra toan bo thong tin sinh vien theo status\n");
	    printf("8.Thoat chuong trinh\n");
	    printf(" lua chon cua ban: \n");
	    int choice;
	    scanf("%d",&choice);
	    switch(choice){
		    case 1:
			   printf("nhap thong tin sinh vien: ");
                scanf("%d", &count);
                for (int i = 0; i < count; i++) {
                    printf("Nhap thong tin  %d:\n", i + 1);
                    printf("ID: ");
                    scanf("%s", studentList[i].id);
                    printf("Name: ");
                    scanf("%s",studentList[i].name);
                    printf("Birthday: ");
                    scanf("%s", studentList[i].birthday);
                    printf("Address: ");
                    scanf("%s", &studentList[i].address);
                    printf("Status: ");
                    scanf("%d", studentList[i].status);
                }
			    break;
	      	case 2:
			  int pos = 0;
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > count + 1) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                for (int i = count; i >= pos; i--) {
                    studentList[i] = studentList[i - 1];
                }
                printf("Nhap thong tin can them:\n");
                printf("Id: ");
                scanf("%s", studentList[pos - 1].id);
                printf("Name: ");
                scanf("%s", studentList[pos - 1].name);
                printf("Birthday: ");
                scanf("%s", studentList[pos - 1].birthday);
                printf("Address: ");
                scanf("%s", &studentList[pos - 1].address);
                printf("Status: ");
                scanf("%d", studentList[pos - 1].status);
                count ++;
			    break;
		    case 3: 
	         int id;
                printf("Nhap id sinh vien can cap nhat: ");
                scanf("%d",id);
                int pos = -1;
                for(int i=0;i<count;i++){
                	if(strcmp(studentList[i].id,id)==0){
                		pos =i;
                		break;
					}
				}
				if(pos==-1){
					printf("Khong tim thay sinh vien nay %s\n");
				}
		        break;
		    case 4:
			    int id;
                printf("Nhap id sinh can xoa: ");
                scanf("%s", id);
                int pos = -1;
                for (int i = 0; i < count; ++i) {
                    if (strcmp(studentList[i].id, id) == 0) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    printf("Khong tim thay sinh vien nay %s!\n", id);
                    break;
                }
                for (int i = pos; i < count - 1; ++i) {
                    studentList[i] = studentList[i + 1];
                }
                count--;
                printf("da xoa sach sinh vien nay %s!\n", id);
			     break;
		    case 5:
                for (int i = 0; i < count - 1; i++) {
                    for (int j = 0; j < count - 1 - i; j++) {
                        if (studentList[j].id > studentList[j + 1].id) {
                            struct Student temp = studentList[j];
                            studentList[j] =  studentList[j + 1];
                            studentList[j + 1] = temp;
                        }
                    }
               }
               printf("sinh vien da duoc sap xep\n");
			    break;
		    case 6:
		         int left = 0;
                 int right = count - 1;

               while (left <= right) {
                    int mid = (left + right) / 2;

                    if (strcmp(studentList[mid].name, searchName) == 0) {
                        return mid;
                    } else if (strcmp(studentList[mid].name, searchName) < 0) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                return -1;
		    	break;
	    	case 7:
		    	break;
		    case 8:
		    	printf("Thoat chuong trinh\n");
			    break;
		    default
	}
	
	}while(choice!=8);
}
