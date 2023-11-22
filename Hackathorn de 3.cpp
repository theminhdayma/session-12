#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int numbers[100];
	int n=0;
	int currentIndex=0;
	int sum;
	int max,min;
	int isPrime;
	int m,k,key;
	int temp;
	do{
		printf("**********MENU***********\n");
		printf("1.Nhap gia tri n phan tu cua mang(n nhap tu ban phim)\n");
		printf("2.In gia tri cac phan tu trong mang\n");
		printf("3.Tinh tong cac phan tu chia het cho 2 va 3 trong mang\n");
		printf("4.In ra gia tri lon nhat va nho nhat trong mang\n");
		printf("5.Su dung thuat toan sap xep chen sap xep tang dan cac phan tu trong mang\n");
		printf("6.Tinh tong cac phan tu la so nguyen to trong mang\n");
		printf("7.Sap xep cac phan tu le chia het cho 5 o dau mang theo thu tu giam dan, cac phan tu chan o cuoi mang chia het cho 5 o cuoi mang theo thu tu tang dan,cac phan tu con lai o giua mang theo thu tu giam dan\n");
		printf("8.Nhap gia tri m tu ban phim, chen gia tri m vao mang(sap xep tang dan) dung vi tri\n");
		printf("9.Thoat\n");
		int choice;
		printf("Moi ban chon: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap so phan tu: ");
				scanf("%d",&n);
				printf("Nhap cac gia tri cho phan tu: \n");
				for(int i=0;i<n;i++){
					printf("numbers[%d]= ",currentIndex);
					scanf("%d",&numbers[currentIndex]);
					currentIndex++;
				}
				break;
			case 2:
				printf("Cac gia tri cua phan tu co trong mang la: ");
				for(int i=0;i<currentIndex;i++){
					printf("\t%d",numbers[i]);
				}
				printf("\n");
				break;
			case 3:
				sum=0;
				for(int i=0;i<currentIndex;i++){
					if(numbers[i]%2==0&&numbers[i]%3==0){
						sum+=numbers[i];
					}
				}
				printf("Tong cac gia tri chia het cho 2 va 3 la: %d\n",sum);
				break;
			case 4:
				max=numbers[0];
				min=numbers[0];
				for(int i=0;i<currentIndex;i++){
					if(max<numbers[i]){
						max=numbers[i];
					}
					if(min>numbers[i]){
						min=numbers[i];
					}
				}
				printf("Gia tri lon nhat trong mang la: %d\n",max);
				printf("Gia tri nho nhat trong mang la: %d\n",min);
				break;
			case 5:
                for(int i=1;i<currentIndex;i++){
        			key=numbers[i];
        			k=i-1;       
        			while(k>=0&&key<numbers[i]){
            			numbers[k+1]=numbers[k];
            			k=k-1;
        			}        
        			numbers[k+1]=key;
    			}   
				break;
			case 6:
				sum=0;
				for(int i=0;i<currentIndex;i++){
					isPrime=0;
					if(numbers[i]>=2){
						for(int j=2;j<=sqrt(numbers[i]);j++){
							if(numbers[i]%j==0){
								isPrime=1;
								break;
							}
						}
					}else{
						isPrime=1;
					}
					if(isPrime==0){
						sum+=numbers[i];
					}
				}
				printf("Tong cac so nguyen to co trong mang la: %d\n",sum);
				break;
			case 7:
				for(int i=0;i<currentIndex;i++){
        			for(int j=i+1;j<currentIndex;j++){
            			if (numbers[i]%2!=0&&numbers[i]%5==0&&numbers[j]%2!=0&&numbers[j]%5==0){
                			if(numbers[i]<numbers[j]){
                    			temp = numbers[i];
                    			numbers[i] = numbers[j];
                    			numbers[j] = temp;
                			}
            			}
            			if(numbers[i]%2==0&&numbers[i]%5==0&&numbers[j]%2==0&&numbers[j]%5==0){
                			if(numbers[i]>numbers[j]){
                    			temp=numbers[i];
                    			numbers[i] = numbers[j];
                    			numbers[j] = temp;
                			}
            			}
            			if((numbers[i]%2!=0||numbers[i]%5!=0)&&(numbers[j]%2!=0||numbers[j]%5!=0)){
                			if(numbers[i]<numbers[j]){
                    			temp=numbers[i];
                    			numbers[i]=numbers[j];
                    			numbers[j]=temp;
                			}
            			}
        			}
    			}
				break;
			case 8:
				printf("Nhap gia tri m: ");
                scanf("%d",&m);
                printf("Nhap vi tri can chen gia tri m (tu 0 den %d): ",currentIndex);
                scanf("%d",&k);              
                if(k<0||k>currentIndex){
                    printf("Vi tri chen khong hop le!\n");
                }else{
                    currentIndex++;
                    for(int i=currentIndex-1;i>k;i--){
                        numbers[i]=numbers[i-1];
                    }
                    numbers[k]=m;
                }
				break;
			case 9:
				printf("Ket thuc chuong trinh\n");
				exit(0);
			default:
				printf("Khong hop le, vui long chon tu 1-9\n");
		}
	}while(1==1);
}
